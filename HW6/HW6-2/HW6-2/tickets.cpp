//
//  ticket.cpp
//  HW6-2
//
//  Created by Apple on 2019/11/28.
//  Copyright © 2019 huangly. All rights reserved.
//

#include "tickets.h"


LotteryTicket::LotteryTicket(){}
LotteryTicket::LotteryTicket(const CustomSet<int>& numbers, int round)
{
    m_numbers=numbers;
    m_round=round;
}
LotteryTicket::~LotteryTicket(){}//纯虚函数也是需要{},否则会报错没有定义
int LotteryTicket::getRound()
{
    return m_round;
}

int LotteryTicket::getCost() const
{
    return m_cost;
}
void LotteryTicket::setCost(const int& cost)
{
    m_cost=cost;
}
int LotteryTicket::getSize()
{
    return m_numbers.size();
}
//-----------------------------------------

Lotto7Ticket::Lotto7Ticket(const CustomSet<int>& numbers, int round)
{
    m_numbers=numbers;
    m_round=round;
}

Lotto7Ticket::~Lotto7Ticket(){}

int Lotto7Ticket::getTicketType()
{
    return LOTTO7;
}

int Lotto7Ticket::standPrize(const CustomSet<int>& prizeNumbers,CustomSet<int>& numbers)
{
    CustomSet<int> T;
    T=numbers.intersection(prizeNumbers);
    if(T.size()<=3)
    {
        return 0;
    }
    else if(T.size()==4)
    {
        return 5;
    }
    else if(T.size()==5)
    {
        return 75;
    }
    else if(T.size()==6)
    {
        return 4500;
    }
    else
    {
        return 2000000;
    }
}
int Lotto7Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round)
{
    if(round==m_round)
    {
        int sum=0;
        CustomSet<int> numbers;//储存标准彩票号码
        pair<int, int> arr[m_numbers.size()];
        for(int i=0;i<7;i++)
        {
            arr[i]=make_pair(1, m_numbers.vec[i]);
        }
        for(int i=7;i<m_numbers.size();i++)
        {
            arr[i]=make_pair(0, m_numbers.vec[i]);
        }
        int n=1,p=1,q=0;
        for(int i = 0; i <m_numbers.size()-7; i++)
        {
            n= (m_numbers.size()-i)*n;
        }
        for(int i = 0; i <m_numbers.size()-7; i++)
        {
            p=p*(m_numbers.size()-7-i);
        }
        q=n/p;
        
        for(int i=0;i<q;i++)
        {
            for(int j=0;j<m_numbers.size();j++)
            {
                if(arr[j].first==1)
                {
                    numbers.add(arr[j].second);
                }
            }
            
            LotteryTicket *a=new Lotto7Ticket(numbers, round);
            sum += a->standPrize(prizeNumbers, numbers);
            delete a;
            numbers.vec.clear();
            numbers.size1=0;
            for(int m=0;m<m_numbers.size();m++)
            {
                if(arr[m].first==1&&arr[m+1].first==0)
                {
                    arr[m].first=0;
                    arr[m+1].first=1;
                    int count1=0,count0=0;
                    for(int u=0;u<m;u++)
                    {
                        if(arr[u].first==1)
                        {
                            count1++;
                        }
                        if(arr[u].first==0)
                        {
                            count0++;
                        }
                    }
                    for(int x=0;x<count1;x++)
                    {
                        arr[x].first=1;
                    }
                    for(int y=count1;y<m;y++)
                    {
                        arr[y].first=0;
                    }
                    break;
                }
            }
        }
      
        return sum;
    }
    
    else
        return 0;
}
//-------------------------------------------------------
Lotto6Ticket::Lotto6Ticket(const CustomSet<int>& numbers, int round)
{
    m_numbers=numbers;
    m_round=round;
}

Lotto6Ticket::~Lotto6Ticket(){}

int Lotto6Ticket::getTicketType()
{
    return LOTTO6;
}

int Lotto6Ticket:: standPrize(const CustomSet<int>& prizeNumbers,CustomSet<int>& numbers)
{
    CustomSet<int> T;
    T=numbers.intersection(prizeNumbers);
    if(T.size()<3)//删去了m_round=round；
    {
        return 0;
    }
    else if(T.size()==3)
    {
        return 5;
    }
    else if(T.size()==4)
    {
        return 75;
    }
    else if(T.size()==5)
    {
        return 4500;
    }
    else
    {
        return 2000000;
    }
}
int Lotto6Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round)
{
    if(round==m_round)
    {
        int sum=0;
        CustomSet<int> numbers;//储存标准彩票号码
        pair<int, int> arr[m_numbers.size()];
        for(int i=0;i<6;i++)
        {
            arr[i]=make_pair(1, m_numbers.vec[i]);
        }
        for(int i=6;i<m_numbers.size();i++)
        {
            arr[i]=make_pair(0, m_numbers.vec[i]);
        }
        int n=1,p=1,q=0;
        for(int i = 0; i <m_numbers.size()-6; i++)
        {
            n= (m_numbers.size()-i)*n;
        }
        for(int i = 0; i <m_numbers.size()-6; i++)
        {
            p=p*(m_numbers.size()-6-i);
        }
        q=n/p;
        
        for(int i=0;i<q;i++)
        {
            for(int j=0;j<m_numbers.size();j++)
            {
                if(arr[j].first==1)
                {
                    numbers.add(arr[j].second);
                }
            }
            
            LotteryTicket *a=new Lotto6Ticket(numbers, round);
            sum += a->standPrize(prizeNumbers, numbers);
            delete a;
            numbers.vec.clear();
            numbers.size1=0;
            for(int m=0;m<m_numbers.size();m++)
            {
                if(arr[m].first==1&&arr[m+1].first==0)
                {
                    arr[m].first=0;
                    arr[m+1].first=1;
                    int count1=0,count0=0;
                    for(int u=0;u<m;u++)
                    {
                        if(arr[u].first==1)
                        {
                            count1++;
                        }
                        if(arr[u].first==0)
                        {
                            count0++;
                        }
                    }
                    for(int x=0;x<count1;x++)
                    {
                        arr[x].first=1;
                    }
                    for(int y=count1;y<count1+count0;y++)
                    {
                        arr[y].first=0;
                    }
                    break;
                }
            }
        }
        return sum;
    }
    
    else
        return 0;
}
