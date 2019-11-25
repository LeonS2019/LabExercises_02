// Lab 1: StringCat.cpp
// Demonstrating overloaded + operator that does not modify operands
#include <iostream>
using namespace std;

#include "String.h"

int main()
{
   String string1, string2( "The date is" );
   String string3( " August 1, 1993" );

   // test overloaded operators
   cout << "string1 = string2 + string3\n";
   string1 = string2 + string3;
   cout << "\"" << string1 << "\" = \"" << string2 << "\" + \""
      << string3 << "\"" << endl;
} // end main
