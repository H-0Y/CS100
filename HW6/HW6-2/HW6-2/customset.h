//
//  customset.h
//  HW6-2
//
//  Created by Apple on 2019/11/28.
//  Copyright © 2019 huangly. All rights reserved.
//

//
//  Header.h
//  HW6-1
//
//  Created by Apple on 2019/11/23.
//  Copyright © 2019 huangly. All rights reserved.
//
#pragma once 
#ifndef customset_h
#define customset_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <random>
#include <time.h>
#include <algorithm>

// Predefined constants for problem 2.
#define LOTTO6 6
#define LOTTO7 7

using namespace std;


/*****************************************************************\
 |                            Problem 1                            |
 \*****************************************************************/
template <typename T>
class CustomSet
{
public:
    // Constructors and destructor:
    CustomSet(){};//默认构造函数写法！必须要写！！！
    // Default constructor
    
    CustomSet(const CustomSet& other)
    {
        vec.assign(other.vec.begin(),other.vec.end());
        size1=other.size1;
    }
    // Copy constructor. Should construct a copy of "other".
    
    CustomSet(T arr[], int size)
    {
        //去重算法
        sort(arr,arr+size,less<int>());//按从小到大的顺序
        int n=floor(unique(arr,arr+size)-arr);
        
        size1=n;
        for(int i=0;i<size1;i++)
        {
            vec.push_back(arr[i]);
        }
    }
    // Constructor using an array.
    // Note that if there are duplicates in the array, you should ignore them.
    // And then the size of your "CustomSet" will be different from the "size" given!
    
    ~CustomSet(){};//默认析构函数写法
    // Destructor. Pay attention to memory leaks!
    
    // Other member functions:
    int size() const//const放在前面返回值不能改，放在后面->只读函数，其中数据成员不能改
    {
        return size1;
    }
    // Returns the size of the set.
    
    bool add(const T& item)
    {
        if(vec.size()==0)
        {
            vec.push_back(item);
            size1++;
            return true;
        }
        else
        {
            for (int i=0; i<vec.size(); i++)// 注意vec.size()==0时就不执行！！！！！
            {
                if (vec[i] == item)
                {
                    return false;
                }
                if(i==vec.size()-1)
                {
                    vec.push_back(item);
                    size1++;
                    return true;
                }
            }
        }
        return true;
        
    }
    
    // If "item" is already in the set, return false.
    // Otherwise, add it to the set and return true.
    
    T* find(const T& item)
    {   //如果你想直接告诉编译器T::iterator是类型而不是变量，只需用typename修饰：
        for(typename vector<T>::iterator it = vec.begin(); it!= vec.end();it++)
        {
            if(*it==item)
            {
                return &(*it);//????返回迭代器可以吗？ 这里如果直接返回迭代器it会报错 所有取内容然后取地址返回不会报错
            }
            if(it==vec.end()-1)
                return nullptr;
        }
    }
    // If an object in the set equals "item", return a pointer to it.
    // If "item" is not found, return nullptr(NULL).
    
    bool erase(const T& item)
    {
        for (int i=0; i<vec.size(); i++)//用数组形式代替迭代器可以避免野指针，但erase后记得把i--；否则会跳过一个
        {
            if (vec[i] == item)
            {
                vec.erase(vec.begin()+i);
                i--;
                size1--;
                return true;
            }
            if(i==vec.size()-1)
                return false;
        }
        return false;
    }
    // If "item" is not in the set, return false.
    // Otherwise, erase it from the set and return true.
    
    CustomSet intersection(const CustomSet& other)
    {
        CustomSet t;
        for (int i=0; i<this->size(); i++)
        {
            //            cout << vec[i]<<endl;
            for (int j=0; j<other.vec.size(); j++)
            {
                //                cout <<other.vec[j] << endl;
                if(vec[i]==other.vec[j])
                {
                    //                    cout<< "ha!"<<endl;
                    t.add(vec[i]);
                }
            }
        }
        return t;
    }
    // This function returns the intersection of two sets (*this and other).
    // In other words, the set of all objects that is in both *this and other.
    // If there is no intersection, just return an empty set.
    
