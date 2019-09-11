#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    //statement variables
    QCheckBox       *chkBoxUnder;   //下划线
    QCheckBox       *chkBoxBold;    //黑体
    QCheckBox       *chkBoxItalic;  //斜体
    QRadioButton    *rBtnBlack;     //黑色
    QRadioButton    *rBtnRed;       //红色
    QRadioButton    *rBtnBlue;      //蓝色
    QPlainTextEdit  *textEdit;      //纯文本编辑框
    QPushButton     *btnOk;         //ok按钮
    QPushButton     *btnCancel;     //取消按钮
    QPushButton     *btnClose;      //关闭按钮

    void initUI();                  //初始化UI
    void initSignalSlots();         //初始化信号槽

private slots:
    void on_chkBoxUnder(bool checked);  //UnderLine的clicked(bool)信号的槽函数
    void on_chkBoxItalic(bool checked); //Ttalic的clicked(bool)信号的槽函数
    void on_chkBoxBold(bool checked);   //Bold的clicked(bool)信号的槽函数
    void setTextFontColor();            //设置字体颜色

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
