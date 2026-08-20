cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(minigpt_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Torch REQUIRED)

add_executable(minigpt_cpp
    main.cpp
    input.cpp
    tokenizer.cpp
    dataset.cpp
    model.cpp
)

target_link_libraries(minigpt_cpp PRIVATE "${TORCH_LIBRARIES}")

set_property(TARGET minigpt_cpp PROPERTY CXX_STANDARD 20)