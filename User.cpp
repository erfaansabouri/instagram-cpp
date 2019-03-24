//
// Created by Erfan Sabouri on 3/23/2019.
//

#include "User.h"

#include "Profile.h"
#include "DataBase.h"
const string &User::getUsername()  {
    return username;
}

void User::setPassword(const string &password) {
    this->password = password; //TODO hash
}

bool User::resetPassword(const string &new_password) {
    if(this->password == new_password)
        return false;
    else
        this->password = new_password;
    return true;
}

bool User::login(const string &username, const string &password) {
    User found_user = DataBase::findUser(username);
    return found_user.password == User::hash(password);
}

bool User::signup(const string &username, const string &password, const string &email) {

    User new_user(username,email);
    new_user.setPassword(User::hash(password));
    DataBase::addUser(new_user);
    Profile new_profile(&(DataBase::findUser(username)));
    DataBase::addProfile(new_profile);
    return true;

}

User::User(const string &username, const string &email) {
    static int u_id = 1000;
    this->user_id = ++u_id;
    this->username = username;
    this->email = email;
}

const string User::hash(const string &password) {
    // TODO: hash password
    return password;
}


