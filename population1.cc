// Uses the header files
#include"person.h"
#include"population1.h"
// needs these to use the functions and commands needed
#include<string> 
#include<vector>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
// Default Constructor
		Population::Population()
		{	
		int n=9;
		vector<Person> temp(n,Person());
		pop=temp;
		};
//Constructor takes in a integer or amount of people
		Population::Population(int people)
		{
		npeople=people;
// makes a vector of people		
		vector<Person> temp(people,Person());
		pop=temp;
		};
// Randomly infects a person
		void Population::random_infection()
			{
			srand(time(NULL));
			int luck=floor(npeople*(float)rand()/(float)RAND_MAX);
			pop[luck].infect(5);
			};
		void Population::update(){
			for(int i=0;i<npeople;i++){
				pop[i].update();}
			};
// Counts the number of the infected
		int Population::count_infected()
	{
		int count=0;
		for(int i=0;i<npeople;i++)
		{	if (pop[i].getn()>0)
			{count+=1;}
		}
		return count;
	};
// prints out the line of identifiers
		void Population::Printer()
	{	cout<<"#sick: "<<count_infected()<<":";
			for(int i=0;i<npeople;i++)
				{if (pop[i].getn()>0)
					{ cout<< "+";}
				else if(pop[i].getn()==-1) 
				{ cout<< "-";}
				else 
				{ cout<< "?";}}
				cout<<endl;
	};

			


