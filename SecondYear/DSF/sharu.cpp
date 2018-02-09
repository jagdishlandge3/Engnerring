#include<iostream>
using namespace std;
#include<string.h>
template<class t>
class node
{
  public:
        t data;
        node<t> *next;
};

template<class t>
class stack
{
 public:
        int a1;
        t n1,n2,h;
        node<t> *first,*p,*temp;
        int empty();
        void push(t x);
        t pop();
        void dis();
        t top();
        stack()
        {
          first=NULL;
          a1=1;
        }
};

template<class t>
t stack<t>::top()
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
template<class t>
int stack<t>::empty()
{
  if(first==NULL)
  {
   return 0;
  }
  else
   return 1;
}
template<class t>
void stack<t>::push(t x)
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
template<class t>
t stack<t>::pop()
{
  
  if(empty()==0)
  {
    cout<<"\n empty ";
  }
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
template<class t>
void stack<t>::dis()
{
  p=first;
  while(p!=NULL)
  {
    cout<<p->data;
    p=p->next;
  }
}
class cal
{
 public:
         int i,j,m,k,res;
	 char ea[20],op1,op2;
         char pa[30],st[30];
         void conpost();
         int pro(char x);
         void evl();
         void rev(char ea[]);
         void conpost2();
        void getexp()
         {
           cout<<"\n enter expression for convert\n ";
           cin>>ea;
           pa[1]='\0';
         }
};
void cal::rev(char ea[20])
{
 strcpy(st,ea);
 for(i=0;st[i]!='\0';i++);
 i--;
 j=0;
 for(k=i;k>=0;k--)
 {
   if(st[k]=='(')
   {
     ea[j++]=')';
   }
   else if(st[k]==')')
   ea[j++]='(';
   else 
   ea[j++]=st[k];
 }
ea[j]='\0';
cout<<"\n*********** "<<ea<<" *************\n";
}
void cal::conpost2()
{
  stack <char> s1;
  s1.first=NULL;
  k=0;
  for(i=0;ea[i]!='\0';i++)
  {
    s1.n1=ea[i];
    if((s1.n1=='+')||(s1.n1=='-')||(s1.n1=='*')||(s1.n1=='/')||(s1.n1=='^'))
   { 
     s1.n2=s1.top();
     if(pro(s1.n2)>pro(s1.n1))
     {
     pa[k]=s1.pop();
     k++;
     }
     s1.push(s1.n1);
   }
    else if(s1.n1=='(')
    s1.push(s1.n1);
    else if(s1.n1==')')
    {
      while(s1.top()!='(')
      {
        pa[k]=s1.pop();
        k++;
      }
      s1.pop();
    }
   else
    {
      pa[k]=s1.n1;
      k++;
    }
    if(ea[i+1]=='\0')
    {
     while(s1.empty()==1)
     {
       s1.h=s1.pop();
       if(s1.h=='(')
           break;
       pa[k++]=s1.h;
     }
    }
   pa[k]='\0';
   cout<<"\n"<<ea<<"\t  ";
   s1.dis();
   cout<<"\t  ";
   cout<<pa<<"\n";
  }
}
void cal::evl()
{
  stack <int> s2;
  s2.first=NULL;
 for(i=0;pa[i]!='\0';i++)
 {
   
 if((pa[i]>='a')&&(pa[i]<='z')||(pa[i]>='A')&&(pa[i]<='Z'))
 {
   cout<<"\n Enter value for "<<pa[i]<<" ";
   cin>>s2.h;
   s2.push(s2.h);
 }
 else
 {
   s2.n2=s2.pop();
   s2.n1=s2.pop();
   switch(pa[i])
   {
     case'^':res=1;
             for(k=0;k<s2.n2;k++)
             res=res*s2.n1;
             cout<<res;
             s2.push(res);
             break;
     case'+':s2.push(s2.n1+s2.n2);
             break;
     case'-':s2.push(s2.n1-s2.n2);
             break;
     case'/':s2.push(s2.n1/s2.n2);
             break;
     case'*':s2.push(s2.n1*s2.n2);
             break;      
   }
 }
}

 cout<<"\n solution is "<<s2.top()<<endl;
}
int cal::pro(char x)
{
  switch(x)
  {
    case'^': return 3;
    case'/':
    case'*':return 2;
    case'+':
    case'-':return 1;
    default:return 0;
           
  }
}
void cal::conpost()
{
  stack <char> s1;
  s1.first=NULL;
  k=0;
  for(i=0;ea[i]!='\0';i++)
  {
    s1.n1=ea[i];
    if((s1.n1=='+')||(s1.n1=='-')||(s1.n1=='*')||(s1.n1=='/')||(s1.n1=='^'))
   { 
     s1.n2=s1.top();
     if(pro(s1.n2)>=pro(s1.n1))
     {
     pa[k]=s1.pop();
     k++;
     }
     s1.push(s1.n1);
   }
    else if(s1.n1=='(')
    s1.push(s1.n1);
    else if(s1.n1==')')
    {
      while(s1.top()!='(')
      {
        pa[k]=s1.pop();
        k++;
      }
      s1.pop();
    }
   else
    {
      pa[k]=s1.n1;
      k++;
    }
    if(ea[i+1]=='\0')
    {
     while(s1.empty()==1)
     {
       s1.h=s1.pop();
       if(s1.h=='(')
           break;
       pa[k++]=s1.h;
     }
    }
   pa[k]='\0';
   cout<<"\n"<<ea<<"\t  ";
   s1.dis();
   cout<<"\t  ";
   cout<<pa<<"\n";
  }
}
int main()
{
  
  cal c1;
  int c;
  char ans;
  do
  {
  cout<<"\n 1-infix to postfix conversion \n 2-postfix evaluation \n 3-infix to prefix conversion ";
  cin>>c;
  switch(c)
  {
  case 1:c1.getexp();
         c1.conpost();
         break;
  case 2:c1.getexp();
         c1.conpost();
         c1.evl();
         break;
  case 3:c1.getexp();
         c1.rev(c1.ea);
         c1.conpost2();
         c1.rev(c1.pa);
  }
  cout<<"\n do u want to continue(y/n) ";
  cin>>ans;
}while(ans=='y');
  return 0;
}