    void sortSet()
    {
        sort(vec.begin(),vec.end());
    }
    // This function sorts the objects in the set in ascending order.
    // Directly using (std::)sort is enough, if you are using an STL container.
    
    void printSet()
    {
        cout << "{";
        
        for(int i=0;i<vec.size();i++)
        {
            if(i!=vec.size()-1)
                cout << vec[i] << ", ";
            else
                cout << vec[i] << "}\n";
        }
    }
    // This function prints the set, seperating elements by { , , , }.
    // It's safe to assume that it supports operator<< of ostream (cout).
    // For example, Assume you've added 2, 4, -2, and 800 to the set, in this order.
    // This function will print: "{2, 4, -2, 800}\n"
    // Note that there are spaces between a comma(,) and the next object.
    // Print a newline at the end. (indicated by the '\n' above)
    
    // Operators:
    CustomSet operator+ (const T& item)
    {
        CustomSet c;
        c.vec.assign(vec.begin(),vec.end());
        c.size1=size1;
        c.add(item);
        return c;
    }
    CustomSet operator+ (const CustomSet& that)
    {
        CustomSet c;
        c.vec.assign(vec.begin(),vec.end());
        c.size1=size1;
        for(int i=0;i<that.size1;i++)
        {
            c.add(that.vec[i]);
        }
        return c;
    }
    CustomSet& operator+= (const T& item)
    {
        CustomSet &c=*this;
        c.erase(item);
        return c;
    }
    CustomSet& operator+= (const CustomSet& that)
    {
        CustomSet &c=*this;
        for(int i=0;i<that.size1;i++)
        {
            c.add(that.vec[i]);
        }
        return c;
    }
    // The operator+ and operator += are overloaded.
    // They can be understood intuitively, or consider this:
    // A set "plus" an item means adding in the item.
    // A set "plus" a set means taking the union of two sets.
    // However, the difference between + and += is not written here.
    // Try to figure out on your own!
    
    CustomSet operator- (const T& item)
    {
        CustomSet c;//需要调用默认构造函数！！！！！
        c.vec.assign(vec.begin(),vec.end());
        c.size1=size1;
        c.erase(item);
        return c;
    }
    CustomSet operator- (const CustomSet& that)
    {
        CustomSet c;
        c.vec.assign(vec.begin(),vec.end());
        c.size1=size1;
        for(int i=0;i<that.size1;i++)
        {
            c.erase(that.vec[i]);
        }
        return c;
    }
    
    CustomSet& operator-= (const T& item)
    {
        CustomSet &c=*this;
        c.erase(item);
        return c;
    }
    CustomSet& operator-= (const CustomSet& that)
    {
        CustomSet &c=*this;
        for(int i=0;i<that.size1;i++)
        {
            c.erase(that.vec[i]);
        }
        return c;
    }
    // The operator- and operator -= are overloaded.
    // They can be undrstood intuitively, or consider this:
    // A set "minus" an item means erasing the item.
    // A set A "minus" a set B means subtracting B from A, or namely, A\B.
    // However, the difference between - and -= is not written here.
    // Try to figure out on your own!
    
    
    CustomSet<std::pair<T, T>> operator* (const CustomSet& that)//通过CustomSet<std::pair<T, T>>这样的声明，把c中vec里类型改为pair
    {
        CustomSet<std::pair<T, T>> c;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<that.vec.size();j++)
            {
                pair <T,T> a;
                a.first=vec[i];
                a.second=that.vec[j];
                c.add(a);
            }
        }
        return c;
    }
    // This function returns the Cartesian product of two sets (*this and that).
    // The Cartesian product of two sets is the set of all ordered pairs that satisfy:
    //        The first element of the ordered pair belongs to first set (*this);
    //        The second element of the ordered pair belongs the second set (that).
    // The (std::)pair (in header <utility>) helps representing the object in it.
    // If you have any question with Cartesian products or std::pair, just look up on Internet!
    vector<T> vec;
    int size1=0;//vec.size()再变 size1z不再变
};



#endif
