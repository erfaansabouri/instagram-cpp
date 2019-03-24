//
// Created by ADMIN on 3/24/2019.
//

#ifndef HW2_COMMENT_H
#define HW2_COMMENT_H


#include "Post.h"
#include <string>
using namespace std;
class Profile;
class Comment {
public:
    string contents;
    int comment_id;
    int depth; //if depth == 0 ; its comments otherwise its a reply with specefic depth
    Profile *profile;
    Post *post;
    Comment(string contents , Profile *profile , Post *post , Comment *father = nullptr);

};


#endif //HW2_COMMENT_H
