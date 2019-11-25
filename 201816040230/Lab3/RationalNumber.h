// Lab 3: RationalNumber.h
// RationalNumber class definition.
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber
{
public:
   RationalNumber( int = 0, int = 1 );
   RationalNumber operator+(const RationalNumber&); /* Write prototype for operator + */
   RationalNumber operator-(const  RationalNumber&);/* Write prototype for operator - */
   RationalNumber operator*(const RationalNumber&); /* Write prototype for operator * */
   RationalNumber operator/(const  RationalNumber&); /* Write prototype for operator / */ // default constructor
   bool operator!=(const RationalNumber&);  /* Write prototype for operator != */
   bool operator>(const RationalNumber&);/* Write prototype for operator > */
   bool operator<(const RationalNumber&);/* Write prototype for operator < */
   bool operator>=(const RationalNumber&); /* Write prototype for operator >= */// relational operators
   bool operator<=(const RationalNumber&); /* Write prototype for operator <= */
   bool operator==(const RationalNumber&); /* Write prototype for operator == */// equality operators
   void printRational() const; // display rational number
private:
   int numerator; // private variable numerator
   int denominator; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

#endif


