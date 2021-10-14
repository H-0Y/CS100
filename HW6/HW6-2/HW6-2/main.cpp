//
//  main.cpp
//  HW6-2
//
//  Created by Apple on 2019/11/28.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <iostream>

#include "lotterystation.h"

//int main()
//{
//    int a[6] = { 1,2,3,4,5,6 };
//    CustomSet<int> foo(a, 6);
//    LotteryStation sample;
//    sample.newRound();
//    sample.setPrizeNumbers(foo, LOTTO6);
//    LotteryTicket* jackpot = sample.buy(foo, LOTTO6);
//    sample.claimPrize(jackpot);
//}
// LOTTO6 is predefined LotteryTicket* jackpot = sample.buy(foo, LOTTO6);
//int main()
//{
//    int a[8] = { 2, 7, 16, 21, 30, 23 ,3,24};
//    int b[7] = { 2, 7, 16, 21, 22, 23 ,2};
//    CustomSet<int> foo(a, 8);
//    CustomSet<int> foo1(b, 7);
//    LotteryStation sample;
//    sample.newRound();
//    sample.setPrizeNumbers(foo1, LOTTO7);
//    LotteryTicket* jackpot = sample.buy(foo, LOTTO7);
//    sample.claimPrize(jackpot);
//    sample.newRound();
//}
int main()
{
    int a[9] = { 1,2,4,7,9,12,13,14,15 };
    int b[7] = { 1,2,3,4,5,6,7 };
    int c[7] = { 2, 7, 16, 21, 30, 29, 18 };
    int d[6] = { 2, 7, 16, 21, 22, 23 };
    int e[6] = { 2, 7, 16, 21, 30, 29 };
    CustomSet<int> c_a(a, 9);
    CustomSet<int> c_b(b, 7);
    CustomSet<int> c_c(c, 7);
    CustomSet<int> c_d(d, 6);
    CustomSet<int> c_e(e, 6);
    LotteryTicket* t_a = new Lotto7Ticket(c_a, 0);
    LotteryTicket* t_b = new Lotto6Ticket(c_c, 0);
    int earn_1, earn_2;
    earn_1 = t_a->claimPrize(c_b, 0);
    earn_2 = t_b->claimPrize(c_d, 0);
    cout << earn_1 << endl;
    cout << earn_2 << endl;
    cout << endl;
    //test tickets

    LotteryStation s_a;

    s_a.newRound();
    s_a.setPrizeNumbers(c_d, 6);
    LotteryTicket* t_c = s_a.buy(c_c, 6);
    s_a.claimPrize(t_c);
    cout << endl;
    //test station lotto6 round 1 --normal situation

    s_a.newRound();
    s_a.setPrizeNumbers(c_b, 7);
    LotteryTicket* t_d = s_a.buy(c_a, 7);
    s_a.claimPrize(t_d);
    cout << endl;
    //test station lotto7 round 2 --normal situation

    s_a.newRound();
    s_a.setPrizeNumbers(c_c, 7);
    LotteryTicket* t_e = s_a.buy(c_b, 7);
    s_a.claimPrize(t_e);
    cout << endl;
    //test station lotto7 round 3 --normal situation

    int f[7] = { 2, 7, 16, 21, 30, 37, 0 };
    CustomSet<int> c_f(f, 9);
    s_a.newRound();
    s_a.setPrizeNumbers(c_c, 7);
    LotteryTicket* t_f = s_a.buy(c_f, 7);
    s_a.claimPrize(t_f);
    cout << endl;
    //test station lotto7 round 4  --out of range

    s_a.newRound();
    s_a.setPrizeNumbers(c_c, 7);
    LotteryTicket* t_g = s_a.buy(c_c, 7);
    s_a.claimPrize(t_g);
    cout << endl;
    //test station lotto7 round 5  --less of number of prizenumbers
    // judge the setPrizeNumbers is true , then get a ticket c_c for prize c_c

    s_a.newRound();
    s_a.setPrizeNumbers(c_b, 7);
    LotteryTicket* t_h = s_a.buy(c_d, 7);
    s_a.claimPrize(t_h);
    cout << endl;
    //test station lotto7 round 6   --less of number of tickets

    s_a.newRound();
    s_a.setPrizeNumbers(c_d, 6);
    LotteryTicket* t_i = s_a.buy(c_e, 6);
    s_a.claimPrize(t_i);
    s_a.claimPrize(t_i);
    cout << endl;
    //test station lotto6 round 7   --claim a ticket that has been claimed 严谨啊！！！！！

    s_a.newRound();
    s_a.setPrizeNumbers(c_d, 6);
    LotteryTicket* t_j = s_a.buy(c_a, 6);
    s_a.claimPrize(t_j);
    LotteryTicket* t_k = s_a.buy(c_e, 6);
    s_a.claimPrize(t_k);
    cout << endl;
    //test station lotto6 round 8   --two operation in one round

    LotteryTicket* t_l = s_a.buy(c_e, 6);
    s_a.newRound();
    s_a.claimPrize(t_l);
    cout << endl;
//    test station lotto6 round 9   --the round isn't correct
    return 0;
}
