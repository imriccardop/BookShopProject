#include "useradmin.h"

UserAdmin::UserAdmin(std::string name, std::string psw): User(name,psw){}
UserAdmin::UserAdmin(std::string s):User(s){}

UserAdmin* UserAdmin::clone() const{
    return new UserAdmin(*this);
}

bool UserAdmin::isAdmin() const{ return true;}
bool UserAdmin::canWrite() const{return true;}

std::string UserAdmin::fUsertString() const{
    return "Uadmin$"+this->infoprint();
}
