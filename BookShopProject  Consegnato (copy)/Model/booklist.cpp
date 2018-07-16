#include "booklist.h"
#include<iostream>

BookList::BookList(){}

void BookList::add(Book nb){
    bool elins=false;//ELementoINSerito
    for(std::list<Book>::iterator i=l.begin();i!=l.end() && !elins;i++){
        if(nb.getQTitolo()<i->getQTitolo()){
            l.insert(i,nb);
            elins=true;
        }if(nb==*i){
            i->setQuantita(i->getQuantita()+nb.getQuantita());
            elins=true;
        }
    }
    if(elins==false){
        l.push_back(nb);
    }
}

bool BookList::mod(const Book& oldb,const Book& newb){
    bool elins=false;//ELementoINSerito
    for(std::list<Book>::iterator i=l.begin();i!=l.end() && !elins;i++){
       if(oldb==*i){
            *i=newb;
            elins=true;
        }
    }
    return elins;
}

bool BookList::kill(const Book& b){
    bool elins=false;//ELementoINSerito
    for(std::list<Book>::iterator i=l.begin();i!=l.end() && !elins;i++){
       if(b==*i){
            l.erase(i);
            elins=true;
        }
    }
    return elins;
}
/*
bool checktextBook(std::string ok){
    int n=0;
    for ( std::string::iterator i=ok.begin(); i!=ok.end(); ++i){
        if(*i==';'){n++;}
     }
     if(n==9){return true;}else{return false;}
}
*/
int BookList::getNoBook() const{
    return l.size();
}

bool BookList::read(std::string nf){
    std::ifstream testfile(nf);
    if(!(testfile)){
        return false;
    }
    l.clear();
    std::ifstream myfile;
    myfile.open(nf);
    while(!myfile.eof()) {
        std::string line;
        getline(myfile,line);
        if(QString::fromStdString(line).split(";", QString::SkipEmptyParts).size()==9){     //if(line.length()>9)
            add(Book(line));//l.push_back(Book(line));
        }
    }
    myfile.close();
    return true;
}

bool BookList::write(std::string nf) const{
    std::ofstream myfile(nf);
    //myfile.open (nf);
    std::string line="";
    for(std::list<Book>::const_iterator i=l.begin();i!=l.end();i++){
        line=line + i->fBooktString()+"\n";
    }
    myfile<<line;
    myfile.close();
    return true;
}

BookList BookList::searchInsideTitle(QString titolo) const{
    BookList r;
    for(std::list<Book>::const_iterator i=l.begin();i!=l.end();i++){
        if(i->getQTitolo().contains(titolo, Qt::CaseInsensitive)){
            r.add(*i);
        }
    }
    return r;
}

BookList BookList::searchInsideAutore(QString autore) const{
    BookList r;
    for(std::list<Book>::const_iterator i=l.begin();i!=l.end();i++){
        if(i->getQAutore().contains(autore, Qt::CaseInsensitive)){
            r.add(*i);
        }
    }
    return r;
}

BookList BookList::searchkeyWord(QString qs) const{
    QStringList ql=qs.split(" ", QString::SkipEmptyParts);
    BookList r;
    for (int i = 0; i < ql.size(); ++i){
        for(std::list<Book>::const_iterator j=l.begin();j!=l.end();j++){
            if(QString::fromStdString(j->fBooktString()).contains(ql.at(i), Qt::CaseInsensitive)==true){
                r.add(Book(*j));
            }
        }
    }
    return r;
    /*
    BookList r;
    for(std::list<Book>::const_iterator i=l.begin();i!=l.end();i++){
        int sr=i->searchInside(qs.toStdString());
        if(sr==1){r.l.push_back(Book(*i));}
        if(sr==2){r.l.push_front(Book(*i));}
    }
    return r;
    */
}

const Book* BookList::searchBook(const Book& b)const{
    for(std::list<Book>::const_iterator i=l.begin();i!=l.end();++i){
        if(*i==b){return &(*i);}
    }
    return 0;
}

std::list<Book> BookList::CopiaList()const{ return l;}
