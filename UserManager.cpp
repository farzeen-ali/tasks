#include "UserManager.h"
#include<fstream>
#include<iostream>
#include<sstream>

UserManager::UserManager(std::string file){
    this->userFile = file;
}

bool UserManager::userExists(const std::string &fullName, const std::string &email){
    std::ifstream file(userFile);
    if(!file.is_open()) return false;

    std::string line;

    while(getline(file, line)){
        std::stringstream ss(line);
        std::string name, mail, username, hash;

        getline(ss, name, ',');
        getline(ss, mail, ',');
        getline(ss, username, ',');
        getline(ss, hash, ',');

        if(name == fullName && mail == email){
            return true;
        }
    }
    return false;
}

void UserManager::saveUser(const User &user){
    std::ofstream file(userFile, std::ios::app);

    file << user.getFullName() << ","
         << user.getEmail() << ","
         << user.getUsername() << ","
         << user.getPasswordHash()
         << "\n";
    
    file.close();
}

void UserManager::registerUser(){
    std::string fullName, email, password;

    std::cout<<"\n==== Register User =====\n";
    std::cout<<"Enter Full Name: ";
    getline(std::cin, fullName);
    std::cout<<"Enter Email: ";
    getline(std::cin, email);
    std::cout<<"Enter Password: ";
    getline(std::cin, password);

    if(userExists(fullName, email)){
        std::cout<<"\nUser Already Exists!\n";
        return;
    }

    std::string username = User::generateUsername();

    size_t hashPassword = User::hashPassword(password);

    User user(fullName, email, username, hashPassword);
    saveUser(user);

    std::cout<<"\nUser Registered Successfully!\n";
    std::cout<<"Your username is: "<< username<<"\n";
}