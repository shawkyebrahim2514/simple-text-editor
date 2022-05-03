#ifndef ADDTEXTWINDOW_H
#define ADDTEXTWINDOW_H

#include <QDialog>

namespace Ui {
class AddTextWindow;
}

class AddTextWindow : public QDialog
{
    Q_OBJECT

public:
    QString new_text;
    explicit AddTextWindow(QWidget *parent = nullptr);
    ~AddTextWindow();
    QString get_new_text();

private slots:
    void on_done_clicked();

private:
    Ui::AddTextWindow *ui;
};

#endif // ADDTEXTWINDOW_H
