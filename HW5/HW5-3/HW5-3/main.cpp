//
//  main.cpp
//  HW5-3
//
//  Created by Apple on 2019/11/5.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class LookupTable
{
public:
    // constructor, start: start position; end: end position; increment: the increment "dx"
    // You should calculate the value in range [start, end], with increment "increment"
    LookupTable(double start, double end, double increment);
    // virtual destructor
    virtual ~LookupTable() = 0;
    // get the value f(x) of the given x
    virtual double getValue(double x) = 0;
    //oj里不会主动调用除了他给的函数的其他函数，所以不能写需要main里调用的在其他函数
protected:
    double s=0,e=0,d=0,x;
    
    vector<double> vec1;
    vector<double> vec2;
};

LookupTable::LookupTable(double start, double end, double increment)
{
    this->s=start;
    this->e=end;
    this->d=increment;
}
LookupTable::~LookupTable(){};//纯虚函数也是需要{},否则会报错没有定义

class SquareLookupTable : public LookupTable
{
    
public:
    SquareLookupTable(double start, double end, double increment) : LookupTable(start, end, increment){};//父类只有带参构造函数时子类必须显式地调用父类构造函数，显式调用时两个括号里6个参数都是形参，第二个括号里3参数类型在之前就被声明
    ~SquareLookupTable(){};
    
    double getValue(double x)
    {
        for(double i=s;i<e+d;i=i+d)//?????????
        {
            vec1.push_back(i);
            double a=i*i;
            vec2.push_back(a);
        }
        if(x<s||x>e)
        {
            return 0;
        }
        else
        {
            vector<double>::iterator v ;
            v=std::find(vec1.begin(),vec1.end(),x);
            
            if(v!=vec1.end())
            {
                return vec2[(x-s)/d];
            }
            else
            {
                return  ((x-vec1[floor((x-s)/d)])*vec2[ceil((x-s)/d)]+(vec1[ceil((x-s)/d)]-x)*vec2[floor((x-s)/d)])/(vec1[ceil((x-s)/d)]-vec1[floor((x-s)/d)]);
            }
        }
    }
    // Your code here.
};

class SinLookupTable : public LookupTable
{
    
public:
    SinLookupTable(double start, double end, double increment) : LookupTable(start, end, increment){};
    ~SinLookupTable(){};
   
    double getValue(double x)
    {
        for(double i=s;i<e+d;i=i+d)
        {
            vec1.push_back(i);
            vec2.push_back(sin(i));
        }
        if(x>e||x<s)
        {
            return 0;
        }
        else
        {
            vector<double>::iterator v ;
            v=std::find(vec1.begin(),vec1.end(),x);
            
            if(v!=vec1.end())
            {
                return vec2[(x-s)/d];
            }
            else
            {
                return  ((x-vec1[floor((x-s)/d)])*vec2[ceil((x-s)/d)]+(vec1[ceil((x-s)/d)]-x)*vec2[floor((x-s)/d)])/(vec1[ceil((x-s)/d)]-vec1[floor((x-s)/d)]);
            }
        }
    }
    // Your code here.
};

class LogLookupTable : public LookupTable
{
    
public:
    LogLookupTable(double start, double end, double increment) : LookupTable(start, end, increment){};//父类只有带参构造函数时子类必须显式地调用父类构造函数，显式调用时两个括号里6个参数都是形参，第二个括号里3参数类型在之前就被声明
    ~LogLookupTable(){};
   
    double getValue(double x)
    {
        for(double i=s;i<e+d;i=i+d)
        {
            vec1.push_back(i);
            vec2.push_back(log(i));
        }
        if(x>e||x<s)
        {
            return 0;
        }
        else
        {
            vector<double>::iterator v ;
            v=std::find(vec1.begin(),vec1.end(),x);
            
            if(v!=vec1.end())
            {
                return vec2[(x-s)/d];
            }
            else
            {
                return  ((x-vec1[floor((x-s)/d)])*vec2[ceil((x-s)/d)]+(vec1[ceil((x-s)/d)]-x)*vec2[floor((x-s)/d)])/(vec1[ceil((x-s)/d)]-vec1[floor((x-s)/d)]);
            }
        }
        
    }
    // Your code here.
};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    double x,s,e,d;
    cin >> x >> s >> e >>d ;
    LookupTable* table;
    SquareLookupTable square(s,e,d);//这里有参数，子类构造函数时也必须有参数
    table=&square;
    cout << table->getValue(x) <<endl;
    // Your code here.
    return 0;
}
