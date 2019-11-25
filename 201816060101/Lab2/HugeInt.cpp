// Lab 2: Hugeint.cpp 
// HugeInt member-function and friend-function definitions.
#include <iostream>
#include <cctype> // isdigit function prototype
#include <cstring> // strlen function prototype
using namespace std;

#include "Hugeint.h" // HugeInt class definition

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value )
{
   // initialize array to zero
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;   

   // place digits of argument into array 
   for ( int j = 29; value != 0 && j >= 0; j-- )
   {
      integer[ j ] = value % 10;
      value /= 10;
   } // end for
   for (int i = 29; i >= 1; i--) {
	   if (integer[i] < 0) {
		   integer[i] += 10;
		   integer[i - 1]--;
	   }
   }
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string 
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const char *string )
{
   // initialize array to zero
   for ( int i = 0; i <= 29; i++ )
      integer[ i ] = 0;

   // place digits of argument into array
   int length = strlen( string );

   for ( int j = 30 - length, k = 0; j <= 29; j++, k++ )

      if ( isdigit( string[ k ] ) )
         integer[ j ] = string[ k ] - '0';

} // end HugeInt conversion constructor

// get function calculates length of integer
int HugeInt::getLength() const
{
	int i;
   for ( i = 0; i <= 29; i++ )
      if ( integer[ i ] != 0 )
         break; // break when first digit is reached
   
   return 30 - i; // length is from first digit (at i) to end of array
} // end function getLength

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const
{
   HugeInt temp; // temporary result
   int carry = 0;

   for ( int i = 29; i >= 0; i-- )
   {
      temp.integer[ i ] = 
         integer[ i ] + op2.integer[ i ] + carry;

      // determine whether to carry a 1
      if ( temp.integer[ i ] > 9 )
      {
         temp.integer[ i ] %= 10;  // reduce to 0-9
         carry = 1;
      } // end if
      else // no carry 
         carry = 0;
   } // end for

   return temp; // return copy of temporary object
} // end function operator+

HugeInt HugeInt::operator-(const HugeInt & b) const
{
	HugeInt c;
	int f = 0;
	if (*this < b) {
		f = 1;
		for (int i = 0; i < 30; i++) c.integer[i] = b.integer[i] - integer[i];
		for (int i = 29; i >= 1; i--) {
			if (c.integer[i] < 0) {
				c.integer[i] += 10;
				c.integer[i - 1]--;
			}
		}
		int i = 0;
		while (i < 30 && c.integer[i] == 0) i++;
		if (i < 30) c.integer[i] *= -1;
	}
	else {
		for (int i = 0; i < 30; i++) {
			c.integer[i] = integer[i] - b.integer[i];
		}
		for (int i = 29; i >= 1; i--) {
			if (c.integer[i] < 0) {
				c.integer[i] += 10;
				c.integer[i - 1]--;
			}
		}
	}
	return c;
}

// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{ 
   // convert op2 to a HugeInt, then invoke 
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 ); 
} // end function operator+

HugeInt HugeInt::operator-(int b) const
{
	return *this + -b;
}

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const char *op2 ) const 
{ 
   // convert op2 to a HugeInt, then invoke 
   // operator+ for two HugeInt objects
   return *this + HugeInt( op2 ); 
} // end function operator+

HugeInt HugeInt::operator-(const char *b) const
{
	return *this - HugeInt(b);
}

// equality operator; HugeInt == HugeInt
/* Write a definition for the == operator */
bool HugeInt::operator==(const HugeInt b) const
{
	for (int i = 0; i < 30; i++) {
		if (integer[i] != b.integer[i]) return 0;
	}
	return 1;
}


// inequality operator; HugeInt != HugeInt
/* Write a definition for the != operator
   by calling the == operator */
bool HugeInt::operator!=(const HugeInt b) const
{
	return !(*this == b);
}


// less than operator; HugeInt < HugeInt
/* Write a definition for the < operator */
bool HugeInt::operator<(const HugeInt b) const
{
	for (int i = 0; i < 30; i++) {
		if (integer[i] < b.integer[i]) return 1;
		if (integer[i] > b.integer[i]) return 0;
	}
	return 0;
}


// less than or equal operator; HugeInt <= HugeInt
/* Write a definition for the <= operator
   by calling the < and == operators */
bool HugeInt::operator<=(const HugeInt b) const
{
	return *this < b || *this == b;
}


// greater than operator; HugeInt > HugeInt
/* Write a definition for the > operator
   by calling the <= operator */
bool HugeInt::operator>(const HugeInt b) const
{
	return !(*this <= b);
}

// greater than or equal operator; HugeInt >= HugeInt
/* Write a definition for the >= operator
   by calling the > and == operators */
bool HugeInt::operator>=(const HugeInt b) const
{
	return *this > b || *this == b;
}

// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num )
{
   int i;

   for ( i = 0; ( num.integer[ i ] == 0 ) && ( i <= 29 ); i++ )
      ; // skip leading zeros

   if ( i == 30 )
      output << 0;
   else

      for ( ; i <= 29; i++ )
         output << num.integer[ i ];

   return output;
} // end function operator<<


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
