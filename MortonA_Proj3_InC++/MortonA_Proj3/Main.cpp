/**********************************************
* Name: Ashley Morton                         *
* Date: December 3, 2017                      *
* Assignment: Project 3: Sets                 *
***********************************************
* Program asks user for input and will create *
* and will unionize, combine, and differ the  *
* lists given by the user, per user's choice. *
***********************************************/


#include "Set.cpp";
#include <stddef.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int main() {
	Set<int> *s1 = new Set<int>;
	Set<int> *s2 = new Set<int>;
	string stringOne;
	string stringTwo;


	//Gathering user input might be useful here
	cout << "Input vector 1 (like num1,num2,...,numN) : ";
	cin >> stringOne;
	s1->Input(stringOne);
	
	cout << "Input vector 2 (like num1,num2,...,numN) : ";
	cin >> stringTwo;
	s2->Input(stringTwo);
		


		cout << "The sorted sets are:" << endl;
		s1->print();
		s2->print();
		//repeatitively ask until they give up and quit
		char userInput = ' ';
		while (true)
		{
			Set<int> *newString = new Set<int>;
			cout << "Enter (i)ntersect, (u)nion, (d)ifference, or (q)uit: " << endl;
			cin >> userInput;
			if (userInput == 'I' || userInput == 'i')
			{
				newString = s1->intersection(s2);
				newString->print();
			}
			else if (userInput == 'U' || userInput == 'u')
			{
				newString = s1->unionArray(s2);
				newString->print();
			}
			else if (userInput == 'D' || userInput == 'd')
			{
				newString = s1->difference(s2);
				newString->print();
			}
			else if(userInput == 'Q'|| userInput == 'q')
			{
				break;
			}
			//destroy a little
			newString->~Set();
		}
		//detroy it all
		s1->~Set();
		s2->~Set();
	}//end main
	