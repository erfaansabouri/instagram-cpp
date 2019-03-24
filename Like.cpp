//
// Created by ADMIN on 3/25/2019.
//

#include "Like.h"
#include "Post.h"

Like::Like(Profile *profile, Post *post) : profile(profile) , post(post){
    post->likeCount++;
}
