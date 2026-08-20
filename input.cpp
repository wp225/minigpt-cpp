#include "input.hpp"

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>  //for stf::ifstream
#include<set>
#include<unordered_map>

std::string read_file(){
    std::ifstream input_file("input.txt");

    if (!input_file){
        std::cerr << "Filed opening file";
        return "";
    }

    std::stringstream buffer;
    buffer << input_file.rdbuf();
    return buffer.str();
}