#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_btnCalc_clicked();

    void on_btnDec_clicked();

    void on_btnBin_clicked();

    void on_btnHex_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
