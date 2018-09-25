//  population header file
#ifndef POPULATION_H_
#define POPULATION_H_
#include"person.h"
#include<string> 
#include<vector>
#include<cmath>
#include<iostream>
// Creation of the methods used
class Population {
	private:
// Has the amount of people and infection probability
		int npeople;
		float probability;
	public:
//	Creates a vector of people using the person class 
		vector<Person> pop;
		Population();
		Population(int people,float probs);
// infects a random people
		void random_infection();
// Counting sick people
		int count_infected();
// updates the population
		void update();
// Prints a line 
		void Printer();
// determines wether the persons adjacent gets sick or not
		void setprob(float badluck);
// randomly vaccinates the person
		void innoculation(float vaccine);
// sick people come in contact with up to six random people		
		void update_spread();
// Total amount sick
		int sickcount();
};
#endif

		

