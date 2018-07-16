#include "bookwindow.h"
#include "ui_bookwindow.h"

//costruttore per la finestra in modalità inserimento nuovo libro
BookWindow::BookWindow(BookList *blp,MainWindow *mwp,QWidget *parent) :QDialog(parent),ui(new Ui::BookWindow){
    bl=blp;
    mw=mwp;
    ui->setupUi(this);
    makeLErules();
    ui->pushButton->hide();
    ui->pushButton_3->hide();
    setModal(true);
}

//costruttore per la finestra in moalità modifica di libro già esistente
BookWindow::BookWindow(BookList *blp,const Book *book,MainWindow *mwp,QWidget *parent) :QDialog(parent),ui(new Ui::BookWindow){
    ui->setupUi(this);

    mw=mwp;
    bl=blp;
    b=book;

    //makeLErules();
    ui->pushButton_4->hide();
    ui->lineEdit->setText(b->getQTitolo());
    ui->lineEdit_2->setText(b->getQAutore());
    ui->lineEdit_3->setText(b->getQGenere());
    ui->lineEdit_4->setText(b->getQPrezzo());
    ui->lineEdit_5->setText(b->getQNumPag());
    ui->lineEdit_6->setText(b->getQAnno());
    ui->lineEdit_7->setText(b->getQIsbn());
    ui->lineEdit_8->setText(b->getQQuantita());
    ui->textEdit->setText(b->getQTrama());
    makeLErules();
    setModal(true);
}

//make LineEditRules
void BookWindow::makeLErules(){
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("([A-Za-z 1234567890,:.?!']{1,30})")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("([A-Za-z 1234567890,:.?!']{1,30})")));
    ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("([A-Za-z ]{1,30})")));
    ui->lineEdit_4->setValidator(new QRegExpValidator(QRegExp("[1234567890]{1,5}[.][1234567890]{1,2}")));
    ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("([1234567890]{1,5})")));
    ui->lineEdit_6->setValidator(new QRegExpValidator(QRegExp("([1234567890]{1,4})")));
    ui->lineEdit_7->setValidator(new QRegExpValidator(QRegExp("([1234567890]{1,13})")));
    ui->lineEdit_8->setValidator(new QRegExpValidator(QRegExp("([1234567890]{1,3})")));
    //ui->textEdit->set  //->setValidator(new QRegExpValidator(QRegExp("([A-Za-z 1234567890,:.?!']{1,300})")));
}

bool BookWindow::voidBook()const{
    QString qs="";
    return ui->lineEdit->text()==qs || ui->lineEdit_2->text()==qs || ui->lineEdit_4->text()==qs || ui->lineEdit_8->text()==qs;
}

Book BookWindow::makeBook(){
    std::string t=ui->lineEdit->text().toStdString();
    std::string a=ui->lineEdit_2->text().toStdString();
    std::string g=ui->lineEdit_3->text().toStdString();
    double pr=ui->lineEdit_4->text().toDouble();
    unsigned int np=ui->lineEdit_5->text().toInt();
    unsigned int an=ui->lineEdit_6->text().toInt();
    std::string isbn=ui->lineEdit_7->text().toStdString();
    unsigned int q=ui->lineEdit_8->text().toInt();
    QString qtr=ui->textEdit->toPlainText();
    qtr.replace(";",".");
    qtr.replace("\n","");
    qtr.replace("  "," ");
    std::string tr=qtr.toStdString();
    if(g.length()==0){g="Sconosciuto";}
    if(tr.length()==0){tr="Sconosciuta";}
    return Book(t,a,g,tr,isbn,np,an,pr,q);
}


BookWindow::~BookWindow()
{
    delete ui;
}

//tasto annulla
void BookWindow::on_pushButton_2_clicked()
{
    this->close();
}

//tasto salva
void BookWindow::on_pushButton_4_clicked()
{
    if(voidBook()){
        QMessageBox::warning(this,"ERRORE","Non solo stati compilati tutti i campi obbligatori.");
    }else{
        Book bs=makeBook();
        bl->add(bs);
        mw->UpdateTabB();
        this->close();
        QMessageBox::information(this,"Informazione","Il libro è stato inserito correttamente.\n Premi il tasto SALVA per rendere permanente l' inserimento.");
    }
}
//tasto info ? dell isbn
void BookWindow::on_pushButton_5_clicked()
{
    QMessageBox::information(0,"Informazione","Il codice ISBN è un codice composto da 13 cifre che permette di identificare ogni libro.");
}

//click del tasto modifica
void BookWindow::on_pushButton_clicked()
{
    if(voidBook()){
        QMessageBox::warning(this,"ERRORE","Non solo stati compilati tutti i campi obbligatori.");
    }else{
    Book bs=makeBook();
        //bool ok=bl->mod(*b,bs);
        bool ok=bl->kill(*b);
        if(ok==true){
            bl->add(bs);
            QMessageBox::information(0,"Informazione","Il libro è stato modificato correttamente.\n Premi il tasto SALVA per rendere permanente la modifica.");
        }else{
            QMessageBox::warning(0,"Errore","La modifica ha generato un errore");
        }
        mw->UpdateTabB();
        this->close();
    }
}

//click del tasto elimina libro
void BookWindow::on_pushButton_3_clicked()
{
    Book bs=makeBook();
    bool ok=bl->kill(*b);
    if(ok==true){
        QMessageBox::information(0,"Informazione","Il libro è stato eliminato correttamente.\n Premi il tasto SALVA per rendere permanente la cancellazione.");
    }else{
        QMessageBox::warning(0,"Errore","Il tentativo di cancellazione ha generato un errore");
    }
    mw->UpdateTabB();
    this->close();
}
