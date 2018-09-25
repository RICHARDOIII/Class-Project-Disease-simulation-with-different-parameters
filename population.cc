// Person definition file
#include"person.h"
#include"population.h"
#include<string> 
#include<vector>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<cstdlib>
using namespace std;
// Default constructor
		Population::Population()
		{
		int n=9;
		vector<Person> temp(n,Person());
		pop=temp;
		};
// Constructor that initializes and sets the size and probability 
		Population::Population(int people,float probs)
		{
			probability=probs;
			npeople=people;
// creates a vector of people using the Person class			
			vector<Person> temp(people,Person());
			pop=temp;
		};
// Infects a random person in the population
		void Population::random_infection()
			{
// Creates a random number between 0-x  and infects that person randomly 				
			srand(time(NULL));
			int luck=floor((npeople+1)*(float)rand()/(float)RAND_MAX);
				while(pop[luck].getn()==-2)
				{
				luck=floor((npeople+1)*(float)rand()/(float)RAND_MAX);
				}
			pop[luck].infect(5);
			};
// Updates each person in the vector
		void Population::update()
		{
			for(int i=0;i<npeople;i++){
// Uses the update method of the person				
					pop[i].update();}
		};
// goes through the vector and checks status
		int Population::count_infected()
	{
		int count=0;
		for(int i=0;i<npeople;i++)
		{	if (pop[i].getn()>0)
			{count+=1;}
		}
		return count;
	};
// Prints out status 
		void Population::Printer()
{	cout<<"#sick: "<<setw(4)<<count_infected()<<":";
		for(int i=0;i<npeople;i++)
	{	if (pop[i].getn()>0){ cout<< "+";}
		else if(pop[i].getn()==-1) { cout<< "-";}
		else if (pop[i].getn()==-2){ cout<<"*";}
		else { cout<< "?";}
	}
	cout<<endl;
};
// If the inputed float is less than the probability then
// the adjacent people will get sick
		void Population::setprob(float badluck)
		{	int count=0;
			for(int i=0;i<npeople;i++)
			{
				if(badluck<probability)
				{	
// Had to make sure that only the left and right of the sickly get infected
// so it should be only two newly sick people and breaks afterwards
					{ if (pop[i].getn()>0 && i!=0 && i!=npeople-1 && count<2)
						{	if( pop[i-1].getn()==0)
								{pop[i-1].infect(5);count+=1;}
						    if( pop[i+1].getn()==0)
								{pop[i+1].infect(5);count+=1;}
						}
					else if (pop[i].getn()>0 && i==0 && count<1)
						{	if( pop[i+1].getn()==0)
							{pop[i+1].infect(5);count+=1;}
						}
					else if (pop[i].getn()>0 && i==npeople-1 && count<1)
						{if( pop[i-1].getn()==0)
								{pop[i-1].infect(5);count+=1;}
						}
					}
				}
			}
		};
// innoculates a random percentage of people
		void Population::innoculation(float per)
		{
			int count=0;
			srand(time(NULL));
			int vaccinated=ceil(per*npeople);
			while(count<vaccinated){	
				for(int i=0;i<vaccinated;i++)
				{
					int random = floor((npeople+1)*(float)rand()/(float)RAND_MAX);
					pop[random].setn(-2);
				for(int i=0;i<npeople;i++)
					{if (pop[i].getn()==-2)
					{count+=1;}
					}
				}
				}
		};
// Sick person comes in contact with up to six people
		void Population::update_spread()
		{
			srand(time(NULL));
//creating an open vector with nothing inside 
			vector<int> open(0);
			for(int i=0;i<npeople;i++)
			{	if(pop[i].getn()>0)
// If sick they will come in contact with up to 6 random people
						{for(int j=0;j<6;j++)
// if the contacted people are unlucky enough they will be infected
							{	float bad_luck =(float)rand()/ (float)RAND_MAX;
								if(bad_luck<probability)
									{ int random=rand()%npeople;
											while(i==random)
												{random=rand()%npeople;}
// put the number of the index of the infected in the open vector											
											open.push_back(random);
										
									}
							}
						}
					
			}
// Now all the people who needed to be infected are
// infected outside the for loop to prevent them from
// spreading disease until the next day
			for(int i=0;i<open.size();i++)
			{
				if (pop[open[i]].getn()==0)
				{
					pop[open[i]].infect(5);
				}
			}
		}

	int Population::sickcount()
{	int count=0;
	for( int i=0;i<npeople;i++)
		{if (pop[i].getn()== -1)
			{count+=1;}
		}	
	return count;
};

