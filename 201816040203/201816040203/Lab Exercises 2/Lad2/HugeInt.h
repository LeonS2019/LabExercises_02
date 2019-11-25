// Lab 2: Hugeint.h
// HugeInt class definition.
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
using namespace std;

class HugeInt
{
   friend ostream &operator<<( ostream &, const HugeInt & );
public:
   HugeInt( long = 0 ); // conversion/default constructor
   HugeInt( const char * ); // conversion constructor

   // addition operator; HugeInt + HugeInt
   HugeInt operator+( const HugeInt & ) const;

   // addition operator; HugeInt + int
   HugeInt operator+( int ) const;

   // addition operator;

   // HugeInt + string that represents large integer value
   HugeInt operator+( const char * ) const;

   /* Write prototypes for the six relational and equality operators */
   HugeInt operator-(int)const;
   HugeInt operator-(const HugeInt &)const;
   bool operator==(HugeInt&);
   bool operator!=(HugeInt&);
   bool operator<(HugeInt&);
   bool operator<=(HugeInt&);
   bool operator>(HugeInt&);
   bool operator>=(HugeInt&);
   int getLength() const;
   int i;
private:
   short integer[ 30 ];
}; // end class HugeInt

#endif

