#include "searchwordwindow.h"
#include "ui_searchwordwindow.h"
#include <QSet>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
QSet<QString>set;
searchwordwindow::searchwordwindow(QString& tmp,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchwordwindow)
{
    ui->setupUi(this);
    set.clear();
    QTextStream file_content;
    QFile file(tmp +".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString  file_word;
    while(!file_content.atEnd()) {

        QString line = file_content.readLine();
        QStringList words = line.split(" ");
        foreach(QString word, words){
            word = word.toLower();
           set.insert(word);
        }

    }
    file.close();
}

searchwordwindow::~searchwordwindow()
{
    delete ui;
}

void searchwordwindow::on_done_clicked()
{
    QString target = ui->wordarea->text();
    target = target.toLower();
    if(set.find(target) == set.end()){
        ui->wordexist->setText("Word was not found");
    }else{
        ui->wordexist->setText("Word was found");
    }
    //hide();
}

