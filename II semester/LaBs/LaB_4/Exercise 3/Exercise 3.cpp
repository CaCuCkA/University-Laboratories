#include <iostream>
#include <vector>
#include <cstdlib>
#include<ctime>
#include <iterator>

using namespace std;

vector<int>initializeVector(vector<int> &vec, int, int, int);
void displayVector(vector<int>);
void rightVShift(vector<int>& vec, int);
//void rightCShift(vector<int>& vec, int, int);

int main()
{
	int size, firstValue, secondValue, K;
	vector<int> intVector;

	cout << "Enter first and last borders: ";
	cin >> firstValue >> secondValue;

	cout << "Enter vector`s size: ";
	cin >> size;

	cout << "Vector is done: " << endl;
	initializeVector(intVector, firstValue, secondValue, size);

	cout << intVector.size() << endl;

	cout << "Enter amount of repeat: ";
	cin >> K;

	rightVShift(intVector, K);
	//rightCShift(intVector, K, size - 1);
	displayVector(intVector);
	return 0;
}

vector<int>initializeVector(vector<int> &vec, int fB, int sB, int size)
{
	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		int element = fB + rand() % (sB + 1);
		vec.push_back(element);
		if (!(i % 3))
			cout << endl;
		cout << vec[i] << '\t';
	}
	cout << endl << endl;
	
	return vec;
}



void displayVector(vector<int> vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (!(i % 4))
			cout << endl;
		cout << vec[i] << '\t';
	}
	cout << endl << endl;
}

// using vector`s functions 

void rightVShift(vector<int>& vec, int K)
{
	for (int i = 0; i < K; i++)
	{
		for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend() - 1; it++)
		{
			*it = *(it + 1);
		}
		vec.front() = 0;
	}
}


// using classical method 
/*
void rightCShift(vector<int>& vec, int K, int size)
{
	for (int i = 0; i < K; i++)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			vec[j] = vec[j - 1];
		}
		vec[0] = 0;
	}
}
*/
