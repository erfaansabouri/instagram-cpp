//
// Created by ADMIN on 3/24/2019.
//

#include "Post.h"
#include "Profile.h"

string Post::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}


Post::Post(Profile *profile,string contents , string imageUrl) : profile(profile),post_id(profile->user->getUsername() + currentDateTime()),contents(contents) {
    this->imageUrl = imageUrl;
    CmCount = 0;
    likeCount = 0;
}

void Post::print_comments() {
    for (Comment &comment : Post::comments) {
        cout << comment.contents << endl;
    }
}

void Post::print_likers() {
    for (Like &like : Post::likes) {
        cout << like.profile->user->getUsername() << endl;
    }
}



