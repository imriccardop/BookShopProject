#ifndef USERADMIN_H
#define USERADMIN_H

#include "user.h"

class UserAdmin : public User
{
public:
    UserAdmin(std::string name, std::string psw);
    UserAdmin(std::string s);
    UserAdmin* clone() const;
    bool isAdmin() const;
    bool canWrite() const;
    std::string fUsertString() const;
};

#endif // USERADMIN_H
