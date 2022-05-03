#include "wordtimeswindow.h"
#include "ui_wordtimeswindow.h"
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
QMap<QString,int>map;
wordtimeswindow::wordtimeswindow(QString& tmp,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wordtimeswindow)
{
    ui->setupUi(this);
    map.clear();
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
           map[word] ++;
        }

    }
}

wordtimeswindow::~wordtimeswindow()
{
    delete ui;
}

void wordtimeswindow::on_done_clicked()
{
    int num_times = map[ui->wordarea->text()];
    ui->wordtimes->setText("The word \"" + ui->wordarea->text() + "\" times: " + QString::number(num_times));
}



