#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>
using namespace std;
class Person {
	private:
		int n;
	public:
		Person();
		Person(int nx);
		void update();
		string status_string();
		void infect(int nx);
		void setn(int nx);
		void step();
		int getn();
		bool is_stable();
};
#endif


















