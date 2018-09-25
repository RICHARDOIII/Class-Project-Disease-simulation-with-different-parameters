#include <iostream>
#include <vector>
#include "person.h"
#include "population.h"
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
int npeople;
float probs,innoc;
cout<<"How many people ?"<<endl;
cin>>npeople;
cout<<"Infection chance ?"<<endl;
cin>>probs;
cout<<"Vaccination rate ?"<<endl;
cin>>innoc;
Population population(npeople,probs);
population.innoculation(innoc);
population.random_infection();
int step=0;
srand(time(NULL));
while(population.count_infected()!=0)
{ 	
	step+=1;
	cout<< "In step   "<<step<<" ";
	population.Printer();
	population.update();
  	population.update_spread();
	};
cout<<"In step   "<<step+1<<" ";
population.Printer();
cout<<"Disease ran its course by step "<<step+1<<endl;
cout<<population.sickcount()<< " got sick"<<endl;
return 0;
}

