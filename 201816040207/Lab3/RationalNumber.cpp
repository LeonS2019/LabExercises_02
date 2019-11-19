
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
   RationalNumber::RationalNumber(int a,int b)
   {
       numerator=a;
       denominator=b;
       reduction();
   }

// overloaded + operator
/* Write definition for overloaded operator + */
     RationalNumber RationalNumber::operator+( RationalNumber &num)
    {
        RationalNumber result = *this;
        int a=this->denominator,b=this->numerator,c=num.denominator,d=num.numerator;

        if(this->denominator>num.denominator)
        {
            if(this->denominator%num.denominator==0)
            {
                num.denominator=num.denominator*(this->denominator/num.denominator);
                num.numerator=num.numerator*(this->denominator/num.denominator);
            }
            else
            {
                num.denominator=num.denominator*(this->denominator);
                num.numerator=num.numerator*(this->denominator);
                result.denominator=this->denominator*(num.denominator);
                result.numerator=this->numerator*(num.denominator);

            }
            result.numerator=this->numerator+num.numerator;
            reduction();
        }
        else if(this->denominator<num.denominator)
        {
            if(num.denominator%this->denominator==0)
            {
                result.denominator=this->denominator*(num.denominator/this->denominator);
                result.numerator=this->numerator*(num.denominator/this->denominator);
            }
            else
            {
                num.denominator=num.denominator*(this->denominator);
                num.numerator=num.numerator*(this->denominator);
                result.denominator=this->denominator*(num.denominator);
                result.numerator=this->numerator*(num.denominator);

            }
            result.numerator=this->numerator+num.numerator;
            reduction();
        }
        else
        {
            result.numerator=this->numerator+num.numerator;
            reduction();
        }
        this->denominator=a;
        this->numerator=b;
        num.denominator=c;
        num.numerator=d;
        result.reduction();
        return result;
    }
// overloaded - operator
/* Write definition for overloaded operator - */
     RationalNumber RationalNumber::operator-(RationalNumber &num)
    {
        RationalNumber result = *this;
        int a=this->denominator,b=this->numerator,c=num.denominator,d=num.numerator;

        if(this->denominator>num.denominator)
        {
            if(this->denominator%num.denominator==0)
            {
                num.denominator=num.denominator*(this->denominator/num.denominator);
                num.numerator=num.numerator*(this->denominator/num.denominator);
            }
            else
            {
                num.denominator=num.denominator*(this->denominator);
                num.numerator=num.numerator*(this->denominator);
                result.denominator=this->denominator*(num.denominator);
                result.numerator=this->numerator*(num.denominator);

            }
            result.numerator=this->numerator-num.numerator;
            reduction();
        }
        else if(this->denominator<num.denominator)
        {
            if(num.denominator%this->denominator==0)
            {
                result.denominator=this->denominator*(num.denominator/this->denominator);
                result.numerator=this->numerator*(num.denominator/this->denominator);
            }
            else
            {
                num.denominator=num.denominator*(this->denominator);
                num.numerator=num.numerator*(this->denominator);
                result.denominator=this->denominator*(num.denominator);
                result.numerator=this->numerator*(num.denominator);

            }
            result.numerator=this->numerator-num.numerator;
            reduction();
        }
        else
        {
            result.numerator=this->numerator-num.numerator;
            reduction();
        }
        this->denominator=a;
        this->numerator=b;
        num.denominator=c;
        num.numerator=d;
        result.reduction();
        return result;
    }
// overloaded * operator
/* Write definition for overloaded operator * */
    RationalNumber RationalNumber::operator*(RationalNumber &num)
    {
        RationalNumber result = *this;
        int a=this->denominator,b=this->numerator,c=num.denominator,d=num.numerator;

        result.numerator=this->numerator*num.numerator;
        result.denominator=this->denominator*num.denominator;
        reduction();
        this->denominator=a;
        this->numerator=b;
        result.reduction();
        return result;
    }
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
     RationalNumber RationalNumber::operator/( RationalNumber &num)
    {
        RationalNumber result = *this;
        int change;
        int a=this->denominator,b=this->numerator,c=num.denominator,d=num.numerator;

        change = num.denominator;
        num.denominator = num.numerator;
        num.numerator = change;


        result.numerator=this->numerator*num.numerator;
        result.denominator=this->denominator*num.denominator;
        reduction();
        num.denominator=c;
        num.numerator=d;
        this->denominator=a;
        this->numerator=b;
        result.reduction();
        return result;
    }
// overloaded > operator
/* Write definition for operator > */
    bool RationalNumber::operator>( RationalNumber &num)
    {
        int a,b;
        a= this->numerator*num.denominator;
        b= num.numerator*this->denominator;
        if(a>b)
            return true;
        else
            return false;
    }
// overloaded < operator
/* Write definition for operator < */
    bool RationalNumber::operator<( RationalNumber &num)
    {
        int a,b;
        a= this->numerator*num.denominator;
        b= num.numerator*this->denominator;
        if(a<b)
            return true;
        else
            return false;
    }
// overloaded >= operator
/* Write definition for operator >= */
    bool RationalNumber::operator>=( RationalNumber &num)
    {
       int a,b;
        a= this->numerator*num.denominator;
        b= num.numerator*this->denominator;
        if(a>b||a==b)
            return true;
        else
            return false;
    }
// overloaded <= operator
/* Write definition for operator <= */
    bool RationalNumber::operator<=( RationalNumber &num)
    {
        int a,b;
        a= this->numerator*num.denominator;
        b= num.numerator*this->denominator;
        if(a<b||a==b)
            return true;
        else
            return false;
    }
// overloaded == operator
/* Write definition for operator == */
    bool RationalNumber::operator==( RationalNumber &num)
    {
        int a,b;
        a= this->numerator*num.denominator;
        b= num.numerator*this->denominator;
        if(a==b)
            return true;
        else
            return false;
    }
// overloaded != operator
/* Write definition for operator != */
    bool RationalNumber::operator!=( RationalNumber &num)
    {
        int a,b;
        a= this->numerator*num.denominator;
        b= num.numerator*this->denominator;
        if(a==b)
            return false;
        else
            return true;
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
