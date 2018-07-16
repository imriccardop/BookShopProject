#include "userstandard.h"

UserStandard::UserStandard(std::string name, std::string psw):User(name,psw){}

UserStandard::UserStandard(std::string s):User(s){}

 UserStandard* UserStandard::clone() const{
    return new UserStandard(*this);
}

bool UserStandard::isAdmin() const{return false;}
bool UserStandard::canWrite() const{return false;}


std::string UserStandard::fUsertString() const{
    return "Ustandard$"+this->infoprint();
}
