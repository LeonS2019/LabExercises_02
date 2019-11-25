// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber( int n , int d )
{
    if( d<=0 )
    {
        d=1;
    }
    if( n<0 )
    {
        n=1;
    }
    numerator = n;
    denominator = d;
    this->reduction();
}
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */

// overloaded + operator
RationalNumber RationalNumber::operator+( const RationalNumber &right )
{
    RationalNumber b;
    b.numerator = numerator*right.denominator + denominator*right.numerator;
    b.denominator = denominator*right.denominator;
    b.reduction();
    return b;
}
/* Write definition for overloaded operator + */

// overloaded - operator
RationalNumber RationalNumber::operator-( const RationalNumber &right )
{
    RationalNumber b;
    b.numerator = numerator*right.denominator - denominator*right.numerator;
    b.denominator = denominator*right.denominator;
    b.reduction();
    return b;
}
/* Write definition for overloaded operator - */

// overloaded * operator
RationalNumber RationalNumber::operator*( const RationalNumber &right )
{
    RationalNumber b;
    b.numerator = numerator*right.numerator;
    b.denominator = denominator*right.denominator;
    b.reduction();
    return b;
}
/* Write definition for overloaded operator * */

// overloaded / operator
RationalNumber RationalNumber::operator/( const RationalNumber &right )
{
    RationalNumber b;
    if( right.numerator==0 )
    {
        throw invalid_argument ("the zero can't be divided");
    }
    else
    {
        b.numerator = numerator*right.denominator;
        b.denominator = denominator*right.numerator;
        b.reduction();
        return b;
    }
}
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */

// overloaded > operator
bool RationalNumber::operator>( const RationalNumber &right )
{
    if( numerator*right.denominator>denominator*right.numerator )
        return true;
    else
        return false;
}
/* Write definition for operator > */

// overloaded < operator
bool RationalNumber::operator<( const RationalNumber &right )
{
    if( numerator*right.denominator<denominator*right.numerator )
        return true;
    else
        return false;
}
/* Write definition for operator < */

// overloaded >= operator
bool RationalNumber::operator>=( const RationalNumber &right )
{
    return !( *this<right );
}
/* Write definition for operator >= */

// overloaded <= operator
bool RationalNumber::operator<=( const RationalNumber &right )
{
    return !( *this>right );
}
/* Write definition for operator <= */

// overloaded == operator
bool RationalNumber::operator==( const RationalNumber &right )
{
    if( numerator*right.denominator==denominator*right.numerator )
        return true;
    else
        return false;
}
/* Write definition for operator == */

// overloaded != operator
bool RationalNumber::operator!=( const RationalNumber &right )
{
    return !( *this==right );
}
/* Write definition for operator != */

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

ostream &operator<<( ostream &output , const RationalNumber &right )
{
    if ( right.numerator == 0 ) // print fraction as zero
      output << right.numerator;
   else if ( right.denominator == 1 ) // print fraction as integer
      output << right.numerator;
   else
      output << right.numerator << '/' << right.denominator;

    return output;
}
