//
//  Poly.hpp
//  HW8
//
//  Created by Apple on 2019/12/22.
//  Copyright © 2019 huangly. All rights reserved.
//

#ifndef POLY_HPP_
#define POLY_HPP_

#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

template<typename T>
class Poly {
public:
    T max(T a, T b) const//for循环时尺寸应去取最大值！
    {
        if(a>b)
            return a;
        else
            return b;
    }
    /* Default constructor */
    Poly()
    {}
    
    /* Constructor for a poly that's a constant number */
    Poly( T constant )
    {
        _coeffs.push_back(constant);
    }
    
    /* Given a vector of coefficients */
    Poly( const std::vector<T> & coeffs )
    {
        _coeffs.assign(coeffs.begin(),coeffs.end()); //v1.assign(v2.begin(), v2.end())
        // For vector, we can't straightly use "="
    }
    
    /* Given an rvalue reference of a vector of coefficients */
    Poly( std::vector<T> && coeffs )
    {
        _coeffs.assign(coeffs.begin(),coeffs.end());
    }
    
    /* Given an array of coefficients with size of the array*/
    Poly( T * coeffs, size_t numberCoeffs )
    {
        for(int i=0;i<numberCoeffs;i++)
        {
            _coeffs.push_back(coeffs[i]);
        }
    }
    
    /* Given an initializer_list */
    Poly( std::initializer_list<T> coeffs )
    {
        _coeffs.assign(coeffs.begin(),coeffs.end());//容器之间的相互赋值
    }
    
    virtual ~Poly()
    {}
    
    /* Copying constructor */
    Poly( const Poly<T> & poly )
    {
        _coeffs.assign(poly._coeffs.begin(),poly._coeffs.end());//cancel "private"
    }
    
    /* Copying constructor with rvalue reference */
    Poly( Poly<T> && poly )
    {
        _coeffs.assign(poly._coeffs.begin(),poly._coeffs.end());
    }
    
    /* Assignment operator */
    Poly<T>& operator=( const Poly<T> & poly )
    {
        _coeffs.assign(poly._coeffs.begin(),poly._coeffs.end());
        //Attention! It's *this instead of this!
        return *this;
    }
    
    /* Assignment operator with rvalue reference */
    Poly<T>& operator=( Poly<T> && poly )
    {
        _coeffs.assign(poly._coeffs.begin(),poly._coeffs.end());
        return *this;                                                  //Attention! It's *this instead of this!
    }
    
    /*
     * Below are operations of polynomials.
     * They are quite self-explanatory.
     */
    
    Poly<T> operator+( const Poly<T> & rhs ) const
    {
        Poly<T> tem;
        for(int i=0;i<max(_coeffs.size(),rhs._coeffs.size());i++)
        {
            if(_coeffs.size()>rhs._coeffs.size())
            {
                if(i>=rhs._coeffs.size())
                    tem._coeffs.push_back(_coeffs[i]);
                else
                    tem._coeffs.push_back(_coeffs[i]+rhs._coeffs[i]);
            }
            else
            {
                if(i>=_coeffs.size())
                    tem._coeffs.push_back(rhs._coeffs[i]);
                else
                    tem._coeffs.push_back(_coeffs[i]+rhs._coeffs[i]);
            }
        }
        return tem;
    }
    Poly<T> operator-( const Poly<T> & rhs ) const
    {
        Poly<T> tem;
        for(int i=0;i<max(_coeffs.size(),rhs._coeffs.size());i++)
        {
            if(_coeffs.size()>rhs._coeffs.size())
            {
                if(i>=rhs._coeffs.size())
                    tem._coeffs.push_back(_coeffs[i]);
                else
                    tem._coeffs.push_back(_coeffs[i]-rhs._coeffs[i]);
            }
            else
            {
                if(i>=_coeffs.size())
                    tem._coeffs.push_back(-rhs._coeffs[i]);
                else
                    tem._coeffs.push_back(_coeffs[i]-rhs._coeffs[i]);
            }
        }
        return tem;
    }
    Poly<T> operator*( const Poly<T> & rhs ) const
    {
        Poly<T> sum;
        for(int i=0;i<max(_coeffs.size(),rhs._coeffs.size());i++)
        {
            
            if(_coeffs.size()>rhs._coeffs.size())
            {
                Poly<T> tem;
                for(int p=0;p<i;p++)
                {
                    tem._coeffs.push_back(0);
                }
                for(int j=0;j<rhs._coeffs.size();j++)
                {
                    tem._coeffs.push_back(rhs._coeffs[j]*_coeffs[i]);
                }
                sum+=tem;
            }
            else
            {
                Poly<T> tem;
                for(int p=0;p<i;p++)
                {
                    tem._coeffs.push_back(0);
                }
                for(int j=0;j<_coeffs.size();j++)
                {
                    tem._coeffs.push_back(rhs._coeffs[i]*_coeffs[j]);
                }
                sum+=tem;
            }
        }
        return sum;
    }
    
