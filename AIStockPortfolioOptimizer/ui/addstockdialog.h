#ifndef ADDSTOCKDIALOG_H
#define ADDSTOCKDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QVBoxLayout>

class AddStockDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddStockDialog(QWidget *parent = nullptr);

    QString getSymbol() const;
    QString getName() const;
    double getPrice() const;
    double getRisk() const;
    double getExpectedReturn() const;

private:
    QLineEdit *symbolLineEdit;
    QLineEdit *nameLineEdit;
    QDoubleSpinBox *priceSpinBox;
    QDoubleSpinBox *riskSpinBox;
    QDoubleSpinBox *returnSpinBox;
    QPushButton *addButton;

private slots:
    void onAddButtonClicked();
};

#endif // ADDSTOCKDIALOG_H