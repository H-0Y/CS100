//
//  lotterystation.cpp
//  HW6-2
//
//  Created by Apple on 2019/11/28.
//  Copyright © 2019 huangly. All rights reserved.
//

#include "lotterystation.h"
LotteryStation:: LotteryStation(){}
LotteryStation::~LotteryStation(){}
LotteryTicket* LotteryStation:: buy(CustomSet<int> numbers, int tickettype)//类型放在前面！！！！
{
    if(tickettype==LOTTO6)
    {
        LotteryTicket *a=new Lotto6Ticket(numbers, m_round);//基类指针指向子类的用法
        int n=1,p=1,q=0;
        for(int i = 0; i <numbers.size1-6; i++)
        {
            n= (numbers.size1-i)*n;
        }
        for(int i = 0; i <numbers.size1-6; i++)
        {
            p=p*(numbers.size1-6-i);
        }
        q=n/p;
        if(numbers.size1<6)
        {
            cout << "Failed.\n";
            return nullptr;
        }
        else
        {
            for(int i=0;i<numbers.size1;i++)
            {
                if(numbers.vec[i]<1||numbers.vec[i]>43)
                {
                    cout << "Failed.\n";
                    return nullptr;
                }
            }
            cout << "Bought a Lotto 6 ticket for "<< 2*q << " Yuan at round "<< m_round <<".\n";
            return a;
        }
    }
        
    else
    {
        LotteryTicket *a=new Lotto7Ticket(numbers, m_round);//基类指针指向子类
        int n=1,p=1,q=0;
        for(int i = 0; i <numbers.size1-7; i++)
        {
            n= (numbers.size1-i)*n;
        }
        for(int i = 0; i <numbers.size1-7; i++)
        {
            p=p*(numbers.size1-7-i);
        }
        q=n/p;
        if(numbers.size1<7)
        {
            cout << "Failed.\n";
            return nullptr;
        }
        else
        {
            for(int i=0;i<numbers.size1;i++)
            {
                if(numbers.vec[i]<1||numbers.vec[i]>30)
                {
                    cout << "Failed.\n";
                    return nullptr;
                }
            }
            cout << "Bought a Lotto 7 ticket for "<< 2*q << " Yuan at round "<< m_round <<".\n";
            return a;
        }
    }
}
void LotteryStation:: claimPrize(LotteryTicket* ticket)
{
    
    if(ticket!=nullptr)//考虑彩票Failede的开奖情况！！！！
    {
        if(ticket->getTicketType()==6)
        {
            cout << "This ticket wins " << ticket->claimPrize(prize6, m_round)<<" Yuan.\n";
            ticket->m_round=0;
//        if(ticket->getRound()==m_round)
//        {
//            int sum=0;
//            CustomSet<int> numbers;
//            pair<int, int> arr[ticket->getSize()];//存入彩票号码
//            for(int i=0;i<6;i++)
//            {
//                arr[i]=make_pair(1, ticket->m_numbers.vec[i]);
//            }
//            for(int i=6;i<ticket->getSize();i++)
//            {
//                arr[i]=make_pair(0, ticket->m_numbers.vec[i]);
//            }
//            int n=1,p=1,q=0;
//            for(int i = 0; i <ticket->getSize()-6; i++)
//            {
//                n= (ticket->getSize()-i)*n;
//            }
//            for(int i = 0; i <ticket->getSize()-6; i++)
//            {
//                p=p*(ticket->getSize()-6-i);
//            }
//            q=n/p;
//            for(int i=0;i<q;i++)
//            {
//                for(int j=0;j<ticket->getSize();j++)
//                {
//                    if(arr[j].first==1)
//                    {
//                        numbers.add(arr[j].second);
//                    }
//                }
//
//                LotteryTicket *a=new Lotto6Ticket(numbers, ticket->getRound());
//                sum += a->claimPrize(prize6, ticket->getRound());
//                delete a;
//                numbers.vec.clear();
//                numbers.size1=0;
//                for(int m=0;m<ticket->getSize();m++)
//                {
//                    if(arr[m].first==1&&arr[m+1].first==0)
//                    {
//                        arr[m].first=0;
//                        arr[m+1].first=1;
//                        int count1=0,count0=0;
//                        for(int u=0;u<m;u++)
//                        {
//                            if(arr[u].first==1)
//                            {
//                                count1++;
//                            }
//                            if(arr[u].first==0)
//                            {
//                                count0++;
//                            }
//                        }
//                        for(int x=0;x<count1;x++)
//                        {
//                            arr[x].first=1;
//                        }
//                        for(int y=count1;y<count1+count0;y++)
//                        {
//                            arr[y].first=0;
//                        }
//                        break;
//                    }
//                }
//            }
//            cout << "This ticket wins " << sum <<" Yuan.\n";
//        }
//        else
//            cout << "This ticket wins 0 Yuan.\n";
    
        }
        else
        {
//        if(ticket->getRound()==m_round)
//        {
//            int sum=0;
//            CustomSet<int> numbers;
//            pair<int, int> arr[ticket->getSize()];
//            for(int i=0;i<7;i++)
//            {
//                arr[i]=make_pair(1, ticket->m_numbers.vec[i]);
//            }
//            for(int i=7;i<ticket->getSize();i++)
//            {
//                arr[i]=make_pair(0, ticket->m_numbers.vec[i]);
//            }
//            int n=1,p=1,q=0;
//            for(int i = 0; i <ticket->getSize()-7; i++)
//            {
//                n= (ticket->getSize()-i)*n;
//            }
//            for(int i = 0; i <ticket->getSize()-7; i++)
//            {
//                p=p*(ticket->getSize()-7-i);
//            }
//            q=n/p;
//
//            for(int i=0;i<q;i++)
//            {
//                for(int j=0;j<ticket->getSize();j++)
//                {
//                    if(arr[j].first==1)
//                    {
//                       numbers.add(arr[j].second);
//                    }
//                }
//
//                LotteryTicket *a=new Lotto7Ticket(numbers, ticket->getRound());
//                sum += a->claimPrize(prize7, ticket->getRound());
//                delete a;
//                numbers.vec.clear();
//                numbers.size1=0;
//                for(int m=0;m<ticket->getSize();m++)
//                {
//                    if(arr[m].first==1&&arr[m+1].first==0)
//                    {
//                        arr[m].first=0;
//                        arr[m+1].first=1;
//                        int count1=0,count0=0;
//                        for(int u=0;u<m;u++)
//                        {
//                            if(arr[u].first==1)
//                            {
//                                count1++;
//                            }
//                            if(arr[u].first==0)
//                            {
//                                count0++;
//                            }
//                        }
//                        for(int x=0;x<count1;x++)
//                        {
//                            arr[x].first=1;
//                        }
//                        for(int y=count1;y<count1+count0;y++)
//                        {
//                            arr[y].first=0;
//                        }
//                        break;
//                    }
//                }
//            }
//             cout << "This ticket wins " << sum <<" Yuan.\n";
//        }
//        else
//            cout << "This ticket wins 0 Yuan.\n";
//    }
            cout << "This ticket wins " << ticket->claimPrize(prize7, m_round)<<" Yuan.\n";
            ticket->m_round=0;//claim的彩票不能再claim!!!!
        }
    }
    else
    {
        cout << "This ticket wins 0 Yuan.\n";
    }
}
void LotteryStation:: newRound()
{
    m_round++;
    prize6.vec.clear();
    prize7.vec.clear();
    int i=0,j=0;
    while(i<6)
    {
        if(prize6.add(randInt(1, 43)))//重置中奖号码！
        i++;
    }
    while(j<7)
    {
        if(prize7.add(randInt(1, 30)))//g复制代码时，要注意Lotto6和Lotto7区别
        j++;
    }
}

bool LotteryStation:: setPrizeNumbers(CustomSet<int> numbers, int tickettype)
{
    if(tickettype==6)
    {
        int b=0;
        for(int i=0;i<numbers.size1;i++)
        {
            if(numbers.vec[i]<1||numbers.vec[i]>43)
            {
                b=1;
            }
        }
        if(b==1)
        {
            return false;
        }
        else
        {
            prize6=numbers;
            return true;
        }
    }
    else
    {
        int b=0;
        for(int i=0;i<numbers.size1;i++)
        {
            if(numbers.vec[i]<1||numbers.vec[i]>30)
            {
                b=1;
            }
        }
        if(b==1)
        {
            return false;
        }
        else
        {
            prize7=numbers;
            return true;
        }
        
    }
    // This function simply serves for the purpose of:
    // Making it easier for you to debug, and also easier for us to check your results.
    // It sets the prize numbers of the type given as the "numbers".
    // "tickettype" is either LOTTO6 or LOTTO7 (predefined).
    // If "numbers" are invalid (not enough/out of bounds), do nothing and return false.
    // If succeeded, return true.
}
int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
        return rand() % (max - min + 1) + min;//产生一个1-43/30之间的数
}
