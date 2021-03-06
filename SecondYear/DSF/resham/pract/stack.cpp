#include<iostream.h>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>



class node
{
  public:
        char data;
        node *next;
};

class stack
{
	 public:
        node  *top;

	     stack()
        {
          top=NULL;
        }

        int empty();
        void push(char );
        char pop();
        void dis();
        char Top();
};

char stack::Top()
{
	node *p=top;

	if(empty()==1)
		return -1;
	else
	   return p->data;
}

int stack::empty()
{
	if(top==NULL)
		return 1;
	else
		return 0 ;
}

void stack::push(char x)
{
	node *p;
	p=new node;
	p->data=x;
	p->next=top;
	top=p;	
}

char stack::pop()
{
	char x;
	node *p;
	
	if(empty()==1)
		return -1;
	else
	{
		p=top;
		top=top->next;
		x=p->data;
		delete p;
		return x;
	}
}

void stack::dis()
{
	node *p=top;

	while(p!=NULL)
	{
		  cout<<p->data;
		  p=p->next;
	}
}

class convert
{
	public:
         char in[200], po[200],pe[200];
		 int c;

		 void infixtopostfix(char in[],char po[]);
		 void infixtoprefix(char in[],char pe[]);
		 void prefix(char in[],char pe[]);
		 void Epostfix(char po[]);
		 void Eprefix(char pe[]);
		 int evaluate(char,int,int);
		 int pri(char);
	 
         void exp()
         {
		     do
		    {
			    cout<<"\n\t1.Infix To Postfix\n\t2.Infix To Prefix\n\t3.Postfix Evalution\n\t4.Prefix Evaluation\n\t5.Exit\n";
			    cout<<"\n\tEnter Your choice:";
			    cin>>c;

			    switch(c)
		       {
				   case 1:
					  cout<<"\n Enter expression for convert to Postfix  -->>   ";
					  cin>>in;

					  infixtopostfix(in,po);
					  cout<<"\nInfix:->> "<<in;
					  cout<<"\nPostfix->> "<<po<<"\n\n";
					  break;

			       case 2:
					  cout<<"\n Enter expression for convert to Prefix  -->>  ";
					  cin>>in;

					  infixtoprefix(in,pe);
					  cout<<"Infix:->> "<<in;
					  cout<<"\nPrefix:->> "<<pe<<"\n\n";
				 	  break;
					
				  case 3:
					   cout<<"\n Enter Postfix expression to Evalute  -->>  ";
					   cin>>po;

					   Epostfix(po);
				       break;
				
				  case 4:
					   cout<<"\n Enter Postfix expression to Evalute  -->>  ";
					   cin>>pe;

					   Eprefix(pe);
					   break;

				  case 5:
					    break;
		      }
		   }while (c!=5);
        }
};

void convert :: Epostfix(char po[])
{
        stack s;
		int i,ch1,ch2,n;
		char x;

		for(i=0; po[i]!='\0'; i++)
		{
			x=po[i];

			if(isalpha(x))
			{
			     cout<<"\n\tEnter the value of "<<x<<" : ";
				 cin>>n;

				 s.push(n);
			}
			else if(isdigit(x))
				s.push(x-48);
			else
			{
			     ch2=s.pop();
				 ch1=s.pop();
				 n=evaluate(x,ch1,ch2);
				 s.push(n);
			}
		}
		n=s.pop();
		cout<<"\n\n\tValue of Expression = "<<n<<"\n\n";
}

void convert :: Eprefix(char pe[])
{
		stack s;
		int i,ch1,ch2,n;
		char x;

		for(i=strlen(pe)-1; i>=0; i--)
		{
			x=pe[i];

			if(isalpha(x))
			{
			     cout<<"\n\tEnter the value of "<<x<<" : ";
				 cin>>n;

				 s.push(n);
			}
			else if(isdigit(x))
				s.push(x-48);
			else
			{
			     ch1=s.pop();
				 ch2=s.pop();
				 n=evaluate(x,ch1,ch2);
				 s.push(n);
			}
		}
		n=s.pop();
		cout<<"\n\n\tValue of Expression = "<<n;
}

