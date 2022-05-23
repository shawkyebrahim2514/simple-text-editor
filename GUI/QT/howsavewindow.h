#ifndef HOWSAVEWINDOW_H
#define HOWSAVEWINDOW_H

#include <QDialog>

namespace Ui {
class howsavewindow;
}

class howsavewindow : public QDialog
{
    Q_OBJECT

public:
    explicit howsavewindow(QString& tmp,QWidget *parent = nullptr);
    ~howsavewindow();

private slots:
    void on_samefile_clicked();

    void on_diferfile_clicked();

private:
    Ui::howsavewindow *ui;
};

#endif // HOWSAVEWINDOW_H
