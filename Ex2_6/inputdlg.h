#ifndef INPUTDLG_H
#define INPUTDLG_H

#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>
#include <QInputDialog>


class InputDlg : public QDialog
{
    Q_OBJECT
public:
    InputDlg(QWidget * parent = 0);

private slots:
    void changeName();
    void changeSex();
    void changeAge();
    void changeScore();

private:
    QLabel *nameLabel1;
    QLabel *sexLabel1;
    QLabel *ageLabel1;
    QLabel *scoreLabel1;

    QLabel *nameLabel2;
    QLabel *sexLabel2;
    QLabel *ageLabel2;
    QLabel *scoreLabel2;

    QPushButton *nameBtn;
    QPushButton *sexBtn;
    QPushButton *ageBtn;
    QPushButton *scoreBtn;
    QGridLayout *mainLayout;


};

#endif // INPUTDLG_H
