#include <iostream>
#include "biList.h"

using namespace std;

void randomData(biList&, int, int, int);

int main()
{
	biList list;
	int start, stop, count;

	cout << "Enter diapason for your elements in list: " << endl;
	cin >> start >> stop;

	cout << "Enter amount of elements: " << endl;
	cin >> count;

	randomData(list, start, stop, count);

	cout << "Unsorted list: ";
	list.forward_view();
	
	/*
	for (int i = 0; i < list.getSize(); i++)
	{
		//cout << !(list.find(i)->data % 2) << " " << i << endl;
		if (!(list.find(i)->data % 2))
		{
			list.insert_after(i, list.find(i)->data - 1);
			i++;
		}
		else
		{
			list.insert_before(i, list.find(i)->data + 1);
			i++;
		}
	}

	cout << "List after condition 1: ";
	list.forward_view();
	
	cout << "====================================================" << endl;

	cout << "List before condition 2: ";
	list.forward_view();
	list.push_front(12);

	for (int i = 0; i < list.getSize(); i++)
	{
		if (!(list.find(i)->data % 3) || !(list.find(i)->data % 5))
		{
			list.remove(i);
			i--;
		}
	}

	cout << "List after condition 2: ";
	list.forward_view();

	cout << "====================================================" << endl;

	biList list2;
	cout << "List 2 is ready: " << endl;
	randomData(list2, -11, 0, 6);
	list2.forward_view();

	cout << "====================================================" << endl;

	cout << "List 1 before splice_in(): ";
	list.forward_view();

	list.splice_in(list2, 3);

	cout << "List 1 after splice_in(): ";
	list.forward_view();

	cout << "====================================================" << endl;

	list.clear();

	cout << "Adding new data in list 1: ";
	randomData(list, 5, 18, 8);
	list.forward_view();

	cout << "====================================================" << endl;

	cout << "List 2 before splice_out(): ";
	list2.forward_view();

	list.splice_out(list2, 2, 7);

	cout << "List 2 after splice_out(): ";
	list2.forward_view();

	cout << "====================================================" << endl;
	*/
	
	cout << "Sorted list: ";
	list.sort();
	list.forward_view();
	

	return 0;
}

void randomData(biList& list, int start, int stop, int count)
{
	srand(time(0));

	for (; count; count--)
	{
		int element = start + rand() % (stop + start);
		list.push_back(element);
	}
}