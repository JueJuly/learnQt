#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //整个对话框的标题
    setWindowTitle(tr("各种标准对话框的实例"));

    //初始化文件对话框中的各个控件
    fileBtn = new QPushButton(this);
    fileBtn->setText(tr("文件标准对话框"));
    fileLineEdit = new QLineEdit; //显示所选文件名

    //布局文件对话框
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);

    //初始化颜色对话框
    colorBtn = new QPushButton(this);
    colorBtn->setText(tr("颜色标准对话框"));
    colorFrame = new QFrame(this);
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    //颜色对话框布局管理
    mainLayout->addWidget(colorBtn,1,0);
    mainLayout->addWidget(colorFrame,1,1);

    inputBtn = new QPushButton(this);
    inputBtn->setText(tr("标准输入对话框"));

    mainLayout->addWidget(inputBtn,2,0);

    msgBtn = new QPushButton(this);
    msgBtn->setText(tr("标准消息对话框"));

    mainLayout->addWidget(msgBtn,3,0);


    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));
    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDlg()));
    connect(msgBtn,SIGNAL(clicked()),this,SLOT(showMsgDlg()));


}

Dialog::~Dialog()
{

}

void Dialog::showFile()
{
    QString str = QFileDialog::getOpenFileName(this,
                                               "open file dialog",
                                               "/",
                                               "C++ file(*.cpp);;C files(*.c);;Head files(*.h)");
    //同一类型文件过滤
    // tr("files (*.cpp *.c *.cc *.h *.hpp)");
    //不同类型文件过滤
    // "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"


    fileLineEdit->setText(str);
}

void Dialog::showColor()
{
    QColor clr = QColorDialog::getColor(Qt::blue);
    if(clr.isValid())
    {
        colorFrame->setPalette(QPalette(clr));
    }
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg(this);
    msgDlg->show();
}
