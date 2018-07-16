#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H

#include <QDialog>
#include <qmessagebox.h>

#include "Model/userlist.h"
#include "View/adminwindow.h"

class Adminwindow;

namespace Ui {
class AccountWindow;
}

class AccountWindow : public QDialog
{
    Q_OBJECT
private:
    const User * us;
    UserList * ul;
    User* makeUser()const ;
    Adminwindow * aw;
public:
    //costruttore in modalita modifica utente
    explicit AccountWindow(const User * usp,UserList * ulp,Adminwindow *awp,QWidget *parent = 0);
    //costruttore in modalità inserisci nuovo utente
    explicit AccountWindow(UserList * ulp,Adminwindow *awp,QWidget *parent = 0);
    ~AccountWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::AccountWindow *ui;
};

#endif // ACCOUNTWINDOW_H
