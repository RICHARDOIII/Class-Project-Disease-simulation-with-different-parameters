#include <iostream>
#include <vector>
#include "person.h"
#include "population.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main(){
int npeople;
float probs,innoc;
// Initialze  and set the values needed
cout<<"How many people ?"<<endl;
cin>>npeople;
cout<<"Infection chance ?"<<endl;
cin>>probs;
cout<<"Vaccination rate ?"<<endl;
cin>>innoc;
// first we create the population, then innoculate
// innoculate first to prevent the innoculation from "saving" the target
Population population(npeople,probs);
population.innoculation(innoc);
population.random_infection();
int step=0;
srand(time(NULL));
while(population.count_infected()!=0)
{ 	
	step+=1;
	cout<< "In step "<<setw(3)<<step<<" ";
	population.Printer();
	float badluck=(float) rand() / (float) RAND_MAX;		
	population.update();
	population.setprob(badluck);
	};
cout<<"In step "<<setw(3)<<step+1<<" ";
population.Printer();
cout<<"Disease ran its course by step "<<step+1<<endl;
cout<< population.sickcount()<<" got sick."<<endl;
return 0;
}

