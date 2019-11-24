// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber ::RationalNumber( int n , int d )
{
    if( d <= 0)
        d = 1;
    numerator = n;
    denominator = d;
    reduction();
}

// overloaded + operator
RationalNumber RationalNumber::operator+( const RationalNumber &op2) const
{
    RationalNumber temp;
    temp.numerator = numerator * op2.denominator + op2.numerator * denominator;
    temp.denominator = denominator * op2.denominator;
    temp.reduction();
    return temp;
}

// overloaded - operator
RationalNumber RationalNumber::operator-( const RationalNumber &op2) const
{
    RationalNumber temp;
    temp.numerator = numerator * op2.denominator - op2.numerator * denominator;
    temp.denominator = denominator * op2.denominator;
    temp.reduction();
    return temp;
}

// overloaded * operator
RationalNumber RationalNumber::operator*( const RationalNumber &op2) const
{
    RationalNumber temp;
    temp.numerator = numerator * op2.numerator;
    temp.denominator = denominator * op2.denominator;
    temp.reduction();
    return temp;
}

// overloaded / operator
RationalNumber RationalNumber::operator/( const RationalNumber &op2) const
{
    RationalNumber temp;
    if( op2.numerator == 0)
        throw invalid_argument( "Divisor cannot be zero !   ");
    else
    {
        temp.numerator = numerator * op2.denominator;
        temp.denominator = denominator * op2.numerator;
        temp.reduction();
    }
    return temp;
}

// overloaded > operator
bool RationalNumber::operator>( const RationalNumber &op2) const
{
    return ( numerator *op2.denominator > denominator * op2.numerator ) ? true : false ;
}

// overloaded < operator
bool RationalNumber::operator<( const RationalNumber &op2) const
{
    return ( numerator *op2.denominator < denominator * op2.numerator ) ? true : false ;
}

// overloaded >= operator
bool RationalNumber::operator>=( const RationalNumber &op2) const
{
    return ( numerator *op2.denominator >= denominator * op2.numerator ) ? true : false ;
}

// overloaded <= operator
bool RationalNumber::operator<=( const RationalNumber &op2) const
{
    return ( numerator *op2.denominator <= denominator * op2.numerator ) ? true : false ;
}

// overloaded == operator
bool RationalNumber::operator==( const RationalNumber &op2) const
{
    return ( numerator *op2.denominator == denominator * op2.numerator ) ? true : false ;
}

// overloaded != operator
bool RationalNumber::operator!=( const RationalNumber &op2) const
{
    return ( numerator *op2.denominator != denominator * op2.numerator ) ? true : false ;
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

// overloaded << operator
ostream &operator<<( ostream & output, const RationalNumber &rat )
{
   if ( rat.numerator == 0 ) // print fraction as zero
      output << rat.numerator;
   else if ( rat.denominator == 1 ) // print fraction as integer
      output << rat.numerator;
   else
      output << rat.numerator << '/' << rat.denominator;
   return output;
}// end function operator<<
