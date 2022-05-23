#ifndef ADDFILENAMEWINDOW_H
#define ADDFILENAMEWINDOW_H

#include <QDialog>

namespace Ui {
class addfilenamewindow;
}

class addfilenamewindow : public QDialog
{
    Q_OBJECT

public:
    explicit addfilenamewindow(QString& tmp,QWidget *parent = nullptr);
    ~addfilenamewindow();

private slots:
    void on_done_clicked();

private:
    Ui::addfilenamewindow *ui;
};

#endif // ADDFILENAMEWINDOW_H
