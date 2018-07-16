#include "accountwindow.h"
#include "ui_accountwindow.h"
//modalità modifica
AccountWindow::AccountWindow(const User * usp,UserList * ulp,Adminwindow *awp,QWidget *parent) :    QDialog(parent),    ui(new Ui::AccountWindow){
    ui->setupUi(this);
    us=usp;
    ul=ulp;
    aw=awp;
    ui->lineEdit->setText(us->getNickname());
    ui->lineEdit_2->setText(us->getPassword());
    ui->comboBox->setCurrentIndex(0);
    if(us->canWrite()){ui->comboBox->setCurrentIndex(1);}
    if(us->isAdmin()){ui->comboBox->setCurrentIndex(2);}
    ui->pushButton_2->hide();
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("([A-Za-z 1234567890,:.?!']{1,30})")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("([A-Za-z 1234567890,:.?!']{1,30})")));
    setModal(true);
}

//modalità nuovo utente
AccountWindow::AccountWindow(UserList * ulp,Adminwindow *awp,QWidget *parent) :    QDialog(parent),    ui(new Ui::AccountWindow){
    ui->setupUi(this);
    ul=ulp;
    aw=awp;
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("([A-Za-z 1234567890,:.?!']{1,30})")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("([A-Za-z 1234567890,:.?!']{1,30})")));
    setModal(true);
}

User* AccountWindow::makeUser()const{
    QString n=ui->lineEdit->text();
    QString p=ui->lineEdit_2->text();
    int tu=ui->comboBox->currentIndex();
    if(tu==0){return UserStandard(n.toStdString(),p.toStdString()).clone();}
    if(tu==1){return UserAdvanced(n.toStdString(),p.toStdString()).clone();}
    if(tu==2){return UserAdmin(n.toStdString(),p.toStdString()).clone();}
}

AccountWindow::~AccountWindow()
{
    delete ui;
}

//click botton Salva
void AccountWindow::on_pushButton_2_clicked(){
        User * usm=makeUser();
        if(usm->getNickname().length()==0 || usm->getPassword().length()==0){
            QMessageBox::warning(this,"Errore","Non possono essere presenti dei campi vuoti.");
        }else{
            if(ul->add(usm)==true){
                QMessageBox::information(this,"Informazione","La creazione del nuovo utente è avvenuta correttamente");
                aw->popTabU();
                this->close();
            }else{
                QMessageBox::warning(this,"ERRORE","Esiste già un utente con lo stesso nickname.");
            }
        }
}

//click tasto elimina
void AccountWindow::on_pushButton_4_clicked()
{
    if(ul->deleteUser(const_cast<User*>(us))){
        QMessageBox::information(this,"Informazione","La cancellazione del utente è avvenuta correttamente");
        aw->popTabU();
        this->close();
    }else{
        QMessageBox::warning(this,"ERRORE","La cancellazione non è avvenuta correttamente");
    }
}

//click modifica
void AccountWindow::on_pushButton_3_clicked()
{
    User * usm=makeUser();
    if(usm->getNickname().length()==0 || usm->getPassword().length()==0){
        QMessageBox::warning(this,"Errore","Non possono essere presenti dei campi vuoti.");
    }else{
        if(ul->deleteUser(const_cast<User*>(us))==true){//ul->add(usm)==true
                if(ul->add(usm)==true){
                    QMessageBox::information(this,"Informazione","La modifica del utente è avvenuta correttamente");
                    aw->popTabU();
                    this->close();
                }else{
                    QMessageBox::warning(this,"ERRORE","La modifica non è avvenuta correttamente./n Errore nel inserimento.");
                }
            }else{
                QMessageBox::warning(0,"ERRORE","La modifica non è avvenuta correttamente./n Errore nella cancellazione.");
                this->close();
            }
    }
}

void AccountWindow::on_pushButton_clicked()
{
    this->close();
}
