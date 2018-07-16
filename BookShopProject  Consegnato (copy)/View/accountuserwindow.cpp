#include "accountuserwindow.h"
#include "ui_accountuserwindow.h"

AccountUserWindow::AccountUserWindow(const User ** userlp,UserList *ulp,LoginWindow *lwp,MainWindow *mwp,QWidget *parent) :QDialog(parent),ui(new Ui::AccountUserWindow)
{
    mw=mwp;
    lw=lwp;
    userl=userlp;
    ul=ulp;
    ui->setupUi(this);
    ui->lineEdit->setText((*userl)->getNickname());
    ui->lineEdit_2->setText((*userl)->getPassword());
    QString textpermessi="INFORMAZIONI E PERMESSI:\nQuesto account ha il diritto di lettura.\n";
    if((*userlp)->canWrite()==true){
        textpermessi=textpermessi+"Questo account ha il diritto di poter apportare modifiche.\n";
    }else{
        textpermessi=textpermessi+"Questo account NON ha il diritto di poter apportare modifiche.\n";
    }
    if((*userlp)->isAdmin()==true){
        textpermessi=textpermessi+"Questo account ha i permessi di amministratore.\n";
    }else{
        textpermessi=textpermessi+"Questo account NON ha i permessi di amministratore.\n";
    }
    ui->label_5->setText(textpermessi);
    setModal(true);
}

AccountUserWindow::~AccountUserWindow()
{
    delete ui;
}

//click del bottone Annulla
void AccountUserWindow::on_pushButton_3_clicked()
{
    this->close();

}

//click del bottone cancella
void AccountUserWindow::on_pushButton_clicked()
{
    bool deleteok=ul->deleteUser(*userl);
    if(deleteok){
        QMessageBox::information(0,"Informazione","La cancellazione dell' account è avvenuto correttamente. \nBookShopProject verrà chiuso.");
        ul->write("userfile.txt");
        *userl=0;
        this->close();
        lw->close();
        mw->close();
    }else{
        QMessageBox::warning(0,"Errore","La cancellazione dell' account NON è avvenuto correttamente");
    }

}

//clic bottone SALVA LE MODIFICHE
void AccountUserWindow::on_pushButton_2_clicked()
{
    std::string n=ui->lineEdit->text().toStdString();
    std::string p=ui->lineEdit_2->text().toStdString();
    if(n.length()==0 || p.length()==0){
        QMessageBox::warning(0,"Errore","Non possono essere presenti dei campi vuoti.");
    }else{
        bool modificheok=ul->modificaUser(*userl,n,p);
        if(modificheok)
            QMessageBox::information(0,"Informazione","La modifica dell' account è avvenuta correttamente");
        else
            QMessageBox::warning(0,"Errore","La modifica dell' account NON è avvenuta correttamente");
        ul->write("userfile.txt");
        this->close();
    }
}
