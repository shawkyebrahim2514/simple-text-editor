#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QDialog>

namespace Ui {
class messagewindow;
}

class messagewindow : public QDialog
{
    Q_OBJECT

public:
    explicit messagewindow(QString tmp, QWidget *parent = nullptr);
    ~messagewindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::messagewindow *ui;
};

#endif // MESSAGE_H
