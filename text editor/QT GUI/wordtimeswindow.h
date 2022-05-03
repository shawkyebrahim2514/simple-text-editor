#ifndef WORDTIMESWINDOW_H
#define WORDTIMESWINDOW_H

#include <QDialog>

namespace Ui {
class wordtimeswindow;
}

class wordtimeswindow : public QDialog
{
    Q_OBJECT

public:
    explicit wordtimeswindow(QString& tmp,QWidget *parent = nullptr);
    ~wordtimeswindow();

private slots:
    void on_done_clicked();

private:
    Ui::wordtimeswindow *ui;
};

#endif // WORDTIMESWINDOW_H
