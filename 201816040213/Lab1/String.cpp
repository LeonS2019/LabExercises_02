// Lab 1: String.cpp
// Member-function definitions for String.cpp
#include <iostream>
using namespace std;

#include <cstring> // strcpy and strcat prototypes
#include "String.h" // String class definition

// conversion constructor: convert a char * to String
String::String( const char * const zPtr )
{
   length = strlen( zPtr ); // compute length
   sPtr = new char[ length + 1 ]; // allocate storage
   assert( sPtr != 0 ); // terminate if memory not allocated
   strcpy( sPtr, zPtr ); // copy literal to object
} // end String conversion constructor

// copy constructor
String::String( const String &copy )
{
   length = copy.length; // copy length
   sPtr = new char[ length + 1 ]; // allocate storage
   assert( sPtr != 0 ); // ensure memory allocated
   strcpy( sPtr, copy.sPtr ); // copy string
} // end String copy constructor

// destructor
String::~String()
{
   delete [] sPtr; // reclaim string
} // end destructor

// overloaded = operator; avoids self assignment
const String &String::operator=( const String &right )
{
   if ( &right != this ) // avoid self assignment
   {
      delete [] sPtr; // prevents memory leak
      length = right.length; // new String length
      sPtr = new char[ length + 1 ]; // allocate memory
      assert( sPtr != 0 ); // ensure memory allocated
      strcpy( sPtr, right.sPtr ); // copy string
   }
   else
      cout << "Attempted assignment of a String to itself\n";

   return *this; // enables concatenated assignments
} // end function operator=

// concatenate right operand and this object and store in temp object
const String String::operator+( const String &right )
{
    String temp ; //declare a temp
    temp.length = length + right.length; //get two argument Strings’ lengthes
    temp.sPtr = new char [temp.length + 1]; // create memory
    assert( sPtr != 0 ); // terminate if memory not allocated
    strcpy( temp.sPtr, sPtr );  // copy sPtr
    strcpy( temp.sPtr + length, right.sPtr ); // copy right.sPtr
    return temp;
} // end function operator+

// overloaded output operator
ostream & operator<<( ostream &output, const String &s )
{
   output << s.sPtr;
   return output; // enables concatenation
} // end function operator<<
