#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node* next;
	node(int data)
	{
		this->data=data;
		next=NULL;
	}
};

class stack
{
	node* head;
	int size;
	public:
	stack()
	{
		head=NULL;
		size=0;
	}
	int getsize()
	{
		return size;
	}
	bool isempty()
	{
		return size==0;
	}
	void push(int element)
	{
		node* newnode=new node(element);
		newnode->next=head;
		head=newnode;
		size++;
	}
	int pop()
	{
		if(isempty())
		{
			return 0;
		}
		int ans=head->data;
		node* temp=head;
		head=head->next;
		delete temp;
		size--;
		return ans;
	}
	int top()
	{
		if(isempty())
		{
			return 0;
		}
		return head->data;
	}
	
};

void reverse(stack input,stack extra)
{
	if(!input.isempty())
	{
		int element=input.top();
		input.pop();
		extra.push(element);
		cout<<extra.top()<<" ";
		reverse(input,extra);
	}
}
int main()
{

	stack s1,s2;
	int i,n,element;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>element;
		s1.push(element);
	}	
	reverse(s1,s2);
}

















