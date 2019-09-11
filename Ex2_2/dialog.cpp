#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //关联单选按钮的信号、槽
    connect(ui->rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}

/*
 * @brief 下划线复选框
 */
void Dialog::on_chkBoxUnder_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}
/*
 * @brief 黑体复选框
 */
void Dialog::on_chkBoxBold_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    font.setBold(checked);
    //font.setUnderline(checked);
    ui->textEdit->setFont(font);
}
/*
 * @brief 斜体复选框
 */
void Dialog::on_chkBoxItalic_clicked(bool checked)
{
    QFont font = ui->textEdit->font();
    //font.setUnderline(checked);
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}
/*
 * @brief 根据RadioButton设置不同的颜色
 */
void Dialog::setTextFontColor()
{
    QPalette plet = ui->textEdit->palette();
    if(ui->rBtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else if(ui->rBtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else if(ui->rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else
        plet.setColor(QPalette::Text,Qt::black);

    ui->textEdit->setPalette(plet);
}
