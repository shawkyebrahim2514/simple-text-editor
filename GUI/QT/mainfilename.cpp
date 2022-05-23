#include "mainfilename.h"
#include "ui_mainfilename.h"
#include "messagewindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
mainfilename::mainfilename(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainfilename)
{
    ui->setupUi(this);
}
mainfilename::~mainfilename()
{
    delete ui;
}
QString mainfilename::get_file(){
    return file_mod;
}
void mainfilename::on_pushButton_clicked()
{
    file_mod = ui->filearea->text();
    QFileInfo check_file(file_mod + ".txt");
    if (check_file.exists() && check_file.isFile());
    else{
        messagewindow screen("File is not exist!, I create it for you");
        screen.setModal(true);
        screen.exec();
    }
    hide();
}


