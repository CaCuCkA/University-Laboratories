#pragma once
#include <iostream>
#include <cassert>
class Queue
{
public:
	Queue();
	void enque(int);
	void enque(Queue T2);
	void deque();
	int first();
	int last();
	bool empty();
	void view();
	void clear();
	
	

private:
	struct Node
	{
		int data;
		Node* pNext;
		Node(int v = 0, Node* n = nullptr)
		{
			data = v;
			pNext = n;
		}
	};
	Node* head;
	Node* tail;
};

