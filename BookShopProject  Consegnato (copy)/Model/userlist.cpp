#include "userlist.h"

UserList::UserList(){}

UserList::UserList(const UserList & ul){
    for(std::list<User*>::const_iterator i=ul.l.begin();i!=ul.l.end();++i){
            add((*i)->clone());
    }
}

UserList::~UserList(){
    for(std::list<User*>::iterator i=l.begin();i!=l.end();++i){
            delete *i;
    }
}

void UserList::killAll(){//XA
    for(std::list<User*>::const_iterator i=l.begin();i!=l.end();++i){
            delete(*i);
    }
    l.clear();
}
UserList& UserList::operator =(const UserList& ul){
    //l=std::list<User*>;
    killAll();
    for(std::list<User*>::const_iterator i=ul.l.begin();i!=ul.l.end();++i){
            add((*i)->clone());
    }
    return *this;
}

std::list<User*> UserList::CopiaList(const User * userl)const{
    std::list<User*> lr;
    for(std::list<User*>::const_iterator i=l.begin();i!=l.end();++i){
        if(!(**i==*userl))
            lr.push_back((*i)->clone());
    }
    return lr;
}

bool UserList::add(User* usp){
    for(std::list<User*>::iterator i=l.begin();i!=l.end();i++){
        if(**i==*usp){return false;}
    }
    l.push_back(usp->clone());
    return true;
}
bool UserList::deleteUser(const User *us){
    bool ok=true;
    for(std::list<User*>::iterator i=l.begin();i!=l.end() && ok ;++i){
        if((*i)->getNickname()==us->getNickname()){
            delete *i;
            l.erase(i);
            ok=false;
        }
    }
    return !ok;
}

bool UserList::modificaUser(const User *userl,std::string n,std::string p){
    bool ok=true;
    for(std::list<User*>::iterator i=l.begin();i!=l.end() && ok ;++i){
        if((*i)->getNickname()==userl->getNickname()){
            (*i)->setNickname(n);
            (*i)->setPassword(p);
            ok=false;
        }
    }
    return !ok;
}

const User* UserList::search(User* usp) const{
    for(std::list<User*>::const_iterator i=l.begin();i!=l.end();i++){
        if((*i)->login(usp)){ return *i;}
    }
    return 0;
}


bool UserList::read(std::string nf){
    std::ifstream testfile(nf);
    if(!(testfile)){
        l.push_back(UserAdmin("admin","admin").clone());
        return false;
    }
    std::ifstream myfile;
    myfile.open(nf);

    while(!myfile.eof()) {
        std::string q, line;
        getline(myfile,q,'$');
        getline(myfile,line);
        if(QString::fromStdString(line).split(";", QString::SkipEmptyParts).size()==2){//if(line.length()>3){
            if(q.compare("Ustandard")==0){
                l.push_back(UserStandard(line).clone());
            }else{
                if(q.compare("Uadvanced")==0){
                    l.push_back(UserAdvanced(line).clone());
                }else{
                    if(q.compare("Uadmin")==0){
                        l.push_back(UserAdmin(line).clone());
                    }
                }
            }
        }
    }
    myfile.close();
    if(l.size()>0){
        return true;
    }else{
        l.push_back(UserAdmin("admin","admin").clone());
        return false;
    }
}

bool UserList::write(std::string nf) const{
    std::ofstream myfile(nf);
    //myfile.open (nf);
    std::string s="";
    for(std::list<User*>::const_iterator i=l.begin();i!=l.end();i++){
        s=s+ (*i)->fUsertString()+"\n";
    }
    myfile <<s;
    myfile.close();
    return true;
}
