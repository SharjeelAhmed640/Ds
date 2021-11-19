#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		data = 0;
		this->next = 0;
	}
	Node(int d)
	{
		data = d;
		this->next = 0;
	}
};
class stack
{
	Node *st;
	bool reverse(Node *p)
	{
		if (p != NULL)
		{
			reverse(p->next);
			cout << p->data << " ";
		}
	}

public:
	stack(Node *top)
	{
		st = top;
	}
	stack()
	{
		st = 0;
	}
	void push(int data)
	{
		if (!isFull())
		{
			cout << "Stack overflow cannot push" << endl;
			return;
		}

		Node *ptr = new Node(data);
		Node *temp = st;
		ptr->next = temp;
		st = ptr;

		cout << "Element pushed " << data << endl;
	}
	int pop()
	{
		if (this->isEmpty())
		{
			cout << "Stack is empty cannot pop" << endl;
		}
		else
		{

			Node *temp = st;
			st = st->next;

			int data = temp->data;
			delete temp;

			return data;
		}
	}
	bool isFull()
	{
		Node *temp = new Node(1);
		if (temp == NULL)
			return false;
		return true;
	}
	bool isEmpty()
	{
		if (st == NULL)
			return true;
		return false;
	}

	void rev()
	{
		cout << "Printing in backward direction" << endl;
		Node *temp = st;
		reverse(temp);
		cout << endl;
	}
	void triversal()
	{
		cout << "Printing in forward direction" << endl;
		Node *temp = st;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{

	stack st;
	int data;
	int choose = 1;
	while (choose != 0)
	{
		cout << endl
			 << endl
			 << "Press 1 for Pushing element" << endl
			 << "Press 2 for poping element" << endl
			 << "Press 3 for printing in backward direction" << endl
			 << "Press 4 for printing in forward direction" << endl
			 << "Press 5 to find if stack is empty?" << endl
			 << "Press 6 to find if stack is full?" << endl
			 << "Press 0 to exit" << endl
			 << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Enter data : ";
			cin >> data;
			st.push(data);
			break;
		case 2:
			data = st.pop();
			if (!st.isEmpty())
				cout << "Poped element : " << data << endl;
			break;
		case 3:
			st.rev();
			break;
		case 4:
			st.triversal();
			break;
		case 5:
			if (st.isEmpty())
				cout << "stack is empty" << endl;
			else
				cout << "Stack is not empty" << endl;
			break;
		case 6:
			if (!st.isFull())
				cout << "stack is Full" << endl;
			else
				cout << "Stack is not full" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Enter valid input" << endl;
			break;
		}
	}
	return 0;
}