#include <iostream>
using std::cout;
using std::endl;

struct Node{
	int value = 0;
	Node* next = nullptr;
};


bool is_empty(const Node* head)
{
	return (head == nullptr);	
}
Node* get_tail(Node* head)
{
	if(is_empty(head))
		return nullptr;
	
	auto tail = head;
	while(true)
	{
		if(tail->next == nullptr)
			break;
		tail = tail->next; 
	}
	return tail;
}

Node* create_stack()
{	
	return nullptr;
}
void push(Node*& head, int value)
{
	Node* node = new Node{value, nullptr};
	if(is_empty(head))
	{
		head = node;
		cout << "First push!" << endl;
	}
	else
	{	
		Node* tail = get_tail(head);
		
		
		tail->next = node;
		tail = tail->next;
		cout << "Push back" << endl;
	}
}
int pop(Node*& head)
{
	if(is_empty(head))
	{
		cout << "Stack is empty" << endl; 
		return -1;
	}
		
	
	int val;
	auto temp = head;
	//Size == 1
	if(temp->next == nullptr)
	{
		val = head->value;
		head = nullptr;
	}
	else
	{
		while(temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		val = get_tail(head)->value;
		temp->next = nullptr;
	}
	return val;
}
int top(Node* head)
{
	if(is_empty(head))
	{
		cout << "stack is empty!" << endl;
		return -1;
	}
	auto tail = get_tail(head);
	return tail->value;
}

void display(const Node* head)
{
	if(is_empty(head))
	{
		cout << "stack is empty!" << endl;
		return;
	}

	auto temp = head;
	while(temp != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}


int main()
{
	Node* head = create_stack();
	push(head, 0);
	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 5);
	display(head);
	pop(head);
	pop(head);
	pop(head);
	display(head);

	return 0;
}