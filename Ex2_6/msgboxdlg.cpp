#include "msgboxdlg.h"

MsgBoxDlg::MsgBoxDlg(QWidget *parent)
    :QDialog(parent)
{

    setWindowTitle(tr("标准消息对话框"));

    label = new QLabel(this);
    label->setText(tr("请选择一种消息框"));

    questionBtn = new QPushButton(this);
    questionBtn->setText(tr("问题消息框"));

    informationBtn = new QPushButton(this);
    informationBtn->setText(tr("信息消息框"));

    warningBtn = new QPushButton(this);
    warningBtn->setText(tr("警告消息框"));

    criticalBtn = new QPushButton(this);
    criticalBtn->setText(tr("断言消息框"));

    aboutBtn = new QPushButton(this);
    aboutBtn->setText(tr("关于消息框"));

    aboutQtBtn = new QPushButton(this);
    aboutQtBtn->setText(tr("关于Qt"));

    mainLayout = new QGridLayout(this);

    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);

    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);

    connect(questionBtn,SIGNAL(clicked()),this,SLOT(showQuestionMsg()));
    connect(informationBtn,SIGNAL(clicked()),this,SLOT(showInfomationMsg()));
    connect(warningBtn,SIGNAL(clicked()),this,SLOT(showWarningMsg()));
    connect(criticalBtn,SIGNAL(clicked()),this,SLOT(showCriticalMsg()));
    connect(aboutBtn,SIGNAL(clicked()),this,SLOT(showAboutMsg()));
    connect(aboutQtBtn,SIGNAL(clicked()),this,SLOT(showAboutQtMsg()));




}

void MsgBoxDlg::showQuestionMsg()
{

}

void MsgBoxDlg::showInfomationMsg()
{

}

void MsgBoxDlg::showWarningMsg()
{

}

void MsgBoxDlg::showCriticalMsg()
{

}

void MsgBoxDlg::showAboutMsg()
{

}

void MsgBoxDlg::showAboutQtMsg()
{

}
