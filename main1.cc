// Main file
#include <iostream>
#include <vector>
#include "person.h"
#include "population1.h"

using namespace std;
int main(){
// Initialize and set the amount 
int npeople;
cout<<"How many people"<<endl;
cin>>npeople;
// Creates the population with npeople as the input
Population population(npeople);
// Infects a random person
population.random_infection();
int step=0;
while(population.count_infected()>=0)
{   // count
	step+=1;
	cout<< "In step   "<<step<<" ";
	// prints out the results
	population.Printer();
	// updates the population
  	population.update();
	// if there is no more sick people then loop is broken
	if (population.count_infected()==0)
	{break;}
};
// adds an extra step since the loop when no one is sick
// and does not print the last line 
cout<<"In step   "<<step+1<<" ";
population.Printer();
cout<<"Disease ran its course by step "<<step+1<<endl;
return 0;
}

