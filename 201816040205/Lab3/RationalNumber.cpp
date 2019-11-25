// Lab 3: RationalNumber.cpp
// RationalNumber member-function definitions.
#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

#include "RationalNumber.h"

// RationalNumber constructor sets n and d and calls reduction
RationalNumber::RationalNumber(int n, int d)
{

    numerator=n;
    denominator=d;
    reduction();
    test();


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
/*void RationalNumber::printRational() const
{
   if ( numerator == 0 ) // print fraction as zero
      cout << numerator;
   else if ( denominator == 1 ) // print fraction as integer
      cout << numerator;
   else
      cout << numerator << '/' << denominator;
} // end function printRational*/
ostream& operator<<(ostream &output, RationalNumber &t)
{
    if ( t.numerator == 0 ) // print fraction as zero
      cout << t.numerator;
   else if ( t.denominator == 1 ) // print fraction as integer
      cout << t.numerator;
   else
      cout << t.numerator << '/' << t.denominator;
}

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

void RationalNumber::test()
{
    if(denominator==0)
    {
        cout<<"Error:denominator CAN'T be 0!"<<endl;
        exit(0);
    }


}


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
