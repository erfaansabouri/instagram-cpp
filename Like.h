//
// Created by ADMIN on 3/25/2019.
//

#ifndef HW2_LIKE_H
#define HW2_LIKE_H

class Post;
class Profile;

class Like {
public:
    Profile *profile;
    Post *post;
    Like(Profile *profile , Post *post);
};


#endif //HW2_LIKE_H
