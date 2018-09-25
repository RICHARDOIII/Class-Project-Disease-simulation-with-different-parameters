#include <iostream>
#include <vector>
#include "person.h"
#include "population.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){
// Initializes and reads in the values needed
int npeople;
float probs;
cout<<"How many people"<<endl;
cin>>npeople;
cout<<"Infection chance ?"<<endl;
cin>>probs;
// Creates the population with Population class.
Population population(npeople,probs);
population.random_infection();
int step=0;
srand(time(NULL));
while(population.count_infected()!=0)
{ 	
	step+=1;
	cout<< "In step   "<<setw(3)<<step<<" ";
	population.Printer();
// Every iteration it creates a new random float value
	float badluck=(float) rand() / (float) RAND_MAX;		
//	Updates the status of the people of the population
	population.update();
//	Inputs the number into the setprob method
//	if the badluck is greater than the spread rate then they will get sick
	population.setprob(badluck);
	};
cout<<"In step   "<<setw(3)<<step+1<<" ";
population.Printer();
cout<<"Disease ran its course by step "<<step+1<<endl;
cout<< population.sickcount()<<" got sick"<<endl;
return 0;
}

