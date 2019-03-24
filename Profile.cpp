//
// Created by ADMIN on 3/23/2019.
//

#include "Profile.h"


Profile::Profile(User *user, const string &name, const string &bio,bool gender) : user(user), name(name), bio(bio),
                                                                                     gender(gender) {}


void Profile::follow(Profile &profile) {
    this->following.push_back(profile);
    profile.followers.push_back(*this);
}

void Profile::unfollow(Profile &profile) {
    list<Profile>::iterator it;
    for (auto it = following.begin(); it != following.end(); ++it){
        if(it->user->getUsername() == profile.user->getUsername()){
            following.erase(it);
            break;
        }
    }
    for (auto it = profile.followers.begin(); it != profile.followers.end(); ++it){
        if(it->user->getUsername() == this->user->getUsername()){
            profile.followers.erase(it);
            break;
        }
    }
}


void Profile::block(Profile &profile) {
    list<Profile>::iterator it;
    for (auto it = following.begin(); it != following.end(); ++it){
        if(it->user->getUsername() == profile.user->getUsername()){
            following.erase(it);
            break;
        }
    }

    for (auto it = followers.begin(); it != followers.end(); ++it){
        if(it->user->getUsername() == profile.user->getUsername()){
            followers.erase(it);
            break;
        }
    }

    for (auto it = profile.followers.begin(); it != profile.followers.end(); ++it){
        if(it->user->getUsername() == this->user->getUsername()){
            profile.followers.erase(it);
            break;
        }
    }

}

void Profile::print_followers() {
    list<Profile>::iterator it;
    for (auto it = followers.begin(); it != followers.end(); ++it){
        cout<< it->user->getUsername() << endl; ;
    }
}

void Profile::print_following() {
    list<Profile>::iterator it;
    for (auto it = following.begin(); it != following.end(); ++it){
        cout<< it->user->getUsername() << endl; ;
    }
}


void Profile::createPost(string contents,string imageUrl) {
    Post new_post(this,contents,imageUrl);
    this->posts.push_back(new_post);
}


bool Profile::deletePost(Post &post) {
    list<Post>::iterator it;
    for (auto it = posts.begin(); it != posts.end(); ++it){
        if(it->post_id == post.post_id)
            posts.erase(it);
    }
}



void Profile::print_posts() {
    int i = 1;
    for (Post &post : Profile::posts) {
        cout << i++ << '.' << post.contents << endl;
    }
}

void Profile::sendComment(const string contents, Post &post) {
    Comment new_comment(contents,this,&post);
    post.comments.push_back(new_comment);
    post.CmCount++;
}

Post &Profile::findPost(string contents) {
    for (Post &postt : Profile::posts) {
        if(postt.contents == contents)
            return postt;
    }
}


void Profile::sendReply(const string contents, Post &post, Comment &comment) {
    Comment new_comment(contents,this,&post,&comment);
    post.comments.push_back(new_comment);
    post.CmCount++;
}

void Profile::like(Post &post) {

    /*
    for (Like &like : post.likes) {
        if(like.profile->user->user_id == this->user->user_id){
            post.likes.remove(like);
            post.likeCount--;
        }
    }
    */
    for (auto it = post.likes.begin(); it != post.likes.end(); ++it){
        if(it->profile->user->user_id == this->user->user_id){
            post.likes.erase(it);
            post.likeCount--;
            return;
        }
    }
    Like new_like(this,&post);
    post.likes.push_back(new_like);
}
/*
Comment &Profile::findComment(Post &post , int comment_id) {
    for (auto it = post.comments.begin(); it != post.comments.end(); ++it){
        if(it->comment_id == comment_id)
            return *it;
    }
}
*/


