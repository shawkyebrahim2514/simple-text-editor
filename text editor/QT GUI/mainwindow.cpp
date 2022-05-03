#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addfilenamewindow.h"
#include "addtextwindow.h"
#include "howsavewindow.h"
#include "searchwordwindow.h"
#include "showcontentwindow.h"
#include "mainfilename.h"
#include "wordtimeswindow.h"
#include "messagewindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
QString file_name = "text";
QTextStream file_content;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainfilename screen;
    screen.setModal(true);
    screen.exec();
    file_name = screen.get_file();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_mergefiles_clicked()
{
    addfilenamewindow screen(file_name);
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_addtext_clicked()
{
    AddTextWindow screen;
    screen.setModal(true);
    screen.exec();
    QFile file(file_name+".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString tmp = screen.get_new_text();
    if(file_content.readAll().size()) file_content << '\n';
    file_content << tmp;
    file.flush();
    file.close();
}


void MainWindow::on_searchfile_clicked()
{
    searchwordwindow screen(file_name);
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_savefile_clicked()
{
    howsavewindow screen(file_name);
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_exit_clicked()
{
    hide();
}


void MainWindow::on_emptyfile_clicked()
{
    QFile file(file_name + ".txt");
    file.open(QFile::WriteOnly|QFile::Truncate);
    file.close();
    messagewindow screen("File now is empty");
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_encryptfile_clicked()
{
    QFile file(file_name+".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString tmp = file_content.readAll();
    for(int i = 0; i < tmp.size(); i++){
        tmp[i] = QChar(tmp[i].unicode() + 1);
    }
    file.close();
    file.open(QFile::WriteOnly|QFile::Truncate);
    file_content << tmp;
    file.close();
    messagewindow screen("File now is Encrypted");
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_decryptfile_clicked()
{
    QFile file(file_name+".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString tmp = file_content.readAll();
    for(int i = 0; i < tmp.size(); i++){
        tmp[i] = QChar(tmp[i].unicode() - 1);
    }
    file.close();
    file.open(QFile::WriteOnly|QFile::Truncate);
    file_content << tmp;
    file.close();
    messagewindow screen("File now is decrypted");
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_tolowerfile_clicked()
{
    QFile file(file_name+".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString tmp = file_content.readAll();
    tmp = tmp.toLower();
    file.close();
    file.open(QFile::WriteOnly|QFile::Truncate);
    file_content << tmp;
    file.close();
    messagewindow screen("All characters have been converted to lowercase");
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_toupperfile_clicked()
{
    QFile file(file_name+".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString tmp = file_content.readAll();
    tmp = tmp.toUpper();
    file.close();
    file.open(QFile::WriteOnly|QFile::Truncate);
    file_content << tmp;
    file.close();
    messagewindow screen("All characters have been converted to uppercase");
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_tocapsfile_clicked()
{
    QFile file(file_name+".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString tmp = file_content.readAll();
    tmp = tmp.toLower();
    for(int i = 0; i < tmp.size(); i++){
        if(!i || tmp[i-1] == ' ' || tmp[i-1] == '\n'){
            tmp[i] = (tmp[i].toUpper());
        }
    }
    file.close();
    file.open(QFile::WriteOnly|QFile::Truncate);
    file_content << tmp;
    file.close();
    messagewindow screen("All words have been converted to caps");
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_showfile_clicked()
{
    QFile file(file_name+".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    QString all_text = file_content.readAll();
    file.flush();
    file.close();
    showcontentwindow screen(all_text);
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_wordtimes_clicked()
{
    wordtimeswindow screen(file_name);
    screen.setModal(true);
    screen.exec();
}


void MainWindow::on_numberoflines_clicked()
{
    QFile file(file_name +".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    int cnt = 0;
    while(!file_content.atEnd()) {

        QString line = file_content.readLine();
        cnt ++;

    }
    messagewindow screen("Number of lines: " + QString::number(cnt));
    screen.setModal(true);
    screen.exec();
    file.close();
}


void MainWindow::on_numberofwords_clicked()
{
    QFile file(file_name +".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    int cnt = 0;
    while(!file_content.atEnd()) {

        QString line = file_content.readLine();
        QStringList words = line.split(" ");
        foreach(QString word, words){
            cnt ++;
        }

    }
    messagewindow screen("Number of words: " + QString::number(cnt));
    screen.setModal(true);
    screen.exec();
    file.close();
}


void MainWindow::on_numberofchars_clicked()
{
    QFile file(file_name +".txt");
    file.open(QFile::ReadWrite | QFile::Text);
    file_content.setDevice(&file);
    int cnt_all_chars = 0,cnt_lines = 0;
    while(!file_content.atEnd()) {

        QString line = file_content.readLine();
        cnt_lines ++;
        cnt_all_chars += line.size();
    }
    messagewindow screen("Number of characters: " + QString::number(cnt_all_chars - cnt_lines + 1));
    screen.setModal(true);
    screen.exec();
    file.close();
}

