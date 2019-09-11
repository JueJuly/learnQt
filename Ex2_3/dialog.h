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

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
