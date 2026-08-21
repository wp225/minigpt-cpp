#pragma once
#include <cstdint>
#include <torch/torch.h>

struct TokenEmbeddingImpl: torch::nn::Module{
    torch::nn::Embedding table{nullptr};

    TokenEmbeddingImpl(int64_t vocab_size, int64_t n_emb);
    torch::Tensor forward(torch::Tensor token_ids);
};

TORCH_MODULE(TokenEmbedding);

struct HeadImpl: torch::nn::Module{
    torch::nn::Linear key{nullptr};
    torch::nn::Linear query{nullptr};
    torch::nn::Linear value{nullptr};

    HeadImpl(int64_t n_emb, int64_t head_size);
    torch::Tensor forward(torch::Tensor x);

}


TORCH_MODULE(HEAD)