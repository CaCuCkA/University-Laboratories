#include <iostream>
#include "stack.h"

using namespace std;


int main()
{
	Stack st;
	int firstBoard, secondBoard;
	int newNumber;

	cout << "Enter first board and second board: ";
	cin >> firstBoard >> secondBoard;

	for (int i = firstBoard; i <= secondBoard; i++)
	{
		st.push(i);
	}

	cout << "Stack is done: " << endl;
	st.view();

	Stack evenSt;
	Stack oddSt;

	while (!st.empty())
	{
		if (!(st.top() % 2))
		{
			evenSt.push(st.top());
			st.pop();
		}
		else
		{
			oddSt.push(st.top());
			st.pop();
		}
	}

	cout << "Stack with even numbers: " << endl;
	evenSt.view();

	cout << "Stack with odd numbers: " << endl;
	oddSt.view();

	
	cout << "Enter a new even number: ";
	cin >> newNumber;


	
	cout << "Stack with even numbers after adding " << evenSt.top()  << " and deleting " <<
		newNumber << ": " << endl;
	evenSt.pop();
	evenSt.push(newNumber);
	evenSt.view();


	cout << "Enter a new odd number: ";
	cin >> newNumber;

	cout << "Stack with odd numbers after adding " << oddSt.top() << " and deleting " <<
		newNumber << ": " << endl;
	oddSt.pop();
	oddSt.push(newNumber);
	oddSt.view();


	while (!oddSt.empty() && !evenSt.empty())
	{
		if (oddSt.top() > evenSt.top())
		{
			st.push(evenSt.top());
			evenSt.pop();
		}

		else
		{
			st.push(oddSt.top());
			oddSt.pop();
		}

	}

	while (!oddSt.empty())
	{
		st.push(oddSt.top());
		oddSt.pop();
	}

	while (!evenSt.empty())
	{
		st.push(evenSt.top());
		evenSt.pop();
	}

	cout << "Union of stack with even numbers and stack with odd numbers:" << endl;
	st.view();

	cout << "Enter first and last board for a new stack: ";
	cin >> firstBoard >> secondBoard;

	Stack test;

	for (int i = firstBoard; i < secondBoard; i++) { test.push(i); }

	cout << "Old stack after switching: " << endl;
	st.push(test, st);
	st.view();

	cout << "New stack after switching and deleting all elements: " << endl;
	test.clear();
	test.view();

	return 0;

}