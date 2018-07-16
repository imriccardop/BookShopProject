#include "adminwindow.h"
#include "ui_adminwindow.h"

Adminwindow::Adminwindow(const User** userlp,UserList *ulp,QWidget *parent) :QDialog(parent),ui(new Ui::Adminwindow){
    ui->setupUi(this);
    userl=userlp;
    ul=ulp;
    popTabU();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setModal(true);
}

Adminwindow::~Adminwindow()
{
    delete ui;
}

void Adminwindow::popTabU(){
    std::list<User*> lc=ul->CopiaList(*userl);
    int row=0;
    for(std::list<User*>::const_iterator i=lc.begin();i!=lc.end();i++){
            ui->tableWidget->setRowCount(row+1);
            addUserTable(row,*i);
            row++;
    }
}

void Adminwindow::addUserTable(int row, User* up){
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(up->getNickname()));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(up->getPassword()));
    QString p="lettura";
    if(up->canWrite()){p="scrittura";}
    if(up->isAdmin()){p="admin";}
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(p));
}


//click tasto esci
void Adminwindow::on_pushButton_2_clicked()
{
    this->close();
}

void Adminwindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString nickname=ui->tableWidget->item(row,0)->text();
    QString password=ui->tableWidget->item(row,1)->text();
    const User* us=new UserStandard(nickname.toStdString(),password.toStdString());
    us=ul->search(const_cast<User*>(us));
    if(us==0){
        QMessageBox::warning(0,"ERRORE","la visualizzazione del utente ha generato un errore");
    }else{
        AccountWindow *aw=new AccountWindow(us,ul,this);
        aw->show();
    }
}

//click salva le modifiche
void Adminwindow::on_pushButton_clicked()
{
    ul->write("userfile.txt");
    QMessageBox::information(0,"INFORMAZIONE","Le modifiche sono state salvate correttamente");
}

//crea nuovo utente
void Adminwindow::on_pushButton_3_clicked()
{
    AccountWindow *aw=new AccountWindow(ul,this);
    aw->show();
}