    Poly<T> & operator+=( const Poly<T> & rhs )
    {
        for(int i=0;i<max(_coeffs.size(),rhs._coeffs.size());i++)
        {
            if(_coeffs.size()>rhs._coeffs.size())
            {
                if(i>=rhs._coeffs.size())
                {

                }
                else
                    _coeffs[i]=(_coeffs[i]+rhs._coeffs[i]);
            }
            else
            {
                if(i>=_coeffs.size())
                    _coeffs.push_back(rhs._coeffs[i]);
                else
                    _coeffs[i]=(_coeffs[i]+rhs._coeffs[i]);
            }
        }
        return *this;//Attention! It's *this instead of this!
    }
    Poly<T> & operator-=( const Poly<T> & rhs )
    {
        for(int i=0;i<max(_coeffs.size(),rhs._coeffs.size());i++)
        {
            if(_coeffs.size()>rhs._coeffs.size())
            {
                if(i>=rhs._coeffs.size())
                {
                    
                }
                else
                    _coeffs[i]=(_coeffs[i]-rhs._coeffs[i]);
            }
            else
            {
                if(i>=_coeffs.size())
                    _coeffs.push_back(-rhs._coeffs[i]);
                else
                    _coeffs[i]=(_coeffs[i]-rhs._coeffs[i]);
            }
        }
        return *this;//Attention! It's *this instead of this!
    }
    Poly<T> & operator*=( const Poly<T> & rhs )
    {
        Poly<T> sum;
        for(int i=0;i<max(_coeffs.size(),rhs._coeffs.size());i++)
        {
            
            if(_coeffs.size()>rhs._coeffs.size())
            {
                Poly<T> tem;
                for(int p=0;p<i;p++)
                {
                    tem._coeffs.push_back(0);
                }
                for(int j=0;j<rhs._coeffs.size();j++)
                {
                    tem._coeffs.push_back(rhs._coeffs[j]*_coeffs[i]);
                }
                sum+=tem;                                            //不可以直接改变*this值！
                                                                    //但可以通过改变*this里的变量间接达到改变*this的目的，从而完成*=的重载。
            }
            else
            {
                Poly<T> tem;
                for(int p=0;p<i;p++)
                {
                    tem._coeffs.push_back(0);
                }
                for(int j=0;j<_coeffs.size();j++)
                {
                    tem._coeffs.push_back(rhs._coeffs[i]*_coeffs[j]);
                }
                sum+=tem;                                                 //不可以直接改变*this值！
            }
        }
        _coeffs.assign(sum._coeffs.begin(),sum._coeffs.end());
        return *this;//Attention! It's *this instead of this!
    }
    
    /*
     * This function evaluates the polynomial at "param",
     * and returns the value of evaluation.
     * For example, evaluating x+3 at param=7 gives 10.
     */
    T eval( T param ) const
    {
        T sum=0;
        for(int i=floor(_coeffs.size())-1;i>=0;i--)////////////////////////////////////////
        {
            if(i!=0)
                sum+=_coeffs[i]*pow(param,i);// 幂函数pow，而不是power
            else
                sum+=_coeffs[i];//_coeffs[i] 是它的系数 param才是它的值
        }
        return sum;
    }
    
    /*
     * This function takes the derivative of the polynomial,
     * and returns a new polynomial of its derivative.
     * For example, calling this function for x^2
     * will return a polynomial 2x.
     */
    Poly<T> der() const
    {
        Poly<T> tem;
        for(int i=0;i<_coeffs.size()-1;i++)
        {
            tem._coeffs.push_back((i+1)*_coeffs[i+1]);
        }
        return tem;
    }
    
    /*
     * This function returns a pair of:
     * 1. the value (evaluation) of the polynomial at "param".
     * 2. the value of the first-order derivative of the polynomial at "param".
     * For example, calling this operator for x^2-2x at "param"=4
     * will return (8, 6).
     */
    std::pair<T,T> operator()( T param ) const
    {
        //Poly( const Poly<T> & poly )
        Poly tem(*this);//this is a pointer!!! remember to add a *
        pair<T, T> p;
        p=make_pair(tem.eval(param),tem.der().eval(param));
        return p;
    }
    

    std::vector<T> _coeffs;
};


#endif
