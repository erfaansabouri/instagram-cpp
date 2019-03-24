//
// Created by Erfan Sabouri on 3/23/2019.
//

#ifndef HW2_DATABASE_H
#define HW2_DATABASE_H
#include <string>
#include <list>
#include "User.h"
#include "Profile.h"

class DataBase {
private:
    static list<User> _users;
    static list<Profile> _profiles;

public:
    static void addUser(const User &user);

    static User &findUser(const string &username);

    static void addProfile(const Profile &profile);

    static Profile &findProfile(const string &username);

    static void print_profiles(){
        list<Profile>::iterator it;
        for (auto it = _profiles.begin(); it != _profiles.end(); it++){
            cout<< it->user->getUsername() << endl; ;
        }
    }
};


#endif //HW2_DATABASE_H
