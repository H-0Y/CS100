//
//  tickets.hpp
//  HW6-2
//
//  Created by Apple on 2019/11/28.
//  Copyright © 2019 huangly. All rights reserved.
//

#ifndef tickets_h
#define tickets_h
#include "customset.h"
#include <stdio.h>


class LotteryTicket
{
public:
    LotteryTicket();
    LotteryTicket(const CustomSet<int>& numbers, int round);
    virtual ~LotteryTicket()=0;
    
    int getRound();
    int getCost() const;
    virtual int getTicketType() = 0;
    void setCost(const int& cost);
    virtual int standPrize(const CustomSet<int>& prizeNumbers,CustomSet<int>& numbers) = 0;
    virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round) = 0;
    int getSize();
    
//protected:
    CustomSet<int> m_numbers;
    int m_round; // The valid round of a ticket. An outdated ticket is invalid.
    int m_cost; // The amount of money spent on this ticket.
};

class Lotto7Ticket: public LotteryTicket
{
public:
    Lotto7Ticket(const CustomSet<int>& numbers, int round);
    ~Lotto7Ticket();
    int getTicketType();
    int standPrize(const CustomSet<int>& prizeNumbers,CustomSet<int>& numbers);
    int claimPrize(const CustomSet<int>& prizeNumbers, int round);
};

class Lotto6Ticket: public LotteryTicket
{
public:
    Lotto6Ticket(const CustomSet<int>& numbers, int round);
    ~Lotto6Ticket();
    int getTicketType();
    int standPrize(const CustomSet<int>& prizeNumbers,CustomSet<int>& numbers);
    int claimPrize(const CustomSet<int>& prizeNumbers, int round);
};
#endif /* tickets_hpp */
