//
// Created by Erfan Sabouri on 3/23/2019.
//

#ifndef HW2_USER_H
#define HW2_USER_H
#include <string>
#include "Post.h"

using namespace std;


class User {
private:
    string username;
    string password;
    string email;
    int user_id;
    User(const string &username , const string &email);
    static const string hash(const string &password);
    friend Post;
    friend Profile;
public:
    const string & getUsername();
    void setPassword(const string &password);
    bool resetPassword(const string &new_password);
    static bool login(const string &username ,const string &password);
    static bool signup(const string &username , const string &password , const string &email);
};



#endif //HW2_USER_H
