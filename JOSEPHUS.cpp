#include<iostream>
#include<stdlib.h>
using std::cout;
using std::cin;

// Node Class to create LinkedList
class node
{
	int data;
	node* next;
	node(int data)
	{
		this->data=data;
		next=NULL;
	}
	friend class CL;
};

// Circular Linked List Class
class CL
{
		node* head;
	public:
		// Constructor, initialize 1st node i.e. "head" node to NULL
		CL():head(NULL){}
	
		// Input
		void getData(int N)
		{
			for(int i=0;i<N;i++)
				create(i+1);
		}
	
		// Create Circular LinkedList
		void create(int i)
		{
			node* p=new node(i);
			if(!head)
			{
				head=p;
				head->next=head;
				return;
			}
			node* q=head;
			do
				q=q->next;
			while(q->next!=head);
			q->next=p;
			p->next=head;
		}
	
		// Solve Josephus Problem
		void Josephus(int K,int N)
		{
			node* p,*q;
			p=q=head;
			for(int i=0;i<N-1;i++)
			{
				for(int j=0;j<K-1;j++)
				{
					q=p;
					p=p->next;
				}
				q->next=p->next;
				cout<<p->data<<" has been Killed\n";
				delete p;
				p=q->next;
			}
			head=p;
			cout<<"\nLast Man Standing --> "<<head->data;
		}
		
		// Print Circular LinkedList
		void show(char* msg)
		{
			cout<<msg;
			node* q=head;
			do{
				cout<<q->data<<"\t";
				q=q->next;
			}while(q!=head);
			cout<<"\n\n";
		}
};
main()
{
	cout<<"\nHow Many People? --> ";
	int N;
	cin>>N;
	if(N<0)
	{
		cout<<"\nInvalid Input...\n";
		exit(1);
	}
	CL cl;
	cl.getData(N);
	cl.show("\nAll standing in a Circle :: \n");
	cout<<"\nPerson to be Killed in the Circle --> ";
	int K;
	cin>>K;
	if(K<0)
	{
		cout<<"\nInvalid Input...\n";
		exit(1);
	}
	cl.Josephus(K,N);
}

/*
Output ::

How Many People? --> 14
All standing in a Circle :: 
1	2	3	4	5	6	7	8	9	10	11	12	13	14	


Person to be Killed in the Circle --> 2
2 has been Killed
4 has been Killed
6 has been Killed
8 has been Killed
10 has been Killed
12 has been Killed
14 has been Killed
3 has been Killed
7 has been Killed
11 has been Killed
1 has been Killed
9 has been Killed
5 has been Killed

Last Man Standing --> 13


*/

