#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFileDialog>
#include <QColorDialog>
#include <QFrame>
#include <QPalette>

#include "inputdlg.h"
#include "msgboxdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    //文件对话框变量
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;

    //颜色对话框
    QPushButton *colorBtn;
    QFrame *colorFrame;

    //输入对话框
    QPushButton *inputBtn;
    InputDlg *inputDlg;

    //消息对话框
    QPushButton *msgBtn;
    MsgBoxDlg *msgDlg;

private slots:
    void showFile();
    void showColor();
    void showInputDlg();
    void showMsgDlg();

};

#endif // DIALOG_H