int  convert :: evaluate(char x,int ch1,int ch2)
{
	if(x=='+')
		return(ch1+ch2);
	if(x=='-')
		return(ch1-ch2);
	if(x=='*')
		return(ch1*ch2);
	if(x=='/')
		return(ch1/ch2);
	if(x=='%')
		return(ch1%ch2);
	if(x=='^')
	{
	   int i,n=1;

	   for(i=1; i<=ch2; i++)
	   {
              n=ch1*n;
	   }
	   return(n);
	}
	if(x=='$')
	{
	   int i,n=1;

	   for(i=1; i<=ch2; i++)
	   {
              n=ch1*n;
	   }
	   return(n);
	}
	if(x=='#')
	{
	   int i,n=1;

	   for(i=1; i<=ch2; i++)
	   {
              n=ch1*n;
	   }
	   return(n);
	}
}

void convert::infixtopostfix(char in[],char po[])
{
		stack s;
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
						while(pri(ch)<=pri(s.Top()) && !s.empty())
						{
							x=s.pop();
							po[k++]=x;
						}
						s.push(ch);
					}
				}
			}
			
			po[k]='\0';
			cout<<"\n";
			s.dis();
			cout<<"\t";

			b=a++;
			for(m=a; m<=n; m++)
				cout<<in[m];
			for(i=0; i<b; i++)
			    cout<<" ";
			cout<<"\t"<<po;
		}
		while(!s.empty())
		{
			x=s.pop();
			po[k++]=x;
		}
		po[k++]='\0';
		cout<<"\n";
		s.dis();
		for(i=0; i<k+k; i++)
			cout<<" ";
		cout<<"\t"<<po;
		cout<<"\n\n";
}

void convert :: infixtoprefix(char in[],char pe[])
{
	stack s;
	int i=0,k=0;
	char ch,temp[200];

	for(i=strlen(in)-1; k>=0,i>=0; i--,k++)
	{
		temp[k]=in[i];
	}
	temp[k]='\0';

	for(i=0; temp[i]!='\0'; i++)
	{
		if(temp[i]=='(')
			temp[i]=')';
		else
			if(temp[i]==')')
				temp[i]='(';
	}

	prefix(temp,pe);

	for(i=0, k=strlen(pe)-1; i<k; i++,k--)
	{
		ch=pe[i];
		pe[i]=pe[k];
		pe[k]=ch;
	}
}

void convert :: prefix(char in[],char pe[])
{
	stack s;
	int i=0,k=0,m,n,a=0,b;
	char ch,x;
	n=strlen(in);

	cout<<"\n\n\t"<<in;
	for(i=0; in[i]!='\0'; i++)
	{
		ch=in[i];

		if(isalnum(ch))
			pe[k++]=ch;
		else
		{
			if(ch=='(')
				s.push(ch);
			else
			{
				if(ch==')')
				{
					while((x=s.pop())!='(')
						pe[k++]=x;
				}
				else
				{
					while(pri(ch)<pri(s.Top()) && !s.empty())
					{
						x=s.pop();
						pe[k++]=x;
					}
					s.push(ch);
				}
			}
		}
		pe[k]='\0';
		cout<<"\n";
		s.dis();
		cout<<"\t";

		b=a++;
		for(m=a; m<=n; m++)
			cout<<in[m];
		for(i=0; i<b; i++)
		      cout<<" ";
		cout<<"\t"<<pe;
	}
	while(!s.empty())
	{
		x=s.pop();
		pe[k++]=x;
	}
	pe[k]='\0';
	cout<<"\n";
	s.dis();
	for(i=0; i<k+k; i++)
		cout<<" ";
	cout<<"\t"<<pe;
	cout<<"\n\n";
}

int convert :: pri(char x)
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
}
