#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include "Model/userlist.h"

#include "mainwindow.h"
class MainWindow;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT
private:
    MainWindow *mw;
    UserList* ulp;
    const User **userlp;
public:
    explicit LoginWindow(UserList* ul,const User **userl,MainWindow *mwp, QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
