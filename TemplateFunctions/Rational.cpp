/* Assignment: 6 – Part Template 
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
Date: 26/05/2014*/

#include "Rational.h"

/*-----------------------------------------------------------------------------
   Name:  constructor for class "Rational"

   Purpose:  Initialize the contents of a rational number
   Receive:  none
-----------------------------------------------------------------------------*/
Rational::Rational() 
{
	numerator = 0;
	denominator = 1;
} // end method

/*-----------------------------------------------------------------------------
   Name:  constructor with parameters for class "Rational"

   Purpose:  Initialize the contents of a rational number from user's input
   Receive:  The numerator and denominator 
-----------------------------------------------------------------------------*/
Rational::Rational(int num, int dem) 
{
	numerator = num;
	if (denominator==0) // can't divide by 0!
		this->denominator = 1;
	else
		this->denominator = dem;
	Reduce(); // lower the rational number
} // end method

/*-----------------------------------------------------------------------------
   Name:  copy constructor for class "Rational"

   Purpose:  copy object
   Receive:  another Rational class
-----------------------------------------------------------------------------*/
Rational::Rational(const Rational& other)  
{
	numerator = other.numerator;
	denominator = other.denominator;
} // end method 

/*-----------------------------------------------------------------------------
   Name:  distructor for class "Rational"

   Purpose:  restore rationa number to default value
   Receive:  none
-----------------------------------------------------------------------------*/
Rational::~Rational() // distructor
{
	numerator = 0;
	denominator = 1;
} // end method 

/*-----------------------------------------------------------------------------
   Name:  reduce for class "Rational"

   Purpose:  minimize the rational number to lowest
   Receive:  none
-----------------------------------------------------------------------------*/
void Rational::Reduce()
{
   int n = numerator < 0 ? -numerator : numerator;
   int d = denominator;
   int largest = n > d ? n : d;

   int gcd = 0; // greatest common divisor

   for (int loop = largest; loop >= 2; loop--)
      if (numerator % loop == 0 && denominator % loop == 0) {
         gcd = loop;
         break;
      }

   if (gcd != 0) {
      numerator /= gcd;
      denominator /= gcd;
   }
} // end method

/*-----------------------------------------------------------------------------
   Name:  operator > for class "Rational"

   Purpose:  determine if one object of class Rational in bigger than the other
   Receive:  rational number
-----------------------------------------------------------------------------*/
bool Rational::operator > ( Rational& num)
{
	if (numerator * num.GetDNum() > denominator * num.GetNum())
		return true;

	return false;
} // end method

/*-----------------------------------------------------------------------------
   Name:  operator == for class "Rational"

   Purpose:  determine if one object of class Rational in equal than the other
   Receive:  rational number
-----------------------------------------------------------------------------*/
bool Rational::operator == ( Rational& num)
{
	if ( numerator * num.GetDNum() == denominator * num.GetNum() )
		return true;

	return false;
} // end method

/*-----------------------------------------------------------------------------
  Name:  operator = for class "Rational"

   Purpose:  Assign an object into another
   Receive:  rational number
-----------------------------------------------------------------------------*/
Rational& Rational::operator = (Rational& C )
{
        numerator = C.numerator;
        denominator = C.denominator;

        return *this;
} // end method

/*-----------------------------------------------------------------------------
  Name:  operator << for class "Rational"

   Purpose:  output of an object to screen 
   Receive:  ostream libary and rational number
-----------------------------------------------------------------------------*/
ostream& operator<<(ostream& out, const Rational& r)
{
  if (r.denominator == 0)
		out << "undefined" ;
  else
		out << r.numerator << "/" << r.denominator;
	
  return out;

} // end method

/*-----------------------------------------------------------------------------
  Name:  operator >> for class "Rational"

   Purpose:  input for an object
   Receive:  ostream libary and rational number
-----------------------------------------------------------------------------*/
istream& operator>>(istream& in, Rational& r)
{
    in >> r.numerator >> r.denominator;  

	return in;
} // end method
