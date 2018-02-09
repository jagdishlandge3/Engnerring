#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 
struct node
{
	int priority;
	char name[30];
	struct node *next;

	void get()
	{
		cout<<"\n\tEnter the name of patient:";
		cin>>name;
	}
};

class PQ
{
    node *front,*rear;

    public:
        PQ()
        {
            front = rear = NULL;
        }

		int empty();
        void insert();
        void del();
        void display();
};

int PQ::empty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}

void PQ::insert()
{
	node *temp = new node;
	temp->get();
	
	if (empty())
		front=rear=temp;
	else
	{
		rear->next=temp;
		rear=temp;
	}
}

void PQ::del()
{
	node *temp;
	
	if(empty())
		cout<<"Queue Underflow\n";
	else
	{
		if(front==rear)
			front=rear=NULL;
		else
		{
			temp = front;
			cout<<"\n\tThe name of patient : "<<temp->name;
			front = front->next;
			cout<<"\n\tgot the treatment \n";
			delete temp;
		}
	 }
}

void PQ::display()
{
	node *temp = front;
	
	if (empty())
		cout<<"Queue is empty\n";
	else
	{
		while(temp != NULL)
		{
			cout<<"\t"<<temp->name<<"\n";
			temp = temp->next;
		}
	 }
}

void type(int pri)
{
	if(pri==0)
		cout<<"\n\tSerious patient Queue\n";
	else if(pri==1)
		cout<<"\n\tMedium  patient Queue\n";
	else 
		cout<<"\n\tGeneral patient Queue\n";
}

void main()
{
    int choice, priority,i;
	char c;
    PQ q[3];
	
    do
    {
        cout<<"\n\t1.Insert\n\t2.Delete\n\t3.Display\n";
        cout<<"\n\tEnter your choice : "; 
        cin>>choice;

        switch(choice)
        {
			case 1:
					cout<<"\n\tEnter the  priority :\n\t0. Serious\n\t1.Medium\n\t2.General: ";
					cin>>priority;
					
					q[priority].insert();
					break;
			case 2:
					for(i=0; i<3; i++)
					{
						type(i);
						q[i].del();
					}
					break;
			case 3:
					for(i=0; i<3; i++)
					{
						type(i);
						q[i].display();
					}
					break;
			default :
					cout<<"\n\t****Invalid Choice....*****\t\t\n\n";
					break;
        }
		cout<<"\nDo U want to continue(Y/N) : ";
		cin>>c;
    }while(c=='Y' || c=='y');
}