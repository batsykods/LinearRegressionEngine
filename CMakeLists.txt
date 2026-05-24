cmake_minimum_required(VERSION 3.10)

project(LinearRegressionEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    LinearRegressionEngine

    src/main.cpp
    src/matrix.cpp
    src/dataset.cpp
    src/linear_regression.cpp
    src/utils.cpp
    src/model_io.cpp
    src/metrics.cpp
)