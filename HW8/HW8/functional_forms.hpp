//
//  functional_forms.hpp
//  HW8
//
//  Created by Apple on 2019/12/23.
//  Copyright © 2019 huangly. All rights reserved.
//

#ifndef FUNCTIONAL_FORMS_HPP_
#define FUNCTIONAL_FORMS_HPP_
#include <stdlib.h>
#include <math.h>


//捕获[]中=必须加，且不能写->pair！



/* For all lambda functions below, if you are not clear how they work, please refer to the given example for details. */


/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1+f2)(m) as first, and (d(f1+f2)/dx)(m) as second.
 */
auto derSum = []( auto f1, auto f2 ){
    return [=](auto m){pair<double,double> p;p.first=f1(m).first+f2(m).first;p.second=f1(m).second+f2(m).second;return p;};             //lambda闭包
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1-f2)(m) as first, and (d(f1-f2)/dx)(m) as second.
 */
auto derSub = []( auto f1, auto f2 ){
    return [=](auto m){pair<double,double> p;p.first=f1(m).first-f2(m).first;p.second=f1(m).second-f2(m).second;return p;};
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1*f2)(m) as first, and (d(f1*f2)/dx)(m) as second.
 */
auto derMul = []( auto f1, auto f2 ){
    return [=](auto m){pair<double,double> p;p.first=f1(m).first*f2(m).first;p.second=f1(m).second*f2(m).first+f1(m).first*f2(m).second;return p;};
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1/f2)(m) as first, and (d(f1/f2)/dx)(m) as second.
 */
auto derDiv = []( auto f1, auto f2 ){
    return [=](auto m){pair<double,double> p;p.first=f1(m).first/f2(m).first;p.second=(f1(m).second*f2(m).first-f1(m).first*f2(m).second)/(f2(m).first*f2(m).first);return p;};
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has (f1(f2))(m) as first, and (d(f1(f2))/dx)(m) as second.
 */
auto derComp = []( auto f1, auto f2 ){
    return [=](auto m){pair<double,double> p;p.first=f1(f2(m).first).first;p.second=f1(f2(m).first).second*f2(m).second;return p;};
};

/*
 * Return a lambda function that takes one parameter (m) and returns a pair<double, double> that:
 * has [(f1)(m)]^exp as first, and (d(f1^exp)/dx)(m) as second.
 */
auto derPow = []( auto f, int exp ) {
    return [=](auto m){pair<double,double> p;p.first=pow(f(m).first,exp);p.second=exp*pow(f(m).first,exp-1)*f(m).second;return p;};
};

#endif

