#ifndef SHOWCONTENTWINDOW_H
#define SHOWCONTENTWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
namespace Ui {
class showcontentwindow;
}

class showcontentwindow : public QDialog
{
    Q_OBJECT

public:
    QString all_text;
    explicit showcontentwindow(QString& tmp,QWidget *parent = nullptr);
    ~showcontentwindow();

private slots:
    void on_pushButton_clicked();
    void on_done_clicked();

private:
    Ui::showcontentwindow *ui;
};
#endif // SHOWCONTENTWINDOW_H
