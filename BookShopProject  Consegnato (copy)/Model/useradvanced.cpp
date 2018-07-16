#include "useradvanced.h"

UserAdvanced::UserAdvanced(std::string name, std::string psw):UserStandard(name,psw) {}
UserAdvanced::UserAdvanced(std::string s):UserStandard(s){}
UserAdvanced* UserAdvanced::clone() const{
    return new UserAdvanced(*this);
}
bool UserAdvanced::canWrite() const{return true;}

std::string UserAdvanced::fUsertString() const{
    return "Uadvanced$"+this->infoprint();
}
