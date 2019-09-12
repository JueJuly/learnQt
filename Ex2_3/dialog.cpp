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
    m_chkBoxUnder         = new QCheckBox(tr("UnderLine"));
    m_chkBoxItalic        = new QCheckBox(tr("Italic"));
    m_chkBoxBold          = new QCheckBox(tr("Bold"));
    QHBoxLayout *hLay1  = new QHBoxLayout;
    hLay1->addWidget(m_chkBoxUnder);
    hLay1->addWidget(m_chkBoxItalic);
    hLay1->addWidget(m_chkBoxBold);

    //创建Black,Red,Blue 3个RadioButton,水平布局
    m_rBtnBlack           = new QRadioButton(tr("Black"));
    m_rBtnBlue            = new QRadioButton(tr("Blue"));
    m_rBtnRed             = new QRadioButton(tr("Red"));
    m_rBtnBlack->setChecked(true);
    QHBoxLayout *hLay2  = new QHBoxLayout;
    hLay2->addWidget(m_rBtnBlack);
    hLay2->addWidget(m_rBtnBlue);
    hLay2->addWidget(m_rBtnRed);

    //创建确定, 取消, 退出3 个 PushButton, 并水平布局
    m_btnOk               = new QPushButton(tr("确定"));
    m_btnCancel           = new QPushButton(tr("取消"));
    m_btnClose            = new QPushButton(tr("退出"));
    QHBoxLayout *hLay3  = new QHBoxLayout;
    hLay3->addStretch();
    hLay3->addWidget(m_btnOk);
    hLay3->addWidget(m_btnCancel);
    hLay3->addStretch();
    hLay3->addWidget(m_btnClose);

    //创建文本框,并设置初始字体
    m_textEdit            = new QPlainTextEdit;
    m_textEdit->setPlainText("Hello World! This is my first Demo!");
    QFont font = m_textEdit->font();  //获取字体
    font.setPointSize(20);          //修改字体大小
    m_textEdit->setFont(font);        //设置字体

    //创建垂直布局,并设置为主布局
    QVBoxLayout *vLay   = new QVBoxLayout;
    vLay->addLayout(hLay1);     //添加字体类型组
    vLay->addLayout(hLay2);     //添加字体颜色组
    vLay->addWidget(m_textEdit);  //添加PlainTextEdit
    vLay->addLayout(hLay3);     //添加按键组
    setLayout(vLay);            //设置为主窗体布局
}

void Dialog::freeUI()
{
    delete m_chkBoxUnder;
    delete m_chkBoxItalic;
    delete m_chkBoxBold;
    delete m_rBtnBlack;
    delete m_rBtnBlue;
    delete m_rBtnRed;
    delete m_textEdit;
    delete m_btnCancel;
    delete m_btnOk;
    delete m_btnClose;

}

void Dialog::initSignalSlots()
{
    //三个颜色 QRadioButton 的clicked()信号与setTextFontColor()槽函数关联
    connect(m_rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(m_rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(m_rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));

    //三个字体设置的 QCheckBox 的clicked(bool)信号与相应的槽函数关联
    connect(m_chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxUnder(bool)));
    connect(m_chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxItalic(bool)));
    connect(m_chkBoxBold,SIGNAL(clicked(bool)), this,SLOT(on_chkBoxBold(bool)));

    //三个按钮的信号与窗体的槽函数关联
    connect(m_btnOk,SIGNAL(clicked()),this,SLOT(accept()));
    connect(m_btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(m_btnClose,SIGNAL(clicked()),this,SLOT(close()));
}

void Dialog::on_chkBoxUnder(bool checked)
{
    QFont font = m_textEdit->font();
    font.setUnderline(checked);
    m_textEdit->setFont(font);
}

void Dialog::on_chkBoxItalic(bool checked)
{
    QFont font = m_textEdit->font();
    font.setItalic(checked);
    m_textEdit->setFont(font);
}

void Dialog::on_chkBoxBold(bool checked)
{
    QFont font = m_textEdit->font();
    font.setBold(checked);
    m_textEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet = m_textEdit->palette();
    if(m_rBtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else if(m_rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(m_rBtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else
        plet.setColor(QPalette::Text,Qt::black);
    m_textEdit->setPalette(plet);
}
