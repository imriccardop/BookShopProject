#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(const User** userlp,BookList* blp,UserList *ulp,QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    userl=userlp;
    bl=blp;
    bls=*bl;
    ul=ulp;
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    UpdateTabB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadWindow(){
    if(!(bl->read("bookfile.txt"))){
        QMessageBox::warning(0,"Errore","Non è presente bookfile.txt , il file verrà generato all' interno della cartella che contiene il file .exe durante il salvataggio. \n La lista dei libri sarà vuota");
    };//inserire la gestione degli errori
    UpdateTabB();
    this->show();
    ui->lineEdit->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    //QMessageBox::warning(0,"Errore",QString::number(bl->getNoBook()));
    if((*userl)->isAdmin()==false){ui->pushButton_3->hide();}else{ui->pushButton_3->show();}
    if((*userl)->canWrite()==false){ui->pushButton_7->hide();}else{ui->pushButton_7->show();}
}

void MainWindow::popTabB(BookList *blp){
    std::list<Book> lc=blp->CopiaList();
    int row=0;
    for(std::list<Book>::const_iterator i=lc.begin();i!=lc.end();i++){
            ui->tableWidget->setRowCount(row+1);
            addBookTable(row,*i);
            row++;
    }
}

void MainWindow::addBookTable(int row, Book bp){
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(bp.getQTitolo()));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(bp.getQAutore()));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(bp.getQGenere()));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(bp.getQPrezzo()));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(bp.getQIsbn()));
}

void MainWindow::logpointer(LoginWindow *lwp){
    lw=lwp;
}

void MainWindow::UpdateTabB(){
    bls=*bl;
    popTabB(&bls);
}
//click bottone visualizza tutti i libri
void MainWindow::on_pushButton_5_clicked()
{
    bls=*bl;
    popTabB(&bls);
}

//click del tasto salva
void MainWindow::on_pushButton_clicked()
{
    bl->write("bookfile.txt");
    ul->write("userfile.txt");
    QMessageBox::information(0,"Informazione","Il salvataggio è avvenuto correttamente");
}

//tasto di Logout
void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    QMessageBox::information(0,"Informazione","Il logout è avvenuto correttamente");
    *userl=0;
    lw->show();
}



void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QString title=ui->tableWidget->item(row,0)->text();
    QString autore=ui->tableWidget->item(row,1)->text();
    QString prezzo=ui->tableWidget->item(row,3)->text();
    QString isbn=ui->tableWidget->item(row,4)->text();
    Book b(title.toStdString(),autore.toStdString(),"","",isbn.toStdString(),0,0,prezzo.toDouble());
    const Book* bs=bl->searchBook(b);
    if(bs==0){
        QMessageBox::warning(0,"ERRORE","la visualizzazione del libro ha generato un errore");
    }else{
        if((*userl)->canWrite()==false){
            QString mbtext="Titolo :\t\t"+bs->getQTitolo();
            mbtext=mbtext+"\nScritto da :\t"+bs->getQAutore();
            mbtext=mbtext+"\nGenere :\t\t"+bs->getQGenere();
            mbtext=mbtext+"\nPrezzo :\t\t"+bs->getQPrezzo()+"€";
            mbtext=mbtext+"\nNum. pagine :\t"+bs->getQNumPag();
            mbtext=mbtext+"\nAnno :\t\t"+bs->getQAnno();
            mbtext=mbtext+"\nISBN :\t\t"+bs->getQIsbn();
            mbtext=mbtext+"\nTrama :\n"+bs->getQTrama();
            QMessageBox::about(this,"Info libro",mbtext);
        }else{
            BookWindow *bw=new BookWindow(bl,bs,this);
            bw->show();
        }
    }
}

//click bottone "Cerca tra i libri"
void MainWindow::on_pushButton_8_clicked()
{
    QString parolak=ui->lineEdit->text();
    QString titolo=ui->lineEdit_4 ->text();
    QString autore=ui->lineEdit_3->text();

    bls=*bl;
    if(parolak.length()>0){bls=bls.searchkeyWord(parolak);}
    if(titolo.length()>0){bls=bls.searchInsideTitle(titolo);}
    if(autore.length()>0){bls=bls.searchInsideAutore(autore);}

    if(bls.getNoBook()==0){
        ui->lineEdit->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_3->setText("");
        //bl->read("bookfile.txt");
        UpdateTabB();
        QMessageBox::warning(0,"Errore","Nessun libro risponde alla ricerca");
    }
        popTabB(&bls);
}

void MainWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{

}

//click del tasto Account
void MainWindow::on_pushButton_4_clicked()
{
    AccountUserWindow* auw=new AccountUserWindow(userl,ul,lw,this);
    auw->show();
}

//clich inserisci nuovo libro
void MainWindow::on_pushButton_7_clicked()
{
    BookWindow *bw=new BookWindow(bl,this);
    bw->show();
}

//click bottone pannello admin
void MainWindow::on_pushButton_3_clicked()
{
    Adminwindow *aw=new Adminwindow(userl,ul,this);
    aw->show();
}

//click tasto esci
void MainWindow::on_pushButton_6_clicked()
{
    this->close();
}
