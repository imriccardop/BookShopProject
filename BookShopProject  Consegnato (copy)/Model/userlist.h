#ifndef USERLIST_H
#define USERLIST_H

#include "user.h"
#include "userstandard.h"
#include "useradvanced.h"
#include "useradmin.h"

#include<list>
#include<string>
#include<fstream>
#include<QStringList>

class UserList
{
private:
    std::list<User*> l;
    void killAll();//XA
public:
    UserList();
    UserList(const UserList & ul);
    ~UserList();
    UserList& operator =(const UserList& ul);
    std::list<User*> CopiaList(const User * userl)const;
    bool add(User* usp);
    bool deleteUser(const User *us);
    bool modificaUser(const User *userl,std::string n,std::string p);
    const User* search(User* usp) const;
    bool read(std::string nf);
    bool write(std::string nf) const;
};

#endif // USERLIST_H
