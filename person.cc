#include <iostream>
#include "person.h"
#include <string>
using namespace std;
// Default constructor sets everything to zero
		Person::Person(){n=0;};
// Constructor that accepts an integer
 		Person::Person(int nx)
		{n=nx;};
// Update the person subtracting one off the integer
// Each time it illiterated
		void Person::update()
		{
			if (n>=1)
			{
				step();
// Once then get to the point of being recovered
// It sets the integer to -1
				if (getn()+1==1 && n==0)
					{ setn(-1);}
			}
		};
// prints out  the string
		string Person::status_string()
		{
			if(n>=1)				
			{ 	string s="sick ";
				return s;}
			else if (n==-1)
			{ return "recovered";}
			else
			{ return "susceptible"; }
		};
// infects the person
		void Person::infect(int nx)
		{setn(nx);};
// returns the current value of the person		
		int Person::getn()
		{ return n;}
// sets the value of the person to the value given
		void Person::setn(int nx){n=nx;};
// subtracts one off the value
		void Person::step()
		{ n=n-1;};

		bool Person::is_stable()
		{
			if(n==-1)
			{ return true;}
			else 
			{return false;}
		};

