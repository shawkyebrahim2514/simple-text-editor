#ifndef MAINFILENAME_H
#define MAINFILENAME_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class mainfilename;
}

class mainfilename : public QDialog
{
    Q_OBJECT

public:
    QString file_mod;
    explicit mainfilename(QWidget *parent = nullptr);
    ~mainfilename();
    QString get_file();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mainfilename *ui;
};

#endif // MAINFILENAME_H
