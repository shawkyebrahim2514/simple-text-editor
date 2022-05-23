#include "addfilenamewindow.h"
#include "ui_addfilenamewindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include "messagewindow.h"
QString all_content1,all_content2,main_file_name;
QTextStream file_content1,file_content2;

addfilenamewindow::addfilenamewindow(QString& tmp,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addfilenamewindow)
{
    ui->setupUi(this);
    main_file_name = tmp;
}

addfilenamewindow::~addfilenamewindow()
{
    delete ui;
}

void addfilenamewindow::on_done_clicked()
{
    QFile file(main_file_name + ".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content1.setDevice(&file);
    all_content1 = file_content1.readAll();


    QFileInfo check_file(ui->filename->text() + ".txt");
    if (check_file.exists() && check_file.isFile());
    else{
        messagewindow screen("File is not exist!, I create it for you");
        screen.setModal(true);
        screen.exec();
    }
    QFile file2(ui->filename->text() + ".txt");
    file2.open(QFile::ReadWrite | QFile::Text);
    file_content2.setDevice(&file2);
    all_content2 = file_content2.readAll();
    file_content1 <<'\n' + all_content2;
    file.flush();
    file.close();
    file2.close();



    /*QFile file(main_file_name + ".txt");
    if(!file.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::information(this,"File status","File not exist!, i create it for you");
    }
    file_content1.setDevice(&file);
    all_content1 = file_content1.readAll();


    QFile file2(ui->filename->text() + ".txt");
    if(!file2.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox::information(this,"File status","File not exist!, i create it for you");
    }
    file_content2.setDevice(&file2);
    all_content2 = file_content2.readAll();


    //QMessageBox::information(this,"File status",all_content2);
    file_content1 <<'\n' + all_content2;
    file.flush();
    file.close();
    file2.close();*/
    hide();
}

