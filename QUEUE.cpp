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
class Queue{
	Node *pos;
	public:
		Queue(Node *n)
		{
			pos=n;
		}
		Queue()
		{
			pos=0;
		}
		void queue(int data)
		{
			if(!isFull())
			{
			cout<<"Queue is full cannot Queue another value"<<endl;
			return;
		}
			
			Node *ptr=new Node (data);
			Node *temp=pos;
			ptr->next=temp;
			pos=ptr;
			
			cout<<"Element pushed "<<data<<endl;
		}
		int Dequeue()
		{
			if(this->isEmpty())
			{
				cout<<"Stack is empty cannot pop"<<endl;
			}
			else{
			int data;
			Node *temp=pos;
			Node *ptr=pos;//  
			if(temp->next==NULL)
			{
				data=temp->data;
				delete temp;
				pos=NULL;
				return data;
								  }                      
			while(temp->next->next!=NULL)// 0 1 2 3 4 5
			{
			temp=temp->next;
			
		}
			 data=temp->next->data;
			temp->next=NULL;
			delete temp->next;
		//	ptr->next=NULL;
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
			if(pos==NULL)
			return true;
			return false;
		}
		void triversal()
		{
			Node *temp=pos;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	
};
int main()
{

	Queue q;
	for(int i=0;i<10;i++)
	{
		if(q.isEmpty())
		cout<<"Queue is empty"<<endl;
		q.queue(i);
		if(!q.isFull())
		cout<<"Queue is FULL"<<endl;
	}
	q.triversal();
	int data;
	for(int i=0;i<10;i++)
	{
		if(q.isEmpty())
		cout<<"Queue is empty"<<endl;
		data=q.Dequeue();
		
		cout<<"Dequeued element : "<<data<<endl;
		if(!q.isFull())
		cout<<"Queue is FULL"<<endl;
	}

	
		
	return 0;
}
