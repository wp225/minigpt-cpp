#include "tokenizer.hpp"

#include<vector>
#include<set>
#include<unordered_map> 

std::set<char> get_unique(const std::string& text){
    return std::set<char>{text.begin(), text.end()};
}

std::unordered_map<char, int> map_tokens(const std::set<char>& char_set){
    int index = 0;
    std::unordered_map<char,int> mappings;
    for (const char& each_char: char_set){
        mappings[each_char]=index;
        index++;
    }

    return mappings;
}

std::vector<int> encode(const std::string& text, const std::unordered_map<char, int>& mappings){
    std::vector<int> encoded; 
    for (const char& character: text){
        encoded.push_back(mappings.at(character));
    }
    return encoded;
}

std::string decode(const std::vector<int>& encoded, const std::vector<char>& itos){
    std::string decoded;
    for (const int enc: encoded){
        decoded += itos[enc];
    }

    return decoded;
}
