//header file
#ifndef POPULATION1_H_
#define POPULATION1_H_
#include"person.h"
#include<string> 
#include<vector>
#include<cmath>
#include<iostream>

class Population {
	private:
		int npeople;
	public:
// vector of people		
		vector<Person> pop;
		Population();
		Population(int people);
		void random_infection();
		int count_infected();
		void update();
		void Printer();
};
#endif

		

