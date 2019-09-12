#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtGlobal>
#include <QFloat16>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    //statement variables
    QCheckBox       *m_chkBoxUnder;   //下划线
    QCheckBox       *m_chkBoxBold;    //黑体
    QCheckBox       *m_chkBoxItalic;  //斜体
    QRadioButton    *m_rBtnBlack;     //黑色
    QRadioButton    *m_rBtnRed;       //红色
    QRadioButton    *m_rBtnBlue;      //蓝色
    QPlainTextEdit  *m_textEdit;      //纯文本编辑框
    QPushButton     *m_btnOk;         //ok按钮
    QPushButton     *m_btnCancel;     //取消按钮
    QPushButton     *m_btnClose;      //关闭按钮

    void initUI();                  //初始化UI
    void freeUI();                  //释放UI资源
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
