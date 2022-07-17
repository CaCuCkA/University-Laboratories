#pragma once
#include <iostream>




class Stack
{

public:
	Stack();
	~Stack();
	void push(const int& x);
	void push(Stack& T1, Stack& T2);
	bool empty() const;
	void pop();
	int top();
	void view();
	void clear();
private:

	struct Node
	{
		int data;
		Node* pNext;
	};
	Node* root;
};


