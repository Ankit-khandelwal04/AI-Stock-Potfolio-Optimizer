cmake_minimum_required(VERSION 3.16)
project(AIStockPortfolioOptimizer)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(backend)
add_subdirectory(ui)