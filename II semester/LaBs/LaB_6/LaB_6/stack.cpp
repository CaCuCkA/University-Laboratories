#include "stack.h"

Stack::Stack() : root(nullptr) {}

Stack::~Stack() { clear(); };


void Stack::push(const int& x)
{
	Node* newnode = new Node;
	newnode->data = x;
	newnode->pNext = root;
	root = newnode;
}

void Stack::push(Stack& T1, Stack& T2)
{
	Stack temp;
	while (!T1.empty())
	{
		temp.push(T1.top());
		T1.pop();
	}
	while (!T2.empty())
	{
		T1.push(T2.top());
		T2.pop();
	}
	while (!temp.empty())
	{
		T2.push(temp.top());
		temp.pop();
	}
}

bool Stack::empty() const
{
	return root == nullptr;
}

void Stack::pop()
{
	if (empty())
		std::cerr << "Error! Your stack is empty!";
	else
	{
		Node* delnode = root;
		root = delnode->pNext;
		delete delnode;
	}

}

int Stack::top()
{
	if (empty())
		std::cerr << "Error! Your stack is empty." << std::endl;

	return root->data;
}

void Stack::view()
{
	if (empty())
		std::cerr << "Your stack is empty!";
	else
	{
		std::cout << "[ ";
		Node* view = root;
		while (view->pNext != nullptr)
		{
			std::cout << view->data << " ";
			view = view->pNext;
		}
		std::cout << view->data << " ";
		std::cout << "]" << std::endl;
	}

}

void Stack::clear()
{
	while (!empty()) { pop(); }
}
