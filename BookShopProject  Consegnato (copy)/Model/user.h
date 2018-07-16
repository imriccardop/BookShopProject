#ifndef USER_H
#define USER_H

#include<string>
#include<QString>

class User
{
private:
    std::string nickname;
    std::string password;

public:
    User(std::string name, std::string psw);
    User(std::string s);
    virtual bool isAdmin() const=0;
    virtual bool canWrite() const=0;
    virtual User* clone() const=0;
    std::string infoprint() const;
    virtual std::string fUsertString() const=0;
    bool canRead() const;

    bool login(User* usp) const;

    QString getNickname()const;
    QString getPassword()const;

    //bool setUser(User us,std::string newnick,std::string newpw);
    void setNickname(std::string newnick);
    void setPassword(std::string newpw);
    bool operator==(const User& u) const;
};

#endif // USER_H
