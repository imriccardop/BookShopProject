#ifndef ACCOUNTUSERWINDOW_H
#define ACCOUNTUSERWINDOW_H

#include <QDialog>
#include <string>
#include "Model/user.h"
#include "Model/userlist.h"
#include "View/loginwindow.h"
#include "View/mainwindow.h"

class MainWindow;
class LoginWindow;

namespace Ui {
class AccountUserWindow;
}

class AccountUserWindow : public QDialog
{
    Q_OBJECT
private:
    const User **userl;
    UserList *ul;
    LoginWindow *lw;
    MainWindow* mw;
public:
    explicit AccountUserWindow(const User ** userlp,UserList *ulp,LoginWindow *lwp,MainWindow *mwp,QWidget *parent = 0);
    ~AccountUserWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AccountUserWindow *ui;
};

#endif // ACCOUNTUSERWINDOW_H
