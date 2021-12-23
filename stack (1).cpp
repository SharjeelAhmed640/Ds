#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node()
		{
			data=0;
			this->next=0;
		}
		Node(int d)
		{
			data=d;
			this->next=0;
		}
};
class stack{
	Node *st;
		bool reverse(Node* p)
		{
			if(p!=NULL)
			{
				reverse(p->next);
				cout<<p->data<<" ";
			}
		}
	public:
		stack(Node *top)
		{
			st=top;
		}
		stack()
		{
			st=0;
		}
		void push(int data)
		{
			if(!isFull())
			{
			cout<<"Stack overflow cannot push"<<endl;
			return;
		}
			
			Node *ptr=new Node (data);
			Node *temp=st;
			ptr->next=temp;
			st=ptr;
			
			cout<<"Element pushed "<<data<<endl;
		}
		int pop()
		{
			if(this->isEmpty())
			{
				cout<<"Stack is empty cannot pop"<<endl;
			}
			else{
			
			Node *temp=st;
			st=st->next;
		
			int data=temp->data;
			delete temp;
		
			return data;
		}
		}
		bool isFull()
		{
			Node *temp=new Node(1);
			if(temp==NULL)
				return false;
			return true;
		
		}
		bool isEmpty()
		{
			if(st==NULL)
			return true;
			return false;
		}
		
		void rev()
		{
			cout<<"Printing in backward direction"<<endl;
			Node *temp=st;
			reverse(temp);
			cout<<endl;
		}
		void triversal()
		{
			cout<<"Printing in forward direction"<<endl;
			Node *temp=st;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}cout<<endl;
		}
	
	
};
int main()
{

	stack st;
	for(int i=0;i<10;i++)
	{
		if(st.isEmpty())
		cout<<"stack is empty"<<endl;
		st.push(i);
		if(!st.isFull())
		cout<<"stack is FULL"<<endl;
	}
	st.rev();
	st.triversal();
;	int data;
	for(int i=0;i<10;i++)
	{
		if(st.isEmpty())
		cout<<"stack is empty"<<endl;
		data=st.pop();
		
		cout<<"Popoed element : "<<data<<endl;
		if(!st.isFull())
		cout<<"stack is FULL"<<endl;
	}
	return 0;
}
