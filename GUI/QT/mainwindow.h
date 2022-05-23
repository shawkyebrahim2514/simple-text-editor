#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mergefiles_clicked();

    void on_addtext_clicked();

    void on_searchfile_clicked();

    void on_savefile_clicked();

    void on_exit_clicked();

    void on_emptyfile_clicked();

    void on_encryptfile_clicked();

    void on_decryptfile_clicked();

    void on_tolowerfile_clicked();

    void on_toupperfile_clicked();

    void on_tocapsfile_clicked();

    void on_showfile_clicked();

    void on_wordtimes_clicked();

    void on_numberoflines_clicked();

    void on_numberofwords_clicked();

    void on_numberofchars_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
