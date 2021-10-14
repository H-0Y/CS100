//
//  main.cpp
//  HW5-2
//
//  Created by Apple on 2019/10/27.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ReportParser
{
public:
    ReportParser(int numStudents, int numInfos);
    ~ReportParser();
    void readReport();
    int length(int i);
    int min(int c);
    void writeStructuredReport(int sortOption);
    // Add your own functions and variables here
private:
    int n,m;
    vector<string> vec;
    // Add your own functions and variables here
};

ReportParser::ReportParser(int numStudents, int numInfos)
{
    n=numStudents;
    m=numInfos;// Your code here.
}

ReportParser::~ReportParser()
{
    
    // Your code here
}


void ReportParser::readReport()
{
    for(int i=0;i<n*m;i++)
    {
        string tem;
        cin >> tem;
        vec.push_back(tem);
    }
}

int ReportParser::length(int c)
{
    int max=vec[c].size();
    for(int i=0;i<n-1;i++)
    {
        if(max<vec[(i+1)*m+c].size())//应该用max与下一个进行比较；否则（0:1，1:2....)一旦中间跳了一个之后，将不再是max在与下一个进行比较,注意！！！！！！！！！你已经翻了两次这样的错误了！
        {
            max=vec[(i+1)*m+c].size();
        }
    }
    return max;
}
int ReportParser::min(int c)
{
    int min=vec[c].size();
    for(int i=0;i<n-1;i++)
    {
        if(vec[i*m+c].size()>vec[(i+1)*m+c].size())
        {
            min=vec[(i+1)*m+c].size();
        }
    }
    return min;
}
void ReportParser::writeStructuredReport(int sortOption)
{
    // 排序

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
        if(vec[(j-1)*m+sortOption]>vec[j*m+sortOption])// 如果是string (*str[j])[1]
        {
            for(int p=0;p<m;p++)
                {
                    string tem0;
                    tem0=vec[(j-1)*m+p];
                    vec[(j-1)*m+p]=vec[(j-1)*m+m+p];
                    vec[(j-1)*m+m+p]=tem0;
                }
        }
    }
}
    
    cout << "/";
    int l1=0;
    for(int i=0;i<m;i++)
    {
        l1=l1+length(i);
    }
    for(int i=0;i<l1+m*2+m-1;i++)
        cout <<"-";
    cout <<"\\"<< endl;
   
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            
            if(j==m-1)
            {
                cout << "|" << " " << vec[i*m+j];
                int len=vec[i*m+j].size();
                for(int p=0;p<length(m-1)+1-len;p++)
                {
                    cout << " ";
                }
                cout << "|" << endl;
                if(i!=n-1)
                {
                    for(int o=0;o<m;o++)
                    {
                        if(o==m-1)
                        {
                            cout << "|";
                            for(int i=0;i<length(m-1)+2;i++)
                                cout <<"-";
                            cout << "|" << endl;

                        }
                        else
                        {
                            cout << "|" ;
                            for(int i=0;i<length(o)+2;i++)
                                cout <<"-";
                        }
                    }
                }
            }
            else
            {
                cout << "|" <<" " << vec[i*m+j];
                int len=vec[i*m+j].size();
                for(int p=0;p<length(j)-len+1;p++)
                {
                    cout << " ";
                }
            }
        }
    }
    cout << "\\";
    for(int i=0;i<l1+m*2+m-1;i++)
        cout <<"-";
    cout <<"/"<< endl;
   
}

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    int m, n, sortOption;
    std::cin >> m >> n >> sortOption;
    getchar();
    ReportParser p(n, m);
    p.readReport();
    p.writeStructuredReport(sortOption);
    return 0;
}
//Umi 20 aa 43
//Honoka 43253 65789 87912
//Kotori 1.7 foo 44
//Sfs 662 asad rqqq
//Agfd 962 safas 223
//Zasf 498 asd rte
