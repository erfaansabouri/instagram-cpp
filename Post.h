//
// Created by ADMIN on 3/24/2019.
//



#pragma once
#include <iostream>
#include <time.h>
#include <string>
#include <list>
//#include "Comment.h"
class Comment;
class Like;
class Profile;
using namespace std;
class Post {
private:
    static string currentDateTime();
public:
    list<Comment> comments;
    list<Like> likes;
    string post_id;
    string contents;
    string imageUrl;
    Profile *profile;
    bool is_image;
    Post(Profile *profile,string contents,string imageUrl = "");

    string showPostId(){ return this->post_id;}
    void print_comments();
    void print_likers();
    int likeCount;
    int CmCount;
};



