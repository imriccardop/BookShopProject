#ifndef USERADVANCED_H
#define USERADVANCED_H

#include "userstandard.h"

class UserAdvanced : public UserStandard{
public:
    UserAdvanced(std::string name, std::string psw);
    UserAdvanced(std::string s);
    UserAdvanced* clone() const;
    bool canWrite() const;
    std::string fUsertString() const;
};

#endif // USERADVANCED_H
