#include<iostream.h>
#include<conio.h>

class sample
{
	int x,y;
	public:
		void display()
	{
	    cout<<"\n\nX:"<<x;
		cout<<"\n\nY:"<<y;
	}
};

void main()
{
   sample s;
   s.display();
}