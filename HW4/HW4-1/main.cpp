//
//  main.cpp
//  HW4
//
//  Created by Apple on 2019/10/19.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <iostream>

using namespace std;
class DynamicArray
{
    private:
    int capacity;
    int* data;
    int size;
    
    public:
        DynamicArray()
        {
            capacity=5;
            data=new int[capacity];
            size=0;
        }
        DynamicArray (const DynamicArray & other)//other 是一个该类的指针,且里面变量不能被改变
        {
            size = other.getSize();//this 能访问到自己的private
            capacity=5;
            data=new int[capacity];
            for(int i=0;i<other.getSize();i++)
            {
                data[i]=other.at(i);
                if(i==this->capacity-1)
                {
                    int data1[capacity];//data1应是一个静态数组，如果是int* data1=nullptr的话，类型就不清楚，就不是指向数组的指针
                    for(int p=0;p<capacity;p++)//直接用data1=data 的话两者地址相同，重新分配data会使data1也做同样变化
                    {
                        data1[p]=data[p];
                    }
                    delete[] data;
                    data=new int[capacity*2];
                    capacity=capacity*2;
                    for(int p=0;p<capacity/2;p++)
                    {
                        data[p]=data1[p];
                    }
                        //delete data1后哪怕是声明的全局data1 也会消失，再用需要重新声明
                    cout <<"(resize) from "<< capacity/2 <<" to "<< capacity<<endl;
                }
            }
        }
        ~DynamicArray ()
    {
        delete[] data;
    }
    void assign (const DynamicArray & other)
    {
        size = other.getSize();//this 能访问到自己的private
        for(int i=0;i<other.getSize();i++)
        {
            data[i]=other.at(i);
            if(i==this->capacity-1)
            {
                int data1[capacity];//data1应是一个静态数组，如果是int* data1=nullptr的话，类型就不清楚，就不是指向数组的指针
                for(int p=0;p<capacity;p++)//直接用data1=data 的话两者地址相同，重新分配data会使data1也做同样变化
                {
                    data1[p]=data[p];
                }
                delete[] data;
                data=new int[capacity*2];
                capacity=capacity*2;
                for(int p=0;p<capacity/2;p++)
                {
                    data[p]=data1[p];
                }
                //delete data1后哪怕是声明的全局data1 也会消失，再用需要重新声明
                cout <<"(resize) from "<< capacity/2 <<" to "<< capacity<<endl;
            }
        }
    }
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
    int at (int index) const
    {
        return data[index];
    }
    void push (const int item)
    {
        data[size]=item;
        size=size+1;
        if(size==this->capacity)
        {
            int data1[capacity+2];//data1应是一个静态数组，如果是int* data1 = nullptr的话，类型就不清楚，就不是指向数组的指针
            for(int p=0;p<capacity;p++)//直接用data1=data 的话两者地址相同，重新分配data会使data1也做同样变化！！！
            {
                data1[p]=data[p];
            }
            delete[] data;
            data=new int[capacity*2];
            capacity=capacity*2;
            for(int p=0;p<capacity/2;p++)
            {
                data[p]=data1[p];
            }
            cout <<"(resize) from "<< capacity/2 <<" to "<< capacity<<endl;//非“”中的空格，输出时没有
        }
    }
    bool remove (const int index)
    {
        if(0<=index<size)
        {
            if(index!=size-1)
            {
                for(int i=index;i<size-1;i++)
                {
                    data[i]=data[i+1];
                }
            }
            else
            {
                data[index]=NULL;
//                int data2[capacity];
//                for(int p=0;p<size;p++)//直接用int* data2(指向整数的指针）=data的话两者地址相同，重新分配data会使data1也做同样变化！！！
//                {
//                    data2[p]=data[p];
//                }
//                delete[] data;
//                data=new int[capacity];
//                for(int i=0;i<size-1;i++)
//                {
//                    data[i]=data2[i];
//                }
            }
            size--;
            return true;
        }
        else
            return false;
    }
};
int main() {
    DynamicArray *arr=new DynamicArray();
    DynamicArray *arr2=new DynamicArray(*arr);
    
    DynamicArray dynamicarray1;
    DynamicArray other;
    for(int i=0;i<=20;i++)
    {
        other.push (i);
    }
    dynamicarray1.assign(other);
    dynamicarray1.push(10);
    DynamicArray other1(dynamicarray1);
    dynamicarray1.at(21);

    return 0;
}

//自己写main函数debug!


