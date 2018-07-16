#include "loginwindow.h"
#include "ui_loginwindow.h"


LoginWindow::LoginWindow(UserList* ul,const User **userl,MainWindow *mwp, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    mw=mwp;
    ui->setupUi(this);
    ulp=ul;
    userlp=userl;
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    std::string n=ui->lineNome->text().toStdString();
    std::string p=ui->lineEdit_2->text().toStdString();
    UserStandard uLogin(n,p);
    *userlp=ulp->search(&uLogin);
    if(*userlp==0){
        QMessageBox::critical(0,"Errore","Login non avvenuto correttamente");
        ui->lineNome->clear();
        ui->lineEdit_2->clear();
    }else{
        ui->lineNome->clear();
        ui->lineEdit_2->clear();
        mw->logpointer(this);
        mw->loadWindow();
        this->hide();
    }
}
