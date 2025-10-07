#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include "../backend/Portfolio.h"
#include "../ui_addstockdialog.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openAddStockDialog();
    void removeSelectedStock();
    void optimizePortfolio();
    void updatePortfolioTable();

private:
    Ui::MainWindow *ui;
    Portfolio *portfolio;
};

#endif // MAINWINDOW_H