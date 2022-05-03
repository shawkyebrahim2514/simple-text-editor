#include "messagewindow.h"
#include "ui_messagewindow.h"
messagewindow::messagewindow(QString tmp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::messagewindow)
{
    ui->setupUi(this);
    ui->messagearea->setText(tmp);
}

messagewindow::~messagewindow()
{
    delete ui;
}

void messagewindow::on_pushButton_clicked()
{
    hide();
}

