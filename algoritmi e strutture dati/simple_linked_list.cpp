#include <iostream>
using std::cout;
using std::endl;

struct Node{
	int value;
	Node* next = nullptr;
};
struct List{
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
};

List create_list(int size)
{
	List list{size, nullptr, nullptr};
	Node* head = nullptr;
	Node* tail = nullptr;
	for(int i = 0; i < size; i++)
	{
		auto temp = new Node{i, nullptr};
		if(head == nullptr)
		{
			head = tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		list.head = head;
		list.tail = tail;
	}
	return list;
}
void print_list(List list)
{
	if(list.size != 0)
	{
		auto head = list.head;
		while(head)
		{
			cout << head->value << " ";
			head = head->next;
		}
		cout << endl << "Size=" << list.size << endl;
	}
	else
		cout << "list is empty!";
	
}
void insert_front(List& list, int value)
{
	if(list.size == 0)
	{
		auto new_node = new Node{ value, nullptr };
		list.head = list.tail = new_node;
	}
	else
	{
		auto new_node = new Node{ value, list.head };
		list.head = new_node;
	}
	list.size++;
}
void insert_back(List& list, int value)
{
	auto new_node = new Node{ value, nullptr };
	if(list.size == 0)
	{
		list.head = list.tail = new_node;
	}
	else
	{
		list.tail->next = new_node;
		list.tail = new_node;
	}
	list.size++;
}
void insert_elem(List& list, int pos, int value)
{
	if(pos < 0) return;
	if (pos == 0)
	{	
		cout << "insert_front\n";
		insert_front(list, value);
	}
	else if(pos == list.size)
	{
		cout << "insert_back\n";
		insert_back(list, value);
	}
	else if(pos > 0 && pos < list.size)
	{
		cout << "insert_elem\n";
		//Get previous element
		auto prev = list.head;
		for(int i = 0; i != pos-1 && (prev = prev->next); i++);

		auto new_node = new Node{ value, prev->next };
		prev->next = new_node;
		list.size++;
	}
}

void empty_list(List& list)
{
	Node* head = list.head;
	while(head)
	{
		auto next = head->next;
		delete head;
		
		head = next;
		list.size--;
	}
	list.head = list.tail = nullptr;
}
void delete_front(List& list)
{
	if(list.size == 0) return;
	if(list.size == 1)
	{
		delete list.head;
		list.head = list.tail = nullptr;
	}
	else
	{
		auto head = list.head;
		auto new_head = list.head->next;
		delete head;
		list.head = new_head;
	}


	list.size--;
}
void delete_back(List& list)
{
	if(list.size == 0) return;
	else if(list.size == 1)
	{
		delete list.head;
		list.head = list.tail = nullptr;
	}
	else
	{
		auto new_tail = list.head;
		while (new_tail->next && new_tail->next->next != nullptr)
			new_tail = new_tail->next;
		
		new_tail->next = nullptr;
		delete list.tail;
		list.tail = new_tail;
	}
	list.size--;

}

int main()
{ 
	List list = create_list(5);

	return 0;
}
