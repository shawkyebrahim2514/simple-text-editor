#include "showcontentwindow.h"
#include "ui_showcontentwindow.h"
showcontentwindow::showcontentwindow(QString& tmp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showcontentwindow)
{
    ui->setupUi(this);
    ui->showarea->setPlainText(tmp);
    //ui->showarea->setEnabled(false);
}

showcontentwindow::~showcontentwindow()
{

    delete ui;

}
void showcontentwindow::on_pushButton_clicked()
{
    hide();
}


void showcontentwindow::on_done_clicked()
{
    hide();
}

