#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include<string>

class UserManager{
    private:
        std::string userFile;
    public:
        UserManager(std::string file);

        bool userExists(const std::string &fullName, const std::string &email);

        void saveUser(const User &user);

        void registerUser();

};

#endif