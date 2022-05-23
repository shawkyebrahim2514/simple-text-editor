#include "howsavewindow.h"
#include "ui_howsavewindow.h"
#include "savenewfilename.h"
QString main_file;
howsavewindow::howsavewindow(QString& tmp,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::howsavewindow)
{
    main_file = tmp;
    ui->setupUi(this);
}

howsavewindow::~howsavewindow()
{
    delete ui;
}

void howsavewindow::on_samefile_clicked()
{
    hide();
}


void howsavewindow::on_diferfile_clicked()
{
    savenewfilename screen(main_file);
    screen.setModal(true);
    screen.exec();
    hide();
}
