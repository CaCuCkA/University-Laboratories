#include "biList.h"

biList::biList() :  head(NULL), tail(NULL), size(0) {}

biList::~biList()
{
	if (is_empty())
		return;
	else
		clear();
}

int biList::getSize() { return size; }

biNode* biList::get_back()
{
	return tail;
}

void biList::push_back(int value)
{
	biNode* temp = new biNode(value);

	if (tail == NULL)
		head = tail = temp;

	else if (size == 1)
	{
		tail = temp;
		tail->prev = head;
		head->next = tail;
	}

	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	size++;
}

void biList::push_front(int value)
{
	biNode* temp = new biNode(value);

	if (head == NULL)
		head = tail = temp;
	
	else if (size == 1)
	{
		head = temp;
		head->next = tail;
		tail->prev = head;
	}

	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	size++;
}

void biList::insert_before(int index, int value)
{
	biNode* insertNode = new biNode(value);
	biNode* cursor = head;
	
	if (index)
	{
		for (int i = index; i; i--)
			cursor = cursor->next;

		biNode* temp = cursor->prev;
		temp->next = insertNode;
		insertNode->prev = temp;
		insertNode->next = cursor;
		cursor->prev = insertNode;
		size++;
	}
	else
		push_front(value);

	
}

void biList::insert_after(int index, int value)
{
	biNode* insertAfter = new biNode(value);
	biNode* cursor = head;

	if (index < size - 1)
	{
		if (index + 1 == size)
			push_back(value);

		for (int i = index; i; i--)
			cursor = cursor->next;

		biNode* temp = cursor->next;
		temp->prev = insertAfter;
		cursor->next = insertAfter;
		insertAfter->prev = cursor;
		insertAfter->next = temp;
		size++;
	}

	else
		push_back(value);

	

}

void biList::remove(int index)
{
	if (is_empty())
	{
		std::cerr << "Error! Your list is empty." << std::endl;
		return;
	}
	if (!index)
	{
		biNode* cursor = head;
		head = cursor->next;
		head->prev = nullptr;
		delete cursor;
	}
	else if(index + 1 == size)
	{
		biNode* cursor = tail;
		tail = cursor->prev;
		tail->next = nullptr;
		delete cursor;
	}
	else
	{
	
		biNode* cursor = head;
		for (; index; index--)
			cursor = cursor->next;

		biNode* temp = cursor->prev;
		temp->next = cursor->next;
		temp = cursor->next;
		temp->prev = cursor->prev;
		delete cursor;
	}
	
	size--;
}

void biList::forward_view()
{
	using namespace std;
	if (is_empty())
	{
		std::cerr << "Error! Your list is empty." << std::endl;
		return;
	}

	biNode* temp = head;

	cout << "[ ";
	while (temp->next != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ]" << endl;
	temp = NULL;

	delete temp;
}

void biList::reverse_view()
{
	using namespace std;
	if (is_empty())
	{
		std::cerr << "Error! Your list is empty." << std::endl;
		return;
	}

	biNode* temp = tail;

	cout << "[ ";

	while (temp->prev != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}

	cout << temp->data << " ]" << endl;
	temp = NULL;

	delete temp;
}

void biList::clear()
{
	if (is_empty())
	{
		std::cerr << "Error! Your list is empty." << std::endl;
		return;
	}

	if (size <= 2)
	{
		head = tail = NULL;
	}
	else
	{
		biNode* cursor = head;

		for (int i = 0; i < size - 1; i++)
		{
			biNode* temp = cursor;
			cursor = cursor->next;
			delete temp;
		}
		delete cursor;
		head = tail = NULL;

	}

	size = 0;
}

biNode* biList::find(int index)
{
	if (index >= size)
		return nullptr;

	else
	{
		biNode* cursor = head;

		for (; index; index--)
			cursor = cursor->next;

		return cursor;
	}
}

void biList::splice_in(biList& T2, int index)
{
	biNode* cursor = T2.find(0);

	if (cursor)
	{
		while (cursor->next)
		{
			insert_after(index, cursor->data);
			cursor = cursor->next;
			index++;
		}
		insert_after(index, cursor->data);
	}
	cursor = NULL;
	delete cursor;
	
}

void biList::splice_out(biList& T2, int start, int end)
{
	biNode* frontCursor = find(start);
	biNode* backCursor = find(end);

	if (frontCursor && backCursor)
	{
		while (frontCursor->next != backCursor->next)
		{
			T2.push_back(frontCursor->data);
			frontCursor = frontCursor->next;
		}
		T2.push_back(backCursor->data);
		frontCursor = backCursor = NULL;
	}

	delete backCursor, frontCursor;
	
}


void biList::swap(int firstIndex, int secondIndex)
{
	if (is_empty())
	{
		std::cerr << "Error! Your list is empty." << std::endl;
		return;
	}

	biNode* firstItem = find(firstIndex);
	biNode* secondItem = find(secondIndex);

	
	if (firstItem && secondItem)
	{
		int temp = firstItem->data;
		firstItem->data = secondItem->data;
		secondItem->data = temp;
	}

}

void biList::sort()
{
	for (int count = 0; count < 10; count++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			int max_index = i;
			for (int j = i + 1; j < size; j++)
			{

				if (find(j)->data > find(i)->data)
				{
					max_index = j;
				}
			}
			if (i != max_index)
			{
				swap(i, max_index);
			}

		}
	}
	
	
}