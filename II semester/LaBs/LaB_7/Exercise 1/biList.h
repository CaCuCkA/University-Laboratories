#pragma once
#include <iostream>

struct biNode
{
	int data;
	biNode* next;
	biNode* prev;
	biNode(int value)
	{
		data = value;
		next = prev = nullptr;
	}
};


class biList
{
public:
	biList();
	~biList();
	int getSize();
	biNode* get_back();
	void push_back(int);
	void push_front(int);
	void insert_before(int, int);
	void insert_after(int, int);
	void remove(int);
	void forward_view();
	void reverse_view();
	void clear();
	biNode* find(int);
	void splice_in(biList& T2, int index);
	void splice_out(biList& T2, int start, int end);
	void swap(int, int);
	void sort();
	
private:
	biNode* head;
	biNode* tail;
	int size;

	bool is_empty()
	{
		return head == NULL;
	}
		
	
};

