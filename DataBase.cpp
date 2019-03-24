//
// Created by ADMIN on 3/23/2019.
//

#include "DataBase.h"

// Setup static attributes
list<User> DataBase::_users;
list<Profile> DataBase::_profiles;

void DataBase::addUser(const User &user) {
    DataBase::_users.push_back(user);
}


User &DataBase::findUser(const string &username) {
    for (User &user : DataBase::_users) {
        if (user.getUsername() == username)
            return user;
    }
    throw 5;
}

void DataBase::addProfile(const Profile &profile) {
    DataBase::_profiles.push_back(profile);
}

Profile &DataBase::findProfile(const string &username) {
    for (Profile &profile : DataBase::_profiles) {
        if (profile.user->getUsername() == username)
            return profile;
    }
    throw 6;
}

