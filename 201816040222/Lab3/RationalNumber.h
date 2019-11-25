#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber::RationalNumber(int a, int b)
{
    numerator=a;
    denominator=b;
}
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber &right ) const
{
    RationalNumber temp;
    temp.denominator = denominator*right.denominator;
    temp.numerator = right.denominator*numerator + denominator*right.numerator;
    temp.reduction();
    return temp;
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &right ) const
{
    RationalNumber temp;
    temp.denominator = denominator*right.denominator;
    temp.numerator = right.denominator*numerator - denominator*right.numerator;
    temp.reduction();
    return temp;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &right ) const
{
    RationalNumber temp;
    temp.denominator = denominator*right.denominator;
    temp.numerator = numerator*right.numerator;
    temp.reduction();
    return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &right ) const
{
    RationalNumber temp;
    temp.denominator = denominator * right.numerator;
    temp.numerator = numerator * right.denominator ;
    temp.reduction();
    return temp;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber &right) const
{
    if (numerator * right.denominator-denominator * right.numerator>0)
        return true;
    else
        return false;
}

// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber &right) const
{
    if (numerator * right.denominator-denominator * right.numerator<0)
        return true;
    else
        return false;
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber &right) const
{
    if (numerator * right.denominator-denominator * right.numerator>=0)
        return true;
    else
        return false;
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber &right) const
{
    if (numerator * right.denominator-denominator * right.numerator<=0)
        return true;
    else
        return false;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber &right) const
{
    if (numerator * right.denominator-denominator * right.numerator==0)
        return true;
    else
        return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber &right) const
{
    if (numerator * right.denominator-denominator * right.numerator!=0)
        return true;
    else
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

