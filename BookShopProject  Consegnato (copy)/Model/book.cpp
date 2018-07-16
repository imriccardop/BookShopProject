#include "book.h"
#include<qstring.h>
Book::Book(){}

Book::Book(std::string Titolo, std::string Autore, std::string Genere, std::string Trama, std::string Isbn, unsigned int NumPag, unsigned int Anno, double Prezzo, unsigned int quantita){
    titolo=Titolo;
    autore=Autore;
    genere=Genere;
    trama=Trama;
    isbn=Isbn;
    nb=quantita;

    std::replace( titolo.begin(), titolo.end(), ';', '.');
    std::replace( autore.begin(), autore.end(), ';', '.');
    std::replace( genere.begin(), genere.end(), ';', '.');
    std::replace( trama.begin(), trama.end(), ';', '.');

    numPag=NumPag;
    anno=Anno;
    prezzo=Prezzo;
    if(!(isbn.length()==13 && isbn.find_first_not_of("0123456789") == std::string::npos)){
        isbn="Sconosciuto";
    }
}

Book::Book(std::string s){
    int i=0;
    titolo= s.substr (0,s.find(";"));
    s= s.substr (s.find(";")+1,s.length());
    autore= s.substr (0,s.find(";"));
    s= s.substr (s.find(";")+1,s.length());
    genere= s.substr (0,s.find(";"));
    s= s.substr (s.find(";")+1,s.length());
    trama= s.substr (0,s.find(";"));
    s= s.substr (s.find(";")+1,s.length());
    isbn= s.substr (0,s.find(";"));
    s= s.substr (s.find(";")+1,s.length());
    QString qnumPag= QString::fromStdString(s.substr (0,s.find(";")));
    numPag=qnumPag.toInt();
    s= s.substr (s.find(";")+1,s.length());
    QString qanno= QString::fromStdString(s.substr (0,s.find(";")));
    anno=qanno.toInt();
    s= s.substr (s.find(";")+1,s.length());
    QString qprezzo= QString::fromStdString(s.substr (0,s.find(";")));
    prezzo=qprezzo.toDouble();
    s= s.substr (s.find(";")+1,s.length());
    QString qquantita= QString::fromStdString(s.substr (0,s.find(";")));
    nb=qquantita.toInt();

    if(!(isbn.length()==13 && isbn.find_first_not_of("0123456789") == std::string::npos)){isbn="Sconosciuto";}

}
/*
int Book::searchInside(std::string s)const{
    if(titolo.find(s)!=-1 || autore.find(s)!=-1) {return 2;}
    if(trama.find(s)!=-1 || genere.find(s)!=-1){return 1;}
    return 0;
}
*/
std::string Book::fBooktString()const{
  QString pv(";");
  QString r= QString::fromStdString(titolo)+pv+QString::fromStdString(autore)+pv+
          QString::fromStdString(genere)+pv+QString::fromStdString(trama)+pv+
          QString::fromStdString(isbn)+pv+QString::number(numPag)+pv+QString::number(anno)+pv+QString::number(prezzo)+pv+QString::number(nb)+pv;
    return r.toStdString();
}

Book* Book::clone()const{ return new Book(*this); }

//funzioni di get
unsigned int Book::getQuantita(){return nb;}

//funzioni di getQ
QString Book::getQTitolo()const{ return QString::fromStdString(titolo);}
QString Book::getQAutore()const{ return QString::fromStdString(autore);}
QString Book::getQGenere()const{ return QString::fromStdString(genere);}
QString Book::getQTrama()const{ return QString::fromStdString(trama);}
QString Book::getQIsbn()const{ return QString::fromStdString(isbn);}
QString Book::getQNumPag()const{ return QString::number(numPag);}
QString Book::getQAnno()const{ return QString::number(anno);}
QString Book::getQPrezzo()const{ return QString::number(prezzo);}
QString Book::getQQuantita()const{return QString::number(nb);}

//funzioni di set
void Book::setTitolo(std::string t){ titolo=t;}
void Book::setAutore(std::string a){ autore=a;}
void Book::setGenere(std::string g){ genere=g;}
void Book::setTrama(std::string t){ trama=t;}
void Book::setIsbn(std::string i){ isbn=i;}
void Book::setNumPag(unsigned int np){ numPag=np;}
void Book::setAnno(unsigned int a){ anno=a;}
void Book::setPrezzo(double p){ prezzo=p;}
void Book::setQuantita(unsigned int quantita){nb=quantita;}

//overloading operatori
bool Book::operator ==(const Book& b) const{
    if(isbn.compare("Sconosciuto")!=0 && b.isbn.compare("Sconosciuto")!=0){
        return isbn.compare(b.isbn)==0 && prezzo==b.prezzo;
    }else{
        return titolo.compare(b.titolo)==0 && autore.compare(b.autore)==0 && prezzo==b.prezzo;
    }
}

bool Book::operator <(Book b) const{
    return titolo.compare(b.titolo)<=0;
}
