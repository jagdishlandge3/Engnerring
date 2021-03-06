#include<iostream.h>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define MAX 200

class stack
{
	char data[MAX];
	int top;

	public:
		stack()
		{
			top=-1;
		}

		char Top()
		{
			return data[top];
		}

		int empty()
		{
				if(top==-1)
					return 1;
				else
					return 0;
		}

		int full()
		{
				if(top==MAX-1)
					return 1;
				else
					return 0;
		}

		void push(int x)
		{
			top=top+1;
			data[top]=x;
		}

		char pop()
		{
			int x;

			x=data[top];
			top=top-1;

			return(x);
		}

		void dis()
		{
			int i;
			for(i=0; i<=top; i++)
			{
				cout<<data[i];
			}
		}
};

int pri(char x)
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

void convert(char in[],char pe[]);

void infixtoprefix(char in[],char pe[])
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

	convert(temp,pe);

	for(i=0, k=strlen(pe)-1; i<k; i++,k--)
	{
		ch=pe[i];
		pe[i]=pe[k];
		pe[k]=ch;
	}
}
	
void convert(char in[],char pe[])
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

void infixtopostfix(char in[],char po[])
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
	po[k]='\0';
	cout<<"\n";
	s.dis();
	for(i=0; i<k+k; i++)
		cout<<" ";
	cout<<"\t"<<po;
	cout<<"\n\n";
}

void main()
{
	char in[200], po[200],pe[200];
	int c;

	cout<<"Exprssion";
	cin>>in;

	do
	{
		cout<<"\n\t1.Infix To Postfix\n\t2.Infix To Prefix\n";
		cout<<"\tEnter Your choice:";
		cin>>c;

		switch(c)
		{
			case 1:
					infixtopostfix(in,po);
					cout<<"\nInfix:->> "<<in;
					cout<<"\nPostfix->> "<<po<<"\n\n";
					break;

			case 2:
					infixtoprefix(in,pe);
					cout<<"Infix:->> "<<in;
					cout<<"\nPrefix:->> "<<pe<<"\n\n";
					break;

			default:
				cout<<"Inalid choice:";
		}
	}while (c<=2);
   
getch();
}