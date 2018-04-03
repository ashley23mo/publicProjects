/**********************************************
* Name: Ashley Morton                         *
* Date: December 3, 2017                      *
* Assignment: Project 3: Sets                 *
***********************************************
* Program asks user for input and will create *
* and will unionize, combine, and differ the  *
* lists given by the user, per user's choice. *
***********************************************/

#include <stddef.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Set {
public:
	int maxLength;
	int curLength;
	T *list;
	Set();
	~Set();
	void resizeArray();
	void print(void) const;
	Set<T>* unionArray(Set<T>* &s1);
	Set<T>* intersection(Set<T>* &s1);
	Set<T>* difference(Set<T>* &s1);
	void Sort();
	void Input(string s);
	void FindDoubles();
};
//finds the difference between the two vectors
template <class T>
Set<T>* Set<T>::difference(Set<T>*  &s1)
{
	Set<T> * temp = new Set<T>;
	string tempString = "";
	int index1 = 0;
	int index2 = 0;
	int same = 0;
	for (index1 = 0; index1 < curLength; index1++) 
	{
		same = 0;
		for (index2 = 0; index2 < s1->curLength; index2++)
		{
			if (list[index1] == s1->list[index2]) 
			{
				same++;
			}//end if
		}//end for
		if (same == 0)
		{
			string a = std::to_string(list[index1]);
			tempString += a;
			tempString += "/";
		}//end if
	}//end for
	temp->Input(tempString);
	return temp;
}
//returns only what is in both vectors
template <class T>
Set<T>* Set<T>::intersection(Set<T>* &s1) 
{
	Set<T> * temp = new Set<T>;
	string tempString = "";
	int index1 = 0;
	int index2 = 0;

	while (index1 < curLength && index2 < s1->curLength)
	{
		if (list[index1] < s1->list[index2]) {
			index1++;
		}
		else if (list[index1] > s1->list[index2])
		{
			index2++;
		}
		else 
		{
			string a = std::to_string(list[index1]);
			tempString += a;
			tempString += "/";
			index1++;
			index2++;
		}//end else
	}//end while
	temp->Input(tempString);
	return temp;


}
//returns what is in both vectors, excluding doubles
template <class T>
Set<T>* Set<T>::unionArray(Set<T>* &s1) 
{
	Set<T> * temp = new Set<T>;
	string tempString = "";

	for (int i = 0; i < curLength; i++) 
	{
		string a = std::to_string(this->list[i]);
		tempString += a;
		tempString += "/";
	}//end for


	for (int i = 0; i < s1->curLength; i++) 
	{
		string a = std::to_string(s1->list[i]);
		tempString += a;
		tempString += "/";
	}//end for
	temp->Input(tempString);
	return temp;

}//end union


template <class T>
Set<T>::Set()
{
	this->maxLength = 15;
	this->curLength = 0;
	this->list = new T[maxLength];
}
//The Destroyer
template <class T>
Set<T>::~Set() 
{
	delete[] list;
}//end destructor

//Sorts the vectors in ascending order
template <class T>
void Set<T>::Sort()
{
	for (int i = 1; i < this->curLength; i++)
	{
		T temp = this->list[i];
		int j = i;
		while (j > 0 && temp < this->list[j - 1])
		{
			this->list[j] = this->list[j - 1];
			j--;
		}//end while
		this->list[j] = temp;
	}//end for
}//end sort

//Resizing array if needed
template <class T>
void Set<T>::resizeArray()
{
	this->maxLength *= 2;
	T * temp = new T[this->maxLength];
	for (int i = 0; i <= this->curLength; i++) 
	{
		temp[i] = this->list[i];
	}//end for
	delete[] this->list;
	this->list = temp;

}//end resize

//turns user's input into arrays to compare
template <class T>
void Set<T>::Input(string s)
{
	std::string::size_type size;
	int temp[50];
	int index = 0;
	int loc = 0;
	string substring;
	while (loc <= s.length()) 
	{
		if ((s[loc] >= '0' && s[loc] <= '9') || s[loc] == '-') 
		{
			substring += s[loc];
		}
		else 
		{
			if (substring.length() != 0) 
			{
				int number = stoi(substring, &size);
				temp[index] = number;
				index++;
			}//end if
			substring.clear();
		}//end else
		loc++;
	}//end while
	for (int i = 0; i < index; i++)
	{
		if (this->curLength == this->maxLength) 
		{
			this->resizeArray();
		}//end if
		this->list[i] = temp[i];
		this->curLength++;
	}//end for
	this->Sort();
	this->FindDoubles();

}

//Check sfor duplicates in each array
template <class T>
void Set<T>::FindDoubles()
{
	T * temp = new T[curLength];
	int j = 0;
	for (int i = 0; i < curLength - 1; i++)
	{
		if (list[i] != list[i + 1]) 
		{
			temp[j] = list[i];
			j++;
		}//end if
		resizeArray();
	}//end for
	temp[j++] = list[curLength - 1];
	curLength = j;
	delete[] this->list;
	list = temp;

}

//Prints
template <class T>
void Set<T>::print(void) const
{
	for (int i = 0; i < curLength; i++)
	{
		cout << list[i] << " ";
	}//end for
	cout << endl;
}//end print