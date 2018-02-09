#include<iostream>
#include<fstream.h>

using namespace std;  

class Filedata
{
   public:
	int rollno;
	long int contact;
	char name[20],year;
	
	void getdata();
	{
	   cout<<"\nEnter name:";
  	   cin>>name;
  	   cout<<"\nEnter roll no:\n";
	   cin>>rollno;
	   cout<<"\nEnter contact no:\n";
	   cin>>contact;
	   cout<<"\nEnter Year:\n";
	   cin>>year;
	}

	void dis(int r,char na[20])
	{
	   cout<<"\n"<<r<<"\t"<<na;
	}
}s[20],s1;

class seqfile
{
    public:
	int n,no,i,r,x,j;
	char na[20];
	
	void accept();
	void display();
	void modify();
	void delet();
	void add();
};

void seqfile::accept()
{
	cout<<"\nEnter how many records you want to enter:\n";
	cin>>n;
	
	fstream file1;
	file1.open("mayur.txt",ios::out);

	for(i=0;i<n;i++)
	{
	   s[i].getdata();
	   file1<<s[i].rollno<<"\t";
	   file1<<s[i].name<<endl;
	}
	file1.close();
}

void seqfile::display()
{
	fstream file2;
	file2.open("mayur.txt",ios::in);
	cout<<"\nr.no     Name";

	for(i=0;i<n;i++)
	{
	  file2>>r;
	  file2>>na;
	  s1.dis(r,na);
	}
  	file2.close();
}

void sfile::modify()
{
	fstream file3;
	file3.open("mayur.txt",ios::in);
	fstream filet;
	filet.open("mayur1.txt",ios::out);

	cout<<\nEnter which roll no you want to modify:\n";
	cin>>x;

	for(i=0;i<n;i++)
	{
	   if(s[i].rollno==x)
	   {
		file3>>r;
		file3>>na;
		filet<<na<<endl;
	   }
 	}
	file3.close();
	filet.close();
	fstream filem;
	filem.open("mayur.txt",ios::out);
	fstream filett;
	filett.open("mayur1.txt",ios::in);

	for(i=0;i<n;i++)
	{
	   filett>>r;
	   filem<<r<<"\t";
	   filett>>na;
	   filem<<na<<endl;
	}
	filem.close();
	filett.close();
}

void seqfile::delet()
{
	fstream file4;
	file4.open("mayur.txt",ios::in);
	fstream filed;
	filed.open("mayur1.txt",ios::out);

	cout<<"\nEnter which roll no. you want to delete:\n";
	cin>>x;

	for(i=0;i<n;i++)
	{
	   if(s[i].rno==x)
	   {
		file4>>r;
		file4>>na;
	   }
	   else
 	   {
		file4>>r;
		filed<<r<<"\t";
		file4>>na;
		filed<<na<<endl;
	   }
	}
	n=n-1;
	file4.close();
	filed.close();
	fstream file5;
	file5.open("mayur.txt",ios::out);
	fstream filedd;
	filedd.open("mayur1.txt",ios::in);

	for(i=0;i<n;i++)
	{
	   filedd>>r;
	   file5<<r<<"\t";
	   filedd>>na;
	   file5<<na<<endl;
	}
	file5.close();
	filedd.close();
}


void sfile::add()
{
	fstream file6;
	file6.open("mayur.txt",ios::in);
	fstream filea;
	filea.open("mayur1.txt",ios::out);

	cout<<"\n Enter roll no.:\n  ";
	cin>>x;

	for(i=0;i<n;i++)
	{
	   if((s[i].rno<x)&&(s[i+1].rno>x))
	   {
		file6>>r;
		filea<<r<<"\t";
		file6>>na;
		filea<<na<<endl;
		
		cout<<"\nEnter name:\n ";
		cin>>na;

		filea<<x<<"\t";
		filea<<na<<endl;
	   }
	   else
	   {
		file6>>r;
		filea<<r<<"\t";
		file6>>na;
		filea<<na<<endl;
	   }
	}
	if(i==n)
	{
 	   file6>>r;
	   filea<<r<<"\t";
	   file6>>na;
	   filea<<na<<endl;
	}
	n=n+1;
	file6.close();
	filea.close();
	fstream file61;
	file61.open("mayur.txt",ios::out);
	fstream fileaa;
	fileaa.open("mayur1.txt",ios::in);

	for(i=0;i<n;i++)
	{
	   fileaa>>r;
	   file61<<r<<"\t";
	   fileaa>>na;
	   file61<<na<<endl;
	}
}


void main()
{
	seqfile sf1;
	int c;
	char ans;

	sf1.accept();
	
	do
	{
		cout<<"\n 1- display \n 2-modify \n 3- delete \n 4-add \n Enter ur choice ";
		cin>>c;

		switch(c)
		{
		   case 1: sf1.display();
			   break;
		   case 2: sf1.modify();
			   sf1.display();
			   break;
		   case 3: sf1.dele();
			   sf1.display();
			   break;
		   case 4: sf1.add();
			   sf1.display();
		 	   break;
		}
		cout<<"\n Do u want to continue(y/n) ";
		cin>>ans;
	}while(ans=='y');
}


