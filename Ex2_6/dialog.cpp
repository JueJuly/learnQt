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

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);

    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));


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

Dialog::~Dialog()
{

}
