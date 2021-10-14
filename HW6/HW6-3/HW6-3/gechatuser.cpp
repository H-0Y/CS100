//
//  gechatuser.cpp
//  HW6-3
//
//  Created by Apple on 2019/12/4.
//  Copyright © 2019 huangly. All rights reserved.
//

#include "gechatuser.h"
//ostream oprator<<(vector frid){
//
//    //how to print
//}
GechatUser::GechatUser(){}

GechatUser::GechatUser(string username)
{
    m_name=username;
}

GechatUser::GechatUser(const GechatUser& other)
{
    m_name=other.m_name;
    f_list=other.f_list;//同一个类可以相互访问private
}

GechatUser::~GechatUser(){}

std::shared_ptr<GechatUser> GechatUser::getPtr()//获得指向this的shared_ptr
{
    return shared_from_this();
}
//get Shared-from-this!
int GechatUser::numFriends() const
{
    return f_list.size();
}

void GechatUser::setUsername(string username)
{
    m_name=username;
}

bool GechatUser::haveFriend(shared_ptr<GechatUser> user)
{
    for(int i=0;i<f_list.vec.size();i++)
    {
        if(f_list.vec[i]==user)
        {
            return true;//????返回迭代器可以吗？ 这里如果直接返回迭代器it会报错 所有取内容然后取地址返回不会报错
        }
    }
    return false;
}

bool GechatUser::addFriend(shared_ptr<GechatUser> user)
{
    if(user!=nullptr)
    {
        return f_list.add(user);
    }
    else
    {
        return false;
    }
}

bool GechatUser::singleDelete(shared_ptr<GechatUser> user)
{
    if(user!=nullptr)
    {
        return f_list.erase(user);
    }
    else
    {
        return false;
    }
}

bool GechatUser::singleDelete(string username)
{
    for(int i=0;i<f_list.vec.size();i++)
    {
        if(f_list.vec[i]->m_name==username)
        {
            return f_list.erase(f_list.vec[i]);
        }
    }
    return false;
}

bool GechatUser::doubleDelete(shared_ptr<GechatUser> user)
{
    p1=getPtr();//获得指向this的shared_ptr

    if(user!=nullptr)
    {
        for (int i=0; i<user->f_list.vec.size(); i++)//用数组形式代替迭代器可以避免野指针，但erase后记得把i--；否则会跳过一个
        {
            if (user->f_list.vec[i] == p1)
            {
                user->f_list.vec.erase(user->f_list.vec.begin()+i);
                i--;
                user->f_list.size1--;
                break;
            }
        }
        //delete me from user's f_list;
        return f_list.erase(user);
        //delete user from my f_list;
    }
    else
    {
        return false;
    }
}

bool GechatUser::doubleDelete(string username)
{
    p1=getPtr();
    for(int i=0;i<f_list.vec.size();i++)
    {
        if(f_list.vec[i]->m_name==username)
        {
            f_list.vec[i]->f_list.erase(p1);
            break;
        }
    }
     //delete me from user's f_list;
    for(int i=0;i<f_list.vec.size();i++)
    {
        if(f_list.vec[i]->m_name==username)
        {
            return f_list.erase(f_list.vec[i]);
        }
    }
    return false;
    //delete user from my f_list;
}

string GechatUser::getName() const
{
    return m_name;
}
//运算符重载！！！！！！
bool GechatUser::operator< (const GechatUser user)
{
    return m_name < user.m_name;
}

bool GechatUser::operator== (const GechatUser& user) const//== operator 左值和右值必须都是const 否则no match for operator
{
    if(m_name== user.m_name)
        return true;
    else
        return false;
}

ostream & operator<< (ostream & out, GechatUser user)
{
    // print rational number on an output stream
    out << user.getName() << " (friends: " << user.numFriends() <<")";//写了friend 就不用GechatUser::
    return out;
}
