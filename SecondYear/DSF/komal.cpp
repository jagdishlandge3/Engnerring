#include<iostream.h>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

template<class t> class node
{
	public:
			t data;
			node<t> *next;
};

template<class t> class stack
{
	public:
        int a1;
        t n1,n2,h;
        
		node<t> *first,*p,*temp;
        
		int empty();
        void push(t x);
        t pop();
        void dis();
        t Top();
        
		stack()
        {
          first=NULL;
          a1=1;
        }
};

template<class t> t stack<t>::Top()
{
	p=first;
	
	if(empty()==0)
		return 0;
  
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p->data;
}

template<class t> int stack<t>::empty()
{
	if(first==NULL)
		return 0;
	else
		return 1;
}

template<class t> void stack<t>::push(t x)
{
	p=new node<t>;
	p->data=x;
	p->next=NULL;
  
	if(first==NULL)
		first=p;
	else
		temp->next=p;
	
	temp=p;
}

template<class t> t stack<t>::pop()
{ 
	if(empty()==0)
		cout<<"\n empty ";
	else
	{
		p=first;
  
		while(p->next!=NULL)
		{
			temp=p;
			p=p->next;
		}
		temp->next=NULL;
		
		if(p==first)
		{
			first=NULL;
		}
		return p->data;
  
		delete(p);
	}
}

template<class t> void stack<t>::dis()
{
	p=first;
	
	while(p!=NULL)
	{
		cout<<p->data;
		p=p->next;
	}
}

class convert
{
	public:
         char in[200], po[200],pe[200],x,a;
		 int c;

		 void infixtopostfix(char in[],char po[]);
	 
        void exp()
         {
           cout<<"\n Enter expression for convert ->:-->>  ";
           cin>>in;

		   infixtopostfix(in,po);
         }

		 int pri(char);
};

void convert::infixtopostfix(char in[],char po[])
{
		stack <char> s;
		int i=0,k=0,m,n,a=0,b;
		char ch,x;
		n=strlen(in);

		cout<<"\n\n\t"<<in;
		for(i=0; in[i]!='\0'; i++)
		{
			ch=in[i];

			if(isalnum(ch))
				po[k++]=ch;
			else
			{
				if(ch=='(')
					s.push(ch);
				else
				{
					if(ch==')')
					{
						while((x=s.pop())!='(')
							po[k++]=x;
					}
					else
					{
						while(pri(ch)<=pri(s.Top()) && ! s.empty())
						{
							x=s.pop();
							po[k++]=x;
						}
						s.push(ch);
					}
				}
			}
			/*po[k]='\0';
			cout<<"\n";
			s.dis();
			cout<<"\t";

			b=a++;
			for(m=a; m<=n; m++)
				cout<<in[m];
			for(i=0; i<b; i++)
			    cout<<" ";*/
			cout<<"\t"<<po;
		}
		while(!s.empty())
		{
			x=s.pop();
			po[k++]=x;
		}
		po[k]='\0';
		/*/cout<<"\n";
		s.dis();
		for(i=0; i<k+k; i++)
			cout<<" ";
		cout<<"\t"<<po;
		cout<<"\n\n";*/
}

int convert::pri(char x)
{
	switch(x)
	{
		case '$':
		case '#':
		case '^': return 3;

		case '%':
		case '*' :
		case '/'  : return 2;

		case '+' :
		case '-' : return 1;

		default: return 0;
	}
}

int main()
{
	convert c;

	c.exp();
    //c.infixtopostfix(char [], char []);

	getch();
}