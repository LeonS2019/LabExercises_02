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
RationalNumber::RationalNumber(int numerat, int denominat)
{
	if (numerat > 0)   //分子
		numerator = numerat;
	else
		numerat = 1;
	if (denominat > 0)   //分母
		denominator = denominat;
	else
		denominat = 1;
	(*this).reduction();
}
// overloaded + operator
/* Write definition for overloaded operator + */
RationalNumber RationalNumber::operator + (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp.numerator = numerator * other.denominator + other.numerator * denominator;//求分子
	temp.denominator = denominator * other.denominator;
	temp.reduction();
	return temp;
}

	
// overloaded - operator
/* Write definition for overloaded operator - */
RationalNumber RationalNumber::operator - (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp.numerator = numerator * other.denominator - other.numerator * denominator;//求分子
	temp.denominator = denominator * other.denominator;
	temp.reduction();
		return temp;
}

// overloaded * operator
/* Write definition for overloaded operator * */
RationalNumber RationalNumber::operator * (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp.numerator = numerator * other.numerator;  //求分子
	temp.denominator = denominator * other.denominator;
	temp.reduction();
		return temp;
}
// overloaded / operator
/* Write definition for overloaded operator /. Check if the client is
   attempting to divide by zero and report an error message if so */
RationalNumber RationalNumber::operator / (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp.numerator =  numerator * other.denominator;//求分子
	temp.denominator = denominator * other.numerator;
	temp.reduction();
		return temp;
}
// overloaded > operator
/* Write definition for operator > */
bool RationalNumber::operator>(const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp = *this -other;
	if (temp.numerator == 0)
	{
		return false;
	}
	if (temp.denominator == 0)
	{
		throw out_of_range("denominator don't be 0");
	}
	int result = temp.numerator / temp.denominator;;
	if (result < 0)
	{
		return false;
	}else{
		return true;
	}
}
// overloaded < operator
/* Write definition for operator < */
bool RationalNumber::operator< (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp = *this - other;
	if (temp.numerator == 0)
	{
		return false;
	}
	int result = temp.numerator / temp.denominator;
	if (result < 0)
	{
		return true;
	}else
	{
	return false;
	}
}

// overloaded >= operator
/* Write definition for operator >= */
bool RationalNumber::operator >= (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp = *this - other;
	if (temp.numerator == 0)
	{
		return true;
	}
	int result = temp.numerator / temp.denominator;
	if (result <= 0)
	{
		return false;
	}else
	{
	return true;
	}
}
// overloaded <= operator
/* Write definition for operator <= */
bool RationalNumber::operator <= (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp = *this - other;
	if (temp.numerator == 0)
	{
		return true;
	}
	int result = temp.numerator / temp.denominator;
	if (result <= 0)
	{
		return true;
	}else
	{
	return false;
	}
}
// overloaded == operator
/* Write definition for operator == */
bool RationalNumber::operator == (const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp = *this - other;
	if (temp.numerator == 0)
	{
		return true;
	}
	return false;
}
// overloaded != operator
/* Write definition for operator != */
bool RationalNumber::operator !=(const RationalNumber other)
{
	RationalNumber temp(1, 1);
	temp = *this - other;
	if (temp.numerator == 0)
	{
		return false;
	}
	return true;
}
// function printRational definition
void RationalNumber::printRational() const
{
   if ( numerator == 0 ) 
      cout << numerator;
   else if ( denominator == 1 ) 
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
