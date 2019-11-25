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
RationalNumber::RationalNumber( int n, int d )
{
    if(d<=0)
    {
    d=1;
    cout<<"denominator must be greater than 0,denominator is be initialized to 1"<<endl<<endl;
    }
    numerator=n;
    denominator=d;
    reduction();
}
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator+(const RationalNumber &op2)
{
    numerator = numerator*op2.denominator + op2.numerator*denominator;
    denominator = denominator*op2.denominator;
    reduction();
    return *this;
}

// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator-(const RationalNumber &op2)
{
    numerator = numerator*op2.denominator - op2.numerator*denominator;
    denominator = denominator*op2.denominator;
    reduction();
    return *this;
}
// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator*(const RationalNumber &op2)
{
    numerator = numerator*op2.numerator;
    denominator = denominator*op2.denominator;
    reduction();
    return *this;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator/(const RationalNumber &op2)
{
    numerator = numerator*op2.denominator ;
    denominator = denominator*op2.numerator;
    reduction();
    return *this;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber &op2)
{
    return (*this<op2||*this==op2?false:true);
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator<(const RationalNumber &op2)
{
    return (numerator*op2.denominator<op2.numerator*denominator?true:false);
}
// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator>=(const RationalNumber &op2)
{
    return (*this<op2?false:true);
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator<=(const RationalNumber &op2)
{
    return (*this<op2||*this==op2?true:false);
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator==(const RationalNumber &op2)
{
    return (numerator*op2.denominator==op2.numerator*denominator?true:false);
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator!=(const RationalNumber &op2)
{
    return (*this==op2?false:true);
}

int RationalNumber::getNumerator()
{
    return numerator;
}

int RationalNumber::getDenominator()
{
    return denominator;
}

ostream &operator<<(ostream &output, RationalNumber &op2)
{
   if ( op2.getNumerator() == 0 ) // print fraction as zero
      output << op2.getNumerator();
   else if ( op2.getDenominator() == 1 ) // print fraction as integer
      output << op2.getNumerator();
   else
      output << op2.getNumerator() << '/' << op2.getDenominator();

   return output;
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
