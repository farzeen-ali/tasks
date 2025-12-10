#ifndef USER_H
#define USER_H

#include<string>

class User{
    private:
        std::string fullName;
        std::string email;
        std::string username;
        size_t passwordHash;
    public:
        User();
        User(std::string fullName, std::string email, std::string username, size_t hash);

        std::string getFullName() const;
        std::string getEmail() const;
        std::string getUsername() const;
        size_t getPasswordHash() const;

        static std::string generateUsername();
        static size_t hashPassword(const std::string &password);
};

#endif