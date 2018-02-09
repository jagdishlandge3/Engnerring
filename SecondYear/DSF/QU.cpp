#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

	struct node
	{
		int data;
	    node *next ;	
	};

class pq
{
	node *head,*p,*q;

	public:
		pq()
		{
			head=NULL;
	    }

		//~pq();
		void insert(int x);
		int Delete();
		int empty();
		void display();
};

int pq::empty()
{
     if(head==NULL)
		 return 1;
	 else
		 return 0;
}

void pq::insert(int x)
{
	node *p,*q;
	p=new node;
	p->data=x;
	p->next=NULL;

	if(head==NULL)
		head=p;
	else
	{
		if(x > head->data)
		{
			p->next=head;
			head=p;
		}
		else
		{
			q=head;

			while(q->next !=NULL && x < q->next->data)
				q=q->next;

			p->next=q->next;
			q->next=p;
		}
	}
}

int pq::Delete()
{
	int x;
	node *p;
	p=head;
	x=p->data;
	head=p->next;

	delete p;
	return(x);
}

/*pq::~pq()
{
	node *p;
	p=head;

	while(head !=NULL)
	{
		p=head;
		head=head->next;

		delete p;
	}
}*/

void pq::display()
{
    node *temp=head;
	
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}
}

void main()
{
	int x,choice;
	char c;

	pq q;

	do
	{
		cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\n";
		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					  cout<<"\nEnter the element to be inserted : ";
					  cin>>x;

					  q.insert(x);
					  break;

			case 2:
					  if(q.empty())
				      {
							cout<<"\nQueue is empty....";
							break;
					  }
					  x=q.Delete();
					  cout<<"\nElement = "<<x;
					  break;
					 
			case 3:
					  q.display();
					  break;
					
			default:
					  cout<<"\n\t****Invalid Choice....*****\t\t\n\n";
				      break;
		}
		cout<<"\nDo U want to continue(Y/N) : ";
		cin>>c;
	}while (c=='Y' || c=='y');
}
