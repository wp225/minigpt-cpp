#include "input.hpp"
#include "tokenizer.hpp"
#include "dataset.hpp"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <torch/torch.h>
int main(){
    std::string text = read_file();
    if (text.empty()){
        return 1;
    }
    std::set<char> unique_chars = get_unique(text);
    std::unordered_map<char, int> mappings = map_tokens(unique_chars);
    std::vector<int> data = encode(text, mappings);
    std::vector<char> itos{unique_chars.begin(), unique_chars.end()};
    std::string decoded = decode(data, itos);

    DataSplit split = split_data(data, 0.1F);
    Batch batch = make_batch(split.train_set, 8, 4);
    TensorBatch tensorbatch = make_tensor_batch(split.train_set, 8,4);
    std::cout << "Tensor Batch size: "
            << tensorbatch.inputs.sizes() << '\n';    
    std::cout << "Batch size: "
            << batch.inputs.size() << '\n';
    std::cout << "Train tokens: "
            << split.train_set.size() << '\n';

    std::cout << "Validation tokens: "
            << split.val_set.size() << '\n';
    std::cout << "Vocabulary size: "
              << unique_chars.size() << '\n';

    std::cout << "Token count: "
              << data.size() << '\n';

    std::cout << "Round-trip matches: "
              << (decoded == text) << '\n';


    torch::Tensor tensor = torch::rand({2,3});
    std::cout << tensor << std::endl;


    return 0;
}