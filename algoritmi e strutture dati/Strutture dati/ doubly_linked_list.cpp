#include <iostream>
using std::cout;
using std::endl;

struct Node{
	int value;
	Node* prev = nullptr;
	Node* next = nullptr;
};
struct List{
	int size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;
};

List create_list(int size)
{
	if(size <= 0) return List();

	Node* head = nullptr;
	Node* tail = nullptr;
	for(int i = 0; i < size; i++)
	{
		if(head == nullptr)
		{
			auto new_node = new Node{ i, nullptr, nullptr };
			head = tail = new_node;
		}
		else
		{
			auto new_node = new Node{ i, tail, nullptr };
			tail->next = new_node;
			tail = new_node;
		}
	}
	List list{ size, head, tail };
	return list;
}
void print_list(const List list)
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
		auto new_node = new Node{ value, nullptr, nullptr };
		list.head = list.tail = new_node;
	}
	else
	{
		auto new_node = new Node{ value, nullptr, list.head };
		list.head = new_node;
	}
	list.size++;
}
void insert_back(List& list, int value)
{
	if(list.size == 0)
	{
		insert_front(list, value);
	}
	else
	{
		auto new_node = new Node{ value, list.tail, nullptr };
		list.tail->next = new_node;
		list.tail = new_node;
		list.size++;
	}
	
}
void insert_after(List& list, Node* prev, int value)
{
	if(list.size == 0) return;
	if(prev == nullptr) return;
	if(prev == list.tail)
	{
		insert_back(list, value);
	}
	else
	{
		auto new_node = new Node{ value, prev, prev->next };
		prev->next->prev = new_node;		
		prev->next = new_node;
		list.size++;
	}
}

void delete_front(List& list)
{
	if(list.size == 0) return;
	if(list.size == 1)
	{
		delete list.tail;
		list.head = list.tail = nullptr;
		list.size = 0;
	}
	else
	{
		auto new_head = list.head->next;
		delete list.head;
		list.head = new_head;
		list.head->prev = nullptr;
		list.size--;
	}
}
void delete_back(List& list)
{
	if(list.size == 0) return;
	if(list.size == 1)
	{
		delete list.tail;
		list.head = list.tail = nullptr;
		list.size = 0;
	}
	else
	{
		auto new_tail = list.tail->prev;
		delete list.tail;
		list.tail = new_tail;
		list.tail->next = nullptr;
		list.size--;
	}
}
void delete_after(List& list, Node* prev)
{
	if(list.size == 0) return;
	if(prev == nullptr) return;
	if(prev->next == nullptr) return;

	auto to_delete = prev->next;
	auto next = to_delete->next;
	if(next != nullptr)
	{
		next->prev = prev;
		prev->next = next;
	}
	else
		prev->next = nullptr;
	
	delete to_delete;
	list.size--;
	
}
void empty_list(List& list)
{
	if(list.size == 0) return;
	auto head = list.head;
	while(head)
	{
		auto next = head->next;
		delete head;
		
		head = next;
		list.size--;
	}
	list.head = list.tail = nullptr;
}

Node* search(const List list, int value)
{
	if(list.size != 0)
	{
		auto head = list.head;
		while(head)
		{
			if(head->value == value)
				return head;
			head = head->next;
		}
	}

	return nullptr;
}

int main()
{ 
	List list = create_list(5);

	return 0;
}
