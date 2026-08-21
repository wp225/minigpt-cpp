#include "model.hpp"

TokenEmbeddingImpl::TokenEmbeddingImpl(int64_t num_embeddings, int64_t n_emb){
    table = register_module(
        "table",
        torch::nn::Embedding(num_embeddings, n_emb)
    );
}

torch::Tensor TokenEmbeddingImpl::forward(torch::Tensor token_ids){
    return table(token_ids);
}

HeadImpl::HeadImpl(int64_t n_emb, int64_t head_size){
    key = register_module(
        "key",
        torch::nn::Linear(
            torch::nn::LinearOptions(n_emb, head_size).bias(false)
        )
    );

    query = register_module(
    "query",
    torch::nn::Linear(
        torch::nn::LinearOptions(n_emb, head_size).bias(false)
    )
);
    value = register_module(
    "value",
    torch::nn::Linear(
        torch::nn::LinearOptions(n_emb, head_size).bias(false)
    )
);
}