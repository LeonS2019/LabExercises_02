// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
 RationalNumber::RationalNumber(int n,int m)
 {
     numerator=n;
     if(m<=0)
     {
         denominator=1;
     }
     else
        denominator=m;
     reduction();
 }
 RationalNumber RationalNumber::operator+(const RationalNumber& p)
 {
     RationalNumber x;
     int otherm;
      if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
     otherm=this->denominator*p.denominator;
     x.numerator=p.denominator*this->numerator+p.numerator*this->denominator;
     x.denominator=otherm;
     x.reduction();
     return x;
 }
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator-(const RationalNumber&p)
{
     RationalNumber x;
     int otherm;
     otherm=this->denominator*p.denominator;
     x.numerator=p.denominator*this->numerator-p.numerator*this->denominator;
     x.denominator=otherm;
     x.reduction();
     return x;
    }
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator*(const RationalNumber&p)
{
    RationalNumber x;
    int otherm,othern;
     if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    otherm=denominator*p.denominator;
    othern=numerator*p.numerator;
    x.denominator=otherm;
    x.numerator=othern;
    x.reduction();
    return x;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator/(const RationalNumber&p)
{
    RationalNumber x;
    int otherm,othern;
    if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    otherm=denominator*p.numerator;
    othern=numerator*p.denominator;
    x.denominator=otherm;
    x.numerator=othern;
    x.reduction();
    return x;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber&p)
{
     if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    if(this->numerator/this->denominator>p.numerator/p.denominator)
    {
        return true;
    }
    return false;
}

// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber&p)
{
     if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    if(this->numerator/this->denominator<p.numerator/p.denominator)
    {
        return true;
    }
    return false;
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber&p)
{
     if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    if(this->numerator/this->denominator>=p.numerator/p.denominator)
    {
        return true;
    }
    return false;
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber&p)
{
     if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    if(this->numerator/this->denominator<=p.numerator/p.denominator)
    {
        return true;
    }
    return false;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber&p)
{
     if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    if(this->numerator/this->denominator==p.numerator/p.denominator)
    {
        return true;
    }
    return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber&p)
{
     if(denominator==0)
    {
        throw invalid_argument("denominator can't be 0");
    }
    if(this->numerator/this->denominator!=p.numerator/p.denominator)
    {
        return true;
    }
    return false;
}
// function printRational definition
void RationalNumber::printRational() const
{
    if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
    else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
    else
      cout << numerator << '/' << denominator;
} // end function printRational

// function reduction definition
void RationalNumber::reduction()
{
   int largest, gcd = 1;  // greatest common divisor;

   largest = ( numerator > denominator ) ? numerator: denominator;

   for ( int loop = 2; loop <= largest; loop++ )
       if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

   numerator /= gcd;
   denominator /= gcd;
} // end function reduction



