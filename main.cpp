#include<iostream>
#include "UserManager.h"

int main(){
    UserManager manager("users.csv");
    manager.registerUser();
    return 0;
}