/* Assignment: 6 – Part Template 
Campus: Beer Sheva 
Author: Lior Mahfoda, ID: 302782230 
Date: 26/05/2014*/

#ifndef RATIONAL_H
#define RATIONAL_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // I/O Libary
using namespace std;

class Rational
{
	private:
		int numerator;
		int denominator; // cannot be 0!

	public:
		// help methods 
		int GetNum() { return numerator; };
		int GetDNum() { return denominator; };
		void Reduce();

		// C'tors,C'ctor,D'tor
		Rational(); 
		Rational(int, int);
		Rational(const Rational&); 
		~Rational(); 

		// operators 
		bool operator > (Rational&);
		bool operator == (Rational& );
		Rational& operator = (Rational& );
		friend ostream& operator <<(ostream&, const Rational&);
		friend istream& operator >>(istream&, Rational&);

};	// end of class Rational	

#endif RATIONAL_H
