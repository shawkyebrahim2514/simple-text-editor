#include "savenewfilename.h"
#include "ui_savenewfilename.h"
#include "messagewindow.h"
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QTextStream>
QString name;
savenewfilename::savenewfilename(QString& tmp,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::savenewfilename)
{
    name = tmp;
    ui->setupUi(this);
}

savenewfilename::~savenewfilename()
{
    delete ui;
}

void savenewfilename::on_done_clicked()
{
    QTextStream main_file_content, new_file_content;
    QString main_file_text, new_file_text;
    QFile main_file(name +".txt");
    main_file.open(QFile::ReadWrite | QFile::Text);
    main_file_content.setDevice(&main_file);
    main_file_text = main_file_content.readAll();


    QFileInfo check_file(ui->filearea->text() + ".txt");
    if (check_file.exists() && check_file.isFile());
    else{
        messagewindow screen("File is not exist!, I create it for you");
        screen.setModal(true);
        screen.exec();
    }
    QFile new_file(ui->filearea->text() + ".txt");
    new_file.open(QFile::ReadWrite | QFile::Truncate);
    new_file_content.setDevice(&new_file);
    new_file_text = new_file_content.readAll();
    new_file_content << main_file_text;
    main_file.close();
    new_file.close();
    hide();
}

