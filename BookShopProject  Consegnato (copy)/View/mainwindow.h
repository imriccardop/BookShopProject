#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMessageBox>

#include "Model/user.h"
#include "Model/booklist.h"
#include "Model/userlist.h"

#include "View/loginwindow.h"
#include "View/accountuserwindow.h"
#include "View/bookwindow.h"
#include "View/adminwindow.h"

class LoginWindow;
class AccountUserWindow;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    const User** userl;//puntatore all' utente loggato
    BookList* bl;//puntatore alla lista dei libri
    BookList bls;
    UserList* ul;
    LoginWindow *lw;

public:
    explicit MainWindow(const User** userlp,BookList* blp,UserList *ulp,QWidget *parent = 0);
    ~MainWindow();
    void loadWindow();
    void popTabB(BookList *blp);//popola tabella Book
    void UpdateTabB();
    void logpointer(LoginWindow *lwp);
    void addBookTable(int row, Book bp);
private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
