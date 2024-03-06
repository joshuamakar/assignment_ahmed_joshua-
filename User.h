#ifndef USER_H
#define USER_H

#include <QString>

struct User {
    QString username;
    QString password;
    int age;
};

extern User users[100];
extern int userCount;

#endif // USER_H
