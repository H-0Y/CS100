//
//  newton.hpp
//  HW8
//
//  Created by Apple on 2019/12/25.
//  Copyright © 2019 huangly. All rights reserved.
//

#ifndef NEWTON_HPP_
#define NEWTON_HPP_

#include <stdlib.h>
/*
 * This function finds the nearest root of a function by Newton's method.
 * f is a lambda function that's returned by any function in problem 2.
 * Starting from "startingPoint", you are to find a nearest root x_0, where
 * |x_0| < eps (0.000001 by default).
 */
template<typename T>
double findNearestRoot( T f, double startingPoint, double eps = 0.000001 ) {
    double y=f(startingPoint).first;
    double x=startingPoint;
    
    while(fabs(y)>=eps)
    {
        x=startingPoint-y/f(startingPoint).second;
        startingPoint=x;
        y=f(x).first;
    }
    return x;
}

#endif

