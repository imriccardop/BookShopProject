#ifndef USERSTANDARD_H
#define USERSTANDARD_H

#include<string>
#include "user.h"

class UserStandard: public User{

public:

    UserStandard(std::string name, std::string psw);
    UserStandard(std::string s);
    virtual bool isAdmin() const;
    virtual bool canWrite() const;
    virtual UserStandard* clone() const;
    std::string fUsertString() const;
};

#endif // USERSTANDARD_H
