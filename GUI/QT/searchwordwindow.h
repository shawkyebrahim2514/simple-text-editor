#ifndef SEARCHWORDWINDOW_H
#define SEARCHWORDWINDOW_H

#include <QDialog>

namespace Ui {
class searchwordwindow;
}

class searchwordwindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchwordwindow(QString& tmp,QWidget *parent = nullptr);
    ~searchwordwindow();

private slots:
    void on_done_clicked();

private:
    Ui::searchwordwindow *ui;
};
#endif // SEARCHWORDWINDOW_H
