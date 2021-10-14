//
//  gechatuser.hpp
//  HW6-3
//
//  Created by Apple on 2019/12/4.
//  Copyright © 2019 huangly. All rights reserved.
//

#ifndef gechatuser_h
#define gechatuser_h
#include "customset.h"
#include <stdio.h>
class GechatUser: public std::enable_shared_from_this<GechatUser>//获得指向this的shared_ptr
{
public:
    // Assume using namespace std;
    GechatUser();
    GechatUser(string username);
    GechatUser(const GechatUser& other);
    ~GechatUser();
    
    int numFriends() const;
    string getName() const;
    void setUsername(string username);
    bool haveFriend(shared_ptr<GechatUser> user); // return true if user is a friend to *this.
    bool addFriend(shared_ptr<GechatUser> user); // return false only if user is invalid or already a friend.
    bool singleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
    bool singleDelete(string username); // return false only if username not found in friends.
    bool doubleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
    bool doubleDelete(string username); // return false only if username not found in friends.
    //重载
    std::shared_ptr<GechatUser> getPtr();
    bool operator< (const GechatUser user);
    bool operator==(const GechatUser& user) const;
    friend ostream & operator<< (ostream & out, GechatUser user);//重载 << 需声明为friend
    // Not complete...
private:
    string m_name;
    CustomSet<shared_ptr<GechatUser>> f_list;
    std::shared_ptr<GechatUser> p1;//获得指向this的shared_ptr
};
//同一类可以互相访问私有，不用friend
#endif /* gechatuser_h */
