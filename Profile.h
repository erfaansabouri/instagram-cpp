//
// Created by Erfan Sabouri on 3/23/2019.
//

#pragma once
#include <string>
#include <iostream>
#include <list>
#include "User.h"
#include "Post.h"
#include "Comment.h"
#include "Like.h"

using namespace std;

class Profile {
public:
    string name;
    string bio;
    bool is_private;
    list<Profile> followers;
    list<Profile> following;
    list<Post> posts;
    User *user;
    Profile(User *user , const string &name = "", const string &bio = "" , bool gender = true);
    void print_followers();
    void print_following();
    void print_posts();
public:
    int phone_number;
    bool gender; // false female , true male
    bool getPrivate(){return is_private;}
    void setPrivate(bool pr){this->is_private = pr;}
    void follow(Profile &profile);
    void unfollow(Profile &profile);
    void block(Profile &profile);
    void createPost(string contents,string imageUrl = "");
    bool deletePost(Post &post);
    Post &findPost(string contents);
    void sendComment(const string contents,Post &post);
    //Comment &findComment(Post &post,int comment_id);
    void sendReply(const string contents,Post &post,Comment &comment);
    void like(Post &post);

};


