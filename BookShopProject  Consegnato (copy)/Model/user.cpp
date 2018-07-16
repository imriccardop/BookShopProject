#include "user.h"

User::User(std::string name, std::string psw):nickname(name), password(psw){}

User::User(std::string s){
        nickname= s.substr (0,s.find(";"));
        s= s.substr (s.find(";")+1,s.length());
        password= s.substr (0,s.find(";"));
}

bool User::login(User* up) const{
    return nickname.compare(up->nickname)==0 && password.compare(up->password)==0;
}


std::string User::infoprint() const{
    return nickname+";"+password+";";
}

QString User::getNickname()const{
    return QString::fromStdString(nickname);
}

QString User::getPassword()const{
    return QString::fromStdString(password);
}


void User::setNickname(std::string newnick){
    nickname=newnick;
}

void User::setPassword(std::string newpw){
    password=newpw;
}
bool User::operator==(const User& u) const{
    if(nickname.compare(u.nickname)==0){ return true;}
    return false;
}
