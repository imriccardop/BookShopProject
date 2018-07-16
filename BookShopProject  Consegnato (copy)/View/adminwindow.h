#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <list>
#include <QMessageBox>

#include "Model/userlist.h"
#include "View/accountwindow.h"

class AccountWindow;

namespace Ui {
class Adminwindow;
}

class Adminwindow : public QDialog
{
    Q_OBJECT
private:
    const User** userl;
    UserList *ul;
public:
    explicit Adminwindow(const User** userlp,UserList *ulp,QWidget *parent = 0);
    ~Adminwindow();
    void popTabU();
private slots:
    void on_pushButton_2_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Adminwindow *ui;
    void addUserTable(int row, User* up);
};

#endif // ADMINWINDOW_H
