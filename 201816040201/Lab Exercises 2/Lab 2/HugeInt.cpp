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

    for (int  i = 0; i <= 29; i++ )
        if ( integer[ i ] != 0 )
            return 30 - i;// break when first digit is reached

    // length is from first digit (at i) to end of array
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
HugeInt HugeInt::operator-(HugeInt op2)
{
    HugeInt temp,op1;
    for(int i=29; i>=0; i--)
        op1.integer[i]=integer[i];
    int len1=getLength();
    int len2=op2.getLength();
    if(len1>len2)///左大右小
    {
        for(int i=29; i>=0; i--)
        {
            int flag=i;
            if(integer[i]-op2.integer[i]>=0)
            {
                temp.integer[i]= integer[i]-op2.integer[i];
            }
            else
            {

                temp.integer[i]=integer[i]+10-op2.integer[i];

                while(1)
                {

                    if(integer[flag-1]==0)
                    {
                        integer[flag-1]=9;
                    }

                    else if(integer[flag-1]!=0)
                    {
                        integer[flag-1]--;
                        break;
                    }
                    flag--;
                }

            }
        }
    }
    else if(len2>len1)///右大左小
    {
        for(int i=29; i>=0; i--)
        {
            int flag=i;
            if(op2.integer[i]-integer[i]>=0)
            {
                temp.integer[i]=op2.integer[i]-integer[i];
            }
            else
            {

                temp.integer[i]=op2.integer[i]+10-integer[i];

                while(1)
                {

                    if(op2.integer[flag-1]==0)
                    {
                        op2.integer[flag-1]=9;
                    }

                    else if(op2.integer[flag-1]!=0)
                    {
                        op2.integer[flag-1]--;
                        break;
                    }
                    flag--;
                }

            }
        }
        for(int i=0; i<=29; i++) ///转符号
        {
            if(temp.integer[i]!=0)
            {
                temp.integer[i]=-temp.integer[i];
                break;
            }
        }
    }
    else///等长
    {
        int flag=0;
        for(int i=29; i>=0; i--)
            if(integer[i]>op2.integer[i])
                flag=1;

        if(flag)///左大右小
        {
            for(int i=29; i>=0; i--)
            {
                if(integer[i]<op2.integer[i])
                {
                    temp.integer[i]=integer[i]+10-op2.integer[i];
                    integer[i-1]--;
                }
                else
                    temp.integer[i]=integer[i]-op2.integer[i];
            }
        }
        else
        {
            for(int i=29; i>=0; i--)
            {
                if(op2.integer[i]<integer[i])
                {
                    temp.integer[i]=op2.integer[i]+10-integer[i];
                    op2.integer[i-1]--;
                }
                else
                    temp.integer[i]=op2.integer[i]-integer[i];
            }
            for(int i=0; i<=29; i++) ///转符号
            {
                if(temp.integer[i]!=0)
                {
                    temp.integer[i]=-temp.integer[i];
                    break;
                }
            }

        }

    }
    for(int i=29; i>=0; i--)///左值复位
        integer[i]=op1.integer[i];
    return temp;


}
// addition operator; HugeInt + int
HugeInt HugeInt::operator+( int op2 ) const
{
    // convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt( op2 );
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const char *op2 ) const
{
    // convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt( op2 );
} // end function operator+
bool HugeInt::operator==(const HugeInt &right) const
{
    //cout<<right.integer[1]<<endl;
    int len1= right.getLength();
    int len2=getLength();
    //cout<<len1<<endl;
    if(len1!=len2)
        return false;
    else
    {
        int flag=0;
        for(int i=29; i>=29-len1; i--)
        {
            // cout<<right<<" "<<*this<<endl;
            if(right.integer[i]!=integer[i])
            {
                flag=1;
                break;
            }
        }
        // cout<<flag<<endl;
        if(flag==1)
            return false;
        else
            return true;
    }
}
bool HugeInt::operator<(const HugeInt &hehe) const
{
    int len1= hehe.getLength();
    int len2=getLength();
    // cout<<len1<<endl;
    if(len1==len2)
    {
        int flag=0;
        for(int i=29; i>=29-len1; i--)
        {
            int mx=max(hehe.integer[i],integer[i]);
            if(hehe.integer[i]<mx)
            {
                return false;
            }
            else  if(integer[i]<mx)
            {
                return true;
            }
        }

    }
    else if(len1>len2)
        return true;
    else
        return false;

}

// equality operator; HugeInt == HugeInt
/* Write a definition for the == operator */

// inequality operator; HugeInt != HugeInt
/* Write a definition for the != operator
   by calling the == operator */

// less than operator; HugeInt < HugeInt
/* Write a definition for the < operator */

// less than or equal operator; HugeInt <= HugeInt
/* Write a definition for the <= operator
   by calling the < and == operators */

// greater than operator; HugeInt > HugeInt
/* Write a definition for the > operator
   by calling the <= operator */

// greater than or equal operator; HugeInt >= HugeInt
/* Write a definition for the >= operator
   by calling the > and == operators */

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
