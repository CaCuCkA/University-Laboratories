#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	Queue qu;
	int firstBoard, secondBoard;
	int newNumber;

	cout << "Enter first board and second board: ";
	cin >> firstBoard >> secondBoard;

	for (int i = firstBoard; i <= secondBoard; i++)
	{
		qu.enque(i);
	}

	cout << "Queue is done: " << endl;
	qu.view();

	Queue evenQu;
	Queue oddQu;


	while (!qu.empty())
	{
		if (!(qu.first() % 2))
		{
			evenQu.enque(qu.first());
			qu.deque();
		}
		else
		{
			oddQu.enque(qu.first());
			qu.deque();
		}
	}

	cout << "Queue with even numbers: " << endl;
	evenQu.view();

	cout << "Queue with odd numbers: " << endl;
	oddQu.view();

	cout << "Enter a new even number: ";
	cin >> newNumber;


	cout << "Queue with even numbers after adding " << newNumber << " and deleting " <<
		newNumber << ": " << endl;
	evenQu.deque();
	evenQu.enque(newNumber);
	evenQu.view();

	cout << "Enter a new even number: ";
	cin >> newNumber;

	cout << "Queue with odd numbers after adding " << newNumber << " and deleting " <<
		oddQu.last() << ": " << endl;
	oddQu.deque();
	oddQu.enque(newNumber);
	oddQu.view();



	while (!oddQu.empty() && !evenQu.empty())
	{
		if (oddQu.first() > evenQu.first())
		{
			qu.enque(evenQu.first());
			evenQu.deque();
		}

		else
		{
			qu.enque(oddQu.first());
			oddQu.deque();
		}

	}


	while (!oddQu.empty())
	{
		qu.enque(oddQu.first());
		oddQu.deque();
	}

	while (!evenQu.empty())
	{
		qu.enque(evenQu.first());
		evenQu.deque();
	}

	cout << "Union of stack with even numbers and stack with odd numbers:" << endl;
	qu.view();
	
	Queue test;

	cout << "Enter first board and second board for a new queue: ";
	cin >> firstBoard >> secondBoard;


	for (int i = firstBoard; i < secondBoard; i++) { test.enque(i); }

	cout << "Old queue after switching: " << endl;
	qu.enque(test);
	qu.view();

	cout << "New queue after switching and deleting all elements: " << endl;
	test.clear();
	test.view();

	return 0;
}