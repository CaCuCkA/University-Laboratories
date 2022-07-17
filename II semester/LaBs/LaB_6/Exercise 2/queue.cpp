#include "queue.h"


Queue::Queue() : head(NULL), tail(NULL) {}


bool Queue::empty()
{
	return head == NULL;
}
void Queue::enque(int x)
{
	if (head == NULL)
		head = tail = new Node(x, NULL);
	else
		tail = tail->pNext = new Node(x, NULL);
}
void Queue::enque(Queue T2)
{
	Queue temp;
	while (!empty())
	{
		temp.enque(first());
		deque();
	}
	while (!T2.empty())
	{
		enque(T2.first());
		T2.deque();
	}
	while (!temp.empty())
	{
		T2.enque(temp.first());
		temp.deque();
	}
}
void Queue::deque()
{
	assert(head != NULL);
	Node* tmp = head;
	head = head->pNext;
	if (head == NULL)
		tail = NULL;
	delete tmp;
}
int Queue::last()
{
	return tail->data;
}
int Queue::first()
{
	return head->data;
}
void Queue::view()
{
	if (empty())
		std::cerr << "Error! Queue is empty." << std::endl;
	else
	{
		Node* temp = head;		
		std::cout << "[ ";
		while (temp->pNext != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->pNext;
		}
		std::cout << tail->data << " ]" << std::endl;	
	}
}
void Queue::clear()
{
	Node* temp;
	while (!empty())
	{
		deque();
	}

}
