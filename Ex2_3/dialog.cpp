#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    initUI();
    initSignalSlots();
    setWindowTitle("Form Created mannually");
}

Dialog::~Dialog()
{
    freeUI();
}

void Dialog::initUI()
{
    //创建UnderLine,Italic,Bold 3个CheckBox,水平布局
    chkBoxUnder         = new QCheckBox(tr("UnderLine"));
    chkBoxItalic        = new QCheckBox(tr("Italic"));
    chkBoxBold          = new QCheckBox(tr("Bold"));
    QHBoxLayout *hLay1  = new QHBoxLayout;
    hLay1->addWidget(chkBoxUnder);
    hLay1->addWidget(chkBoxItalic);
    hLay1->addWidget(chkBoxBold);

    //创建Black,Red,Blue 3个RadioButton,水平布局
    rBtnBlack           = new QRadioButton(tr("Black"));
    rBtnBlue            = new QRadioButton(tr("Blue"));
    rBtnRed             = new QRadioButton(tr("Red"));
    rBtnBlack->setChecked(true);
    QHBoxLayout *hLay2  = new QHBoxLayout;
    hLay2->addWidget(rBtnBlack);
    hLay2->addWidget(rBtnBlue);
    hLay2->addWidget(rBtnRed);

    //创建确定, 取消, 退出3 个 PushButton, 并水平布局
    btnOk               = new QPushButton(tr("确定"));
    btnCancel           = new QPushButton(tr("取消"));
    btnClose            = new QPushButton(tr("退出"));
    QHBoxLayout *hLay3  = new QHBoxLayout;
    hLay3->addStretch();
    hLay3->addWidget(btnOk);
    hLay3->addWidget(btnCancel);
    hLay3->addStretch();
    hLay3->addWidget(btnClose);

    //创建文本框,并设置初始字体
    textEdit            = new QPlainTextEdit;
    textEdit->setPlainText("Hello World! This is my first Demo!");
    QFont font = textEdit->font();  //获取字体
    font.setPointSize(20);          //修改字体大小
    textEdit->setFont(font);        //设置字体

    //创建垂直布局,并设置为主布局
    QVBoxLayout *vLay   = new QVBoxLayout;
    vLay->addLayout(hLay1);     //添加字体类型组
    vLay->addLayout(hLay2);     //添加字体颜色组
    vLay->addWidget(textEdit);  //添加PlainTextEdit
    vLay->addLayout(hLay3);     //添加按键组
    setLayout(vLay);            //设置为主窗体布局
}

void Dialog::freeUI()
{
    delete chkBoxUnder;
    delete chkBoxItalic;
    delete chkBoxBold;
    delete rBtnBlack;
    delete rBtnBlue;
    delete rBtnRed;
    delete textEdit;
    delete btnCancel;
    delete btnOk;
    delete btnClose;

}

void Dialog::initSignalSlots()
{
    //三个颜色 QRadioButton 的clicked()信号与setTextFontColor()槽函数关联
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));

    //三个字体设置的 QCheckBox 的clicked(bool)信号与相应的槽函数关联
    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxBold,SIGNAL(clicked(bool)), this,SLOT(on_chkBoxBold(bool)));

    //三个按钮的信号与窗体的槽函数关联
    connect(btnOk,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
}

void Dialog::on_chkBoxUnder(bool checked)
{
    QFont font = textEdit->font();
    font.setUnderline(checked);
    textEdit->setFont(font);
}

void Dialog::on_chkBoxItalic(bool checked)
{
    QFont font = textEdit->font();
    font.setItalic(checked);
    textEdit->setFont(font);
}

void Dialog::on_chkBoxBold(bool checked)
{
    QFont font = textEdit->font();
    font.setBold(checked);
    textEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet = textEdit->palette();
    if(rBtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else if(rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(rBtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else
        plet.setColor(QPalette::Text,Qt::black);
    textEdit->setPalette(plet);
}
