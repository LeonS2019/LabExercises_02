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
RationalNumber::RationalNumber( int n,int d)
{
    numerator=n;
   if(d>0)
   {
       denominator=d;

   }
   else
   {
       denominator=1;
   }
   reduction();
}

// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber &right)
{

    return RationalNumber(numerator*right.denominator+denominator*right.numerator,denominator*right.denominator);
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &right)
{


    return RationalNumber(numerator*right.denominator-denominator*right.numerator,denominator*right.denominator);
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &right)
{

    return RationalNumber(numerator*right.numerator,denominator*right.denominator);
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &right)
{


    return RationalNumber(numerator*right.denominator, denominator*right.numerator);
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber &right)
{
  if(numerator*right.denominator>right.numerator*denominator)
  {
      return 1;
  }

  else
  {
      return 0;
  }


}
// overloaded < operator
/* Write definition for operator < */
bool  RationalNumber::operator<(const RationalNumber &right)
{
    if(numerator*right.denominator<right.numerator*denominator)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// overloaded >= operator
/* Write definition for operator >= */
bool  RationalNumber::operator>=(const RationalNumber &right)
{
    return !(numerator<right.numerator);
}
// overloaded <= operator
/* Write definition for operator <= */
bool  RationalNumber::operator<=(const RationalNumber &right)
{
    return !(numerator>right.numerator);
}
// overloaded == operator
/* Write definition for operator == */
bool  RationalNumber::operator==(const RationalNumber &right)
{
    if(numerator==right.numerator)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// overloaded != operator
/* Write definition for operator != */
bool  RationalNumber::operator!=(const RationalNumber &right)
{
    return !(numerator==right.numerator);
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
