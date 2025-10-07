#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addstockdialog.h"
#include "Portfolio.h"
#include <QMessageBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    portfolio(new Portfolio())
{
    ui->setupUi(this);
    connect(ui->addStockButton, &QPushButton::clicked, this, &MainWindow::openAddStockDialog);
    connect(ui->removeStockButton, &QPushButton::clicked, this, &MainWindow::removeSelectedStock);
    connect(ui->optimizeButton, &QPushButton::clicked, this, &MainWindow::optimizePortfolio);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete portfolio;
}

void MainWindow::openAddStockDialog()
{
    AddStockDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Stock stock = dialog.getStock();
        portfolio->addStock(stock);
        updatePortfolioTable();
    }
}

void MainWindow::removeSelectedStock()
{
    int currentRow = ui->portfolioTable->currentRow();
    if (currentRow >= 0) {
        QString symbol = ui->portfolioTable->item(currentRow, 0)->text();
        portfolio->removeStock(symbol.toStdString());
        updatePortfolioTable();
    } else {
        QMessageBox::warning(this, "Remove Stock", "Please select a stock to remove.");
    }
}

void MainWindow::optimizePortfolio()
{
    // Implement optimization logic here
    // Example: std::vector<double> optimizedWeights = optimizer.optimize(portfolio->getStocks(), budget, riskTolerance);
    // Update the portfolio table with optimized results
}

void MainWindow::updatePortfolioTable()
{
    ui->portfolioTable->setRowCount(0);
    for (const Stock& stock : portfolio->getStocks()) {
        int row = ui->portfolioTable->rowCount();
        ui->portfolioTable->insertRow(row);
        ui->portfolioTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(stock.getSymbol())));
        ui->portfolioTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(stock.getName())));
        ui->portfolioTable->setItem(row, 2, new QTableWidgetItem(QString::number(stock.getPrice())));
        ui->portfolioTable->setItem(row, 3, new QTableWidgetItem(QString::number(stock.getRisk())));
        ui->portfolioTable->setItem(row, 4, new QTableWidgetItem(QString::number(stock.getExpectedReturn())));
    }
}