#ifndef SAVENEWFILENAME_H
#define SAVENEWFILENAME_H

#include <QDialog>

namespace Ui {
class savenewfilename;
}

class savenewfilename : public QDialog
{
    Q_OBJECT

public:
    explicit savenewfilename(QString& tmp,QWidget *parent = nullptr);
    ~savenewfilename();

private slots:
    void on_done_clicked();

private:
    Ui::savenewfilename *ui;
};

#endif // SAVENEWFILENAME_H
