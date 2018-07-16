#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "book.h"
#include<list>
#include<fstream>
#include<string>
#include<QStringList>

class BookList{
private:
    std::list<Book> l;
    //bool checktextBook(std::string ok);
public:
    const Book* searchBook(const Book& b)const;

    BookList();
    void add(Book b);
    bool mod(const Book& oldb,const Book& newb);
    bool kill(const Book& b);//XA
    int getNoBook() const;
    bool read(std::string nf);
    bool write(std::string nf) const;
    BookList searchkeyWord(QString qs) const;
    BookList searchInsideTitle(QString titolo) const;
    BookList searchInsideAutore(QString autore) const;
    BookList insideTitle(QString qs) const;
    BookList insideAutore(QString qs) const;
    std::string pABook()const;//printAllBook
    std::list<Book> CopiaList()const;
};

#endif // BOOKLIST_H
