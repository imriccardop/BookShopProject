#ifndef BOOK_H
#define BOOK_H

#include<string>
#include<qstring.h>


class Book
{

private:
    std::string titolo;
    std::string autore;
    std::string genere;
    std::string trama;
    std::string isbn;

    unsigned int numPag;
    unsigned int anno;
    unsigned int nb;//numero book, un intero che indica la qualtità di libri
    double prezzo;

public:
    //costruttori
    Book();
    Book(std::string Titolo, std::string Autore, std::string Genere="Sconosciuto",
         std::string Trama="Sconosciuta",std::string Isbn="Sconosciuto",
         unsigned int numPag=0, unsigned int Anno=0, double Prezzo=0,
         unsigned int quantita=0);
    Book(std::string s);


    /*searchInside ricerca una parola all' interno dei dati del libro
        0= parola non presente
        1= parola presente nella trama
        2= parola presente in titolo o autore*/
    //int searchInside(std::string s)const;

    /* fromBooktoString restituisce una stringa con l' elenco
     *  di elementi dell oggetto book intervallati dal  ; */
    std::string fBooktString()const;

    Book* clone() const;

    //funzioni di get
    unsigned int getQuantita();

    //funzioni di getQ
    QString getQTitolo()const;
    QString getQAutore()const;
    QString getQGenere()const;
    QString getQTrama()const;
    QString getQIsbn()const;
    QString getQNumPag()const;
    QString getQAnno()const;
    QString getQPrezzo()const;
    QString getQQuantita()const;

    //funzioni di set
    void setTitolo(std::string t);
    void setAutore(std::string a);
    void setGenere(std::string g);
    void setTrama(std::string t);
    void setIsbn(std::string i);
    void setNumPag(unsigned int np);
    void setAnno(unsigned int a);
    void setPrezzo(double p);
    void setQuantita(unsigned int quantita);

    //overloading operatori
    bool operator ==(const Book& b) const;
    bool operator <(Book b) const;
};



#endif // BOOK_H
