#include<tensor/tensor.h>
struct TokenEmbeddingImpl : torch::nn::Module {
    torch::nn::Embedding table{nullptr};

    TokenEmbeddingImpl(int64_t vocab_size, int64_t n_embd);
    torch::Tensor forward(torch::Tensor token_ids);
};

TORCH_MODULE(TokenEmbedding);
