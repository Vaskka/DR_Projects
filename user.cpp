#include "user.h"

User::User()
{

}

User::User(std::string name, std::string number, int access)
{
    this->name = QString(name.c_str());
    this->number = QString(number.c_str());
    this->access = access;
}
