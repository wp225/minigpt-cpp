// dataset.hpp
#pragma once
#include<vector>
#include<random>
#include<algorithm>
#include<torch/torch.h>
struct DataSplit{
    std::vector<int> train_set;
    std::vector<int> val_set;
};

struct TensorBatch{
    torch::Tensor inputs;
    torch::Tensor targets;
};

struct Batch{
    std::vector<std::vector<int>> inputs;
    std::vector<std::vector<int>> targets;
};

Batch make_batch(const std::vector<int>& training_data, int batch_size, int block_size);
TensorBatch make_tensor_batch(const std::vector<int>& training_data, int batch_size, int block_size);

DataSplit split_data(const std::vector<int>& data, float testing_split);
