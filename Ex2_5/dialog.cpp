#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_btnCalc_clicked()
{
    int num = ui->spinBoxNum->value();
    float price = ui->dSpinBoxPrice->value();
    float total = num * price;
    ui->dSpinBoxTotal->setValue(total);
}

void Dialog::on_btnDec_clicked()
{
    int val = ui->spinBoxDec->value();
    ui->spinBoxBin->setValue(val);
    ui->spinBoxHex->setValue(val);
}

void Dialog::on_btnBin_clicked()
{
    int val = ui->spinBoxBin->value();
    ui->spinBoxDec->setValue(val);
    ui->spinBoxHex->setValue(val);
}

void Dialog::on_btnHex_clicked()
{
    int val = ui->spinBoxHex->value();
    ui->spinBoxBin->setValue(val);
    ui->spinBoxDec->setValue(val);
}
