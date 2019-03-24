/* developed by Erfan Sabouri */

#include <iostream>
#include "User.h"
#include "DataBase.h"
#include "Profile.h"
#include "Post.h"
#include "Comment.h"
using namespace std;

int main() {
    User::signup("erfan","123","e@g.com");
    User::signup("hassan" , "123" , "h@g.com");
    Profile erfan = DataBase::findProfile("erfan");
    erfan.createPost("post0");
    erfan.createPost("post1");
    erfan.createPost("post2");
    erfan.createPost("post3");
    erfan.createPost("post with image","http");

    erfan.print_posts();

    Post p = erfan.findPost("post2");
    erfan.sendComment("hi",p);
    erfan.sendComment("hi",p);
    erfan.sendComment("hi",p);
    erfan.sendComment("hi",p);
    p.print_comments();
    cout << "count " << p.CmCount;
    erfan.like(p);
    erfan.like(p);
    erfan.like(p);
    erfan.like(p);
    //erfan.like(p);
    cout << endl << "like count " <<p.likeCount << endl;
    p.print_likers();
    return 0;
}