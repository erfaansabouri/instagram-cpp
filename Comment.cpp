//
// Created by ADMIN on 3/24/2019.
//

#include "Comment.h"

/*
Comment::Comment(Profile *profile) : profile(profile){
    static int cmId = 3000;
    comment_id = cmId++;
    if(father == nullptr)
        this->depth = 0;
    else
        this->depth = (father->depth) + 1;
}
*/
Comment::Comment(string contents, Profile *profile, Post *post ,  Comment *father) : contents(contents) , profile(profile) , post(post) {
    static int cmId = 3000;
    comment_id = cmId++;
    if(father == nullptr)
        this->depth = 0;
    else
        this->depth = (father->depth) + 1;
}
