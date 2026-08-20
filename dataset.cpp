// dataset.cpp
#include "dataset.hpp"

DataSplit split_data(
    const std::vector<int>& data,
    float testing_split
) {
    const std::size_t split_index = static_cast<std::size_t>(
        data.size() * testing_split
    );

    std::vector<int> train_data(
        data.begin(),
        data.end() - split_index
    );

    std::vector<int> validation_data(
        data.end() - split_index,
        data.end()
    );

    return {train_data, validation_data};
}

Batch make_batch(const std::vector<int>& training_data, int batch_size, int block_size){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, training_data.size() - block_size - 1);


    std::vector<std::vector<int>> inputs;
    std::vector<std::vector<int>> targets;

    for (int batch_no=0; batch_no < batch_size; batch_no++){
        int random_num = distrib(gen);
        std::vector<int> input(
            training_data.begin()+random_num, 
            training_data.begin()+random_num+block_size
    );
        std::vector<int> target(
            training_data.begin()+random_num+1,
            training_data.begin()+random_num+block_size+1
    );
        inputs.push_back(input);
        targets.push_back(target);
    }
    return {inputs, targets};
}



TensorBatch make_tensor_batch(const std::vector<int>& training_data, int batch_size, int block_size){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, training_data.size() - block_size - 1);

    std::vector<int> flat_inputs;
    std::vector<int> flat_targets;

    for (int batch_no=0; batch_no < batch_size; batch_no++){
        int random_num = distrib(gen);
        std::vector<int> input(
            training_data.begin()+random_num, 
            training_data.begin()+random_num+block_size
    );
        std::vector<int> target(
            training_data.begin()+random_num+1,
            training_data.begin()+random_num+block_size+1
    );
    flat_inputs.insert(flat_inputs.end(), input.begin(), input.end());
    flat_targets.insert(flat_targets.end(), target.begin(), target.end());
    }

    const auto options = torch::TensorOptions().dtype(torch::kInt64);

    torch::Tensor inputs =
        torch::tensor(flat_inputs, options)
            .reshape({batch_size, block_size});

    torch::Tensor targets =
        torch::tensor(flat_targets, options)
            .reshape({batch_size, block_size});
    
    return {inputs, targets};
}