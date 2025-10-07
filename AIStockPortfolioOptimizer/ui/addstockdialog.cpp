#include "addstockdialog.h"
#include <QDialog>
#include <QMessageBox>

AddStockDialog::AddStockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStockDialog)
{
    ui->setupUi(this);
    connect(ui->addButton, &QPushButton::clicked, this, &AddStockDialog::onAddStock);
}

AddStockDialog::~AddStockDialog()
{
    delete ui;
}

void AddStockDialog::onAddStock()
{
    QString symbol = ui->symbolLineEdit->text();
    QString name = ui->nameLineEdit->text();
    double price = ui->priceSpinBox->value();
    double risk = ui->riskSpinBox->value();
    double expectedReturn = ui->returnSpinBox->value();

    if (symbol.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    Stock newStock(symbol.toStdString(), name.toStdString(), price, risk, expectedReturn);
    emit stockAdded(newStock);
    accept();
}