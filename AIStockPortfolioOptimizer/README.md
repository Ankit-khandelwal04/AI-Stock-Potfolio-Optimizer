# AI Stock Portfolio Optimizer

## Project Overview
AI-Stock-Portfolio-Optimizer is a C++ application with a Qt GUI designed to help users manage and optimize their stock portfolios. The application utilizes data structures and algorithms to simulate buying and selling stocks, track performance, and recommend optimized portfolio allocations using AI-inspired techniques.

## Features
- **Stock Management**: Add, remove, or update stock information with attributes such as symbol, company name, price, risk factor, and expected return.
- **Portfolio Simulation**: Create a portfolio and simulate buying/selling stocks while tracking the portfolio's value over time.
- **Optimization Engine**: Suggest optimized allocation of funds using dynamic programming or greedy algorithms.
- **GUI Dashboard**: A user-friendly interface to display current stocks, portfolio summary, and optimization results.
- **File Persistence**: Load stock data from a text file on launch and save updates automatically on close.

## Project Structure
```
AIStockPortfolioOptimizer/
├── backend/
│   ├── Stock.h
│   ├── Stock.cpp
│   ├── Portfolio.h
│   ├── Portfolio.cpp
│   ├── Optimizer.h
│   ├── Optimizer.cpp
│   └── CMakeLists.txt
├── ui/
│   ├── main.cpp
│   ├── mainwindow.ui
│   ├── mainwindow.h
│   ├── mainwindow.cpp
│   ├── addstockdialog.ui
│   ├── addstockdialog.h
│   ├── addstockdialog.cpp
│   └── CMakeLists.txt
├── data/
│   └── stocks.txt
├── CMakeLists.txt
└── README.md
```

## Setup Instructions
1. **Install Qt & CMake**: Ensure you have Qt and CMake installed on your system.
2. **Clone the Repository**: Clone the project repository to your local machine.
3. **Build the Project**:
   - Create a build directory: `mkdir build && cd build`
   - Run CMake: `cmake ..`
   - Compile the project: `make` (or `mingw32-make` on Windows)
4. **Run the Application**: Execute the generated binary to launch the application.

## Usage
- Use the "Add Stock" button to input new stock details.
- Manage your portfolio by adding or removing stocks.
- Click "Optimize Portfolio" to receive recommendations based on your current holdings and risk tolerance.
- View the portfolio summary and track performance through the GUI.

## Data Format
The stock data file (`data/stocks.txt`) should contain stock entries in the following format:
```
symbol|name|price|risk|return
```
Example:
```
TCS|Tata Consultancy|3500|0.3|0.12
INFY|Infosys|1450|0.25|0.10
RELI|Reliance|2400|0.35|0.14
```

## Acknowledgments
This project leverages various data structures and algorithms to provide a robust stock portfolio management solution. Contributions and feedback are welcome!
