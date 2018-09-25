// Main file for the first example
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "person.h"
using namespace std;
int main()
{
	Person joe;
	srand(time(NULL));
	int step=0;
// updates joe
	joe.update();
// this while loop will continue until recovery
	while(joe.is_stable()==false)
	{
		// day counter
		step=step+1; 
// updates every day 
		joe.update();
// each day the person gets assigned bad luck to see if will get sick
		float bad_luck =(float) rand()/ (float) RAND_MAX;
		if(bad_luck>.95)
			{
//if his bad luck is high enough he will get sick 
			joe.infect(5);
			}
// prints the status of the person of each day
	cout<<"On day "<<step<<", Joe is "<< joe.status_string()<<endl;
	if(joe.is_stable()==true)
	{break;}
	}
return 0;}




