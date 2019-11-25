// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n,int d )//n为分子，d为分母
{
    numerator=n;

    if(d==0)
    {
        d=1;
        denominator=d;
    }
    else
        denominator=d;
reduction();
}
/* Implement the RationalNumber constructor. Validate d first to ensure that
   it is a positive number and set it to 1 if not. Call the reduction utility
   function at the end */
RationalNumber RationalNumber::operator+(const RationalNumber &rhs)
{// overloaded + operator

    int a=numerator;
    int b=denominator;
    int c=rhs.numerator;
    int d=rhs.denominator;
    return RationalNumber(a*b+c*d,b*d);reduction();
}
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator-(const RationalNumber &rhs)
{
    int a=numerator;
    int b=denominator;
    int c=rhs.numerator;
    int d=rhs.denominator;
    return RationalNumber(a*b-c*d,b*d);
}
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator*(const RationalNumber &rhs)
{
    int a=numerator;
    int b=denominator;
    int c=rhs.numerator;
    int d=rhs.denominator;
    return RationalNumber(a*c,b*d);
}
RationalNumber RationalNumber::operator/(const RationalNumber &rhs)
{
    int a=numerator;
    int b=denominator;
    int c=rhs.numerator;
    int d=rhs.denominator;
    /*if(b=0||d=0)
    {
        cout<<"error"<<endl;
    }
    else*/
    return RationalNumber(a*c,b*d);
}
// overloaded * operator
/* Write definition for overloaded operator * */

// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
bool RationalNumber::operator>(const RationalNumber &rhs)
{
    if(numerator*rhs.denominator>numerator*rhs.numerator)
        return false;
    else
        return true;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator<(const RationalNumber &rhs)
{
    if(numerator*rhs.denominator<numerator*rhs.numerator)
        return false;
    else
        return true;
}

// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator>=(const RationalNumber &rhs)
{
    if(numerator*rhs.denominator>numerator*rhs.numerator)
        return true;
        if(numerator*rhs.denominator==numerator*rhs.numerator)
            return true;
    else
        return false;
}

// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator<=(const RationalNumber &rhs)
{
     if(numerator*rhs.denominator<numerator*rhs.numerator)
        return true;
        if(numerator*rhs.denominator==numerator*rhs.numerator)
            return true;
    else
        return false;
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator==(const RationalNumber &rhs)
{
    if(numerator*rhs.denominator==numerator*rhs.numerator)
        return true;
    else
        return false;
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator!=(const RationalNumber &rhs)
{
    if(numerator*rhs.denominator==numerator*rhs.numerator)
        return false;
    else
    return true;
}
// overloaded != operator
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


/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
