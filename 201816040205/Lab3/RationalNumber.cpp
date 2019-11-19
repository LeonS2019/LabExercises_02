// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n, int d)
{
    numerator=n;
    denominator=d;
    reduction();

} /* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */

// overloaded + operator
RationalNumber RationalNumber::operator+(RationalNumber &op)
{
    RationalNumber Add(this->numerator*op.denominator+ this->denominator*op.numerator,this->denominator*op.denominator );

    return Add;
}
/* Write definition for overloaded operator + */

// overloaded - operator
RationalNumber RationalNumber::operator-(RationalNumber &op)
{
   RationalNumber Sub(this->numerator*op.denominator-this->denominator*op.numerator,this->denominator*op.denominator);

   return Sub;
}
/* Write definition for overloaded operator - */

// overloaded * operator
RationalNumber RationalNumber::operator*(RationalNumber &op)
{
    RationalNumber Mul(this->numerator*op.numerator,this->denominator*op.denominator );

    return Mul;
}
/* Write definition for overloaded operator * */

// overloaded / operator
RationalNumber RationalNumber::operator/(RationalNumber &op)
{
    RationalNumber Div(this->numerator*op.denominator ,this->denominator*op.numerator );

    return Div;
}
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */

// overloaded > operator
bool RationalNumber::operator>(RationalNumber &op)
{
    if(this->numerator/this->denominator>op.numerator/op.denominator)
        return true;
    else
        return false;
}
/* Write definition for operator > */

// overloaded < operator
bool RationalNumber::operator<(RationalNumber &op)
{
    if(this->numerator/this->denominator<op.numerator/op.denominator)
        return true;
    else
        return false;
}
/* Write definition for operator < */

// overloaded >= operator
bool RationalNumber::operator>=(RationalNumber &op)
{
    if(this->numerator/this->denominator>=op.numerator/op.denominator)
        return true;
    else
        return false;
}
/* Write definition for operator >= */

// overloaded <= operator
bool RationalNumber::operator<=(RationalNumber &op)
{
    if(this->numerator/this->denominator<=op.numerator/op.denominator)
        return true;
    else
        return false;
}
/* Write definition for operator <= */

// overloaded == operator
bool RationalNumber::operator==(RationalNumber &op)
{
    if(this->numerator/this->denominator==op.numerator/op.denominator)
        return true;
    else
        return false;
}
/* Write definition for operator == */

// overloaded != operator
bool RationalNumber::operator!=(RationalNumber &op)
{
    if(this->numerator/this->denominator!=op.numerator/op.denominator)
        return true;
    else
        return false;
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
