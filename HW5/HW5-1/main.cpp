//
//  main.cpp
//  HW5-1
//
//  Created by Apple on 2019/10/27.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const int ERRORCODE = -1;

class DataAnalyser
{
public:
    DataAnalyser() {};
    virtual ~DataAnalyser() {};
    virtual float calculate(float* data, size_t size)
    {
        std::cout << "ERROR: Try to access virtual function which is in base class" << std::endl;
        return ERRORCODE;
    };
};


// MaximumAnalyser
class MaximumAnalyser : public DataAnalyser
{
    public:

        float calculate(float* data, size_t size)
        {
            float max=0;
            max = data[0];
            for(int i=1;i<size;i++)
            {
                if(max<data[i])
                    max=data[i];//应该用max与下一个data比较，而不是data和下一个data比较(排序才用)，min同理
            }
            return max;
        }
};

// MinimumAnalyser
class MinimumAnalyser : public DataAnalyser
{
public:
    
    float calculate(float* data, size_t size)
    {
        float min=0;
        min=data[0];
        for(int i=1;i<size;i++)//count算法用于字符串，不用于数组
        {
            if(min>data[i])
                min=data[i];
        }
        return min;
    }
};

// AverageAnalyser
class AverageAnalyser : public DataAnalyser
{
public:
    
    float calculate(float* data, size_t size)
    {
        float sum=0;
    
        for(int i=0;i<size;i++)
        {
            sum=sum+data[i];
        }
        return sum/size;
    }
};

// MedianAnalyser
class MedianAnalyser : public DataAnalyser
{
public:
    
    float calculate(float* data, size_t size)
    {
        float mdia=0,tem=0;
        for(int i=0;i<size;i++)
        {
            for(int j=1;j<size;j++)
            {
                if(data[j-1]>data[j])
                {
                  tem=data[j-1];
                  data[j-1]=data[j];
                  data[j]=tem;
                }
            }
        }
        if(size%2!=1)
            mdia=(data[size/2-1]+data[size/2])/2;
        
        else
            mdia=data[(size-1)/2];
        return mdia;
    }
};

// StdDevAnalyser
class StdDevAnalyser : public DataAnalyser
{
public:
    
    float calculate(float* data, size_t size)
    {
        float std=0,sum=0,sum1=0,avrg=0;
        for(int i=0;i<size;i++)
        {
            sum=sum+data[i];
        }
         avrg=sum/size;
        for(int i=0;i<size;i++)
        {
            sum1=sum1+pow(data[i]-avrg,2);
        }
        return std=pow(sum1/size,0.5);
    }

};

//////////////////////////////////////////////////////////////////////
///////////////// DO NOT SUBMIT THE FOLLOWING LINES //////////////////
//////////////////////////////////////////////////////////////////////
int main()
{
    float arr[] = {0.3, -100, 1, 2, 5, 6, 9, 12, 2};
    DataAnalyser* foo = new AverageAnalyser();  /* it can be any of the required 5 child classes */
         //子类仍属于父类类型！声明用父类名称                   //创建 类型* 指针=new 构造函数（）
    
    std::cout << foo->calculate(arr, 9) << std::endl; /* should be -100 in
                                                       this case */
    delete foo;
    return 0;
}
