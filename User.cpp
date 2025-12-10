#include "User.h"
#include<random>

User::User() {};

User::User(std::string fullName, std::string email, std::string username, size_t hash){
    this->fullName = fullName;
    this->email = email;
    this->username = username;
    this->passwordHash = hash;
}

std::string User::getFullName() const {
    return fullName;
}
std::string User::getEmail() const {
    return email;
}
std::string User::getUsername() const {
    return username;
}
size_t User::getPasswordHash() const {
    return passwordHash;
}

// generate username 10 digit

std::string User::generateUsername(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,9);

    std::string id = "";
    for(int i = 0; i < 10; i++){
        id += std::to_string(dist(gen));
    }

    return id;
}

// password hashing

size_t User::hashPassword(const std::string &password){
    std::hash<std::string> hasher;
    return hasher(password);
}