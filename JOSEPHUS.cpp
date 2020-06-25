#include<iostream>
#include<stdlib.h>
using std::cout;
using std::cin;
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
class CL
{
		node* head;
	public:
		CL():head(NULL){}
		void getData(int N)
		{
			for(int i=0;i<N;i++)
				create(i+1);
		}
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



