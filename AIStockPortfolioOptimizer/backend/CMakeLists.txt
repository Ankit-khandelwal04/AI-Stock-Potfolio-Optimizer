add_library(backend
    Stock.cpp
    Portfolio.cpp
    Optimizer.cpp
)
target_include_directories(backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})