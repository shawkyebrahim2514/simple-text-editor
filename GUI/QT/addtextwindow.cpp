#include "addtextwindow.h"
#include "ui_addtextwindow.h"
AddTextWindow::AddTextWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTextWindow)
{
    ui->setupUi(this);
}

AddTextWindow::~AddTextWindow()
{
    delete ui;
}
QString AddTextWindow::get_new_text(){
    return new_text;
}
void AddTextWindow::on_done_clicked()
{
    new_text = ui->textarea->toPlainText();
    hide();
}

