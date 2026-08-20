#pragma once

#include<set>
#include <string>
#include <unordered_map>
#include <vector>
std::set<char> get_unique(const std::string& text);
std::unordered_map<char, int> map_tokens(const std::set<char>& unique_chars);
std::vector<int> encode(const std::string& text, const std::unordered_map<char, int>& mappings);
std::string decode(const std::vector<int>& encoded, const std::vector<char>& itos);

