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
    QString str = ui->lineEditNum->text();
    int num = str.toInt();
    str = ui->lineEditPrice->text();
    float price = str.toFloat();
    float total = num * price;
    str = str.sprintf("%0.2f",total);
    ui->lineEditTotal->setText(str);
}

void Dialog::on_btnDec_clicked()
{
    QString str = ui->lineEditDec->text();
    int val = str.toInt();
    str = str.setNum(val,16);
    str = str.toUpper();
    ui->lineEditHex->setText(str);
    str = str.setNum(val,2);
    ui->lineEditBin->setText(str);
}

void Dialog::on_btnBin_clicked()
{
    QString str = ui->lineEditBin->text();
    bool ok;
    int val = str.toInt(&ok,2);
    str = QString::number(val,10);
    ui->lineEditDec->setText(str);
    str = str.setNum(val,16);
    str = str.toUpper();
    ui->lineEditHex->setText(str);
}

void Dialog::on_btnHex_clicked()
{
    QString str = ui->lineEditHex->text();
    bool ok;
    int val = str.toInt(&ok,16);
    str = QString::number(val,10);
    ui->lineEditDec->setText(str);
    str = str.setNum(val,2);
    //str = str.toUpper();
    ui->lineEditBin->setText(str);
}
