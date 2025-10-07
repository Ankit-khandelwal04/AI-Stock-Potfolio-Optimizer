set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(AIStockPortfolioOptimizer
    main.cpp
    mainwindow.cpp
    addstockdialog.cpp
)

target_link_libraries(AIStockPortfolioOptimizer
    Qt5::Widgets
    backend
)