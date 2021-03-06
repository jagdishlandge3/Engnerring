#include<iostream>
#include<stdlib.h>

using namespace std;

struct tree
{
	char data;
	tree *left,*right;

	tree(char c)
	{
		data=c;
		left=right=NULL;
	}
};

class stack
{
	tree *stk[30];
	int top;

	public:
		stack()
		{
		   top=-1;
		}

		int empty();

		void push(tree*);
		tree* pop();
};

int stack::empty()
{
	if(top==-1)
	   return 1;
	return 0;
}

int stack::full()
{
	if(top==29)
	   return 1;
	return 0;
}

void stack::push(tree *d)
{
	if(!full())
	   stk[++top]=d;
}

tree* stack::pop()
{
	tree *temp=stk[top];
	top--;

	return temp;
}

tree *create()
{
	char str[100];
	int i=0;
	stack s;
	
	cout<<"\n\tEnter the postfix expreesion :";
	cin>>str;

	while(str[i]!='\0')
	{
		tree *node=new tree(str[i]);

		if(isalnum(str[i]))
		   s.push(node);
		else
		{
		   node->right=s.pop();
		   node->left=s.pop();
	
		   s.push(node);
		}
		i++;
	}
	return s.pop();
}

void inorder(tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data;

		inorder(root->right);
	}
}

void preorder(tree *root)
{
	if(root!=NULL)
	{
		cout<<root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data;
	}
}

void nonpre(tree *root)
{
	stack s;
	while(!s.empty()||root!=NULL)
	{
	   	while(root!=NULL)
	   	{
		   cout<<root->data;
		   s.push(root);
		   root=root->left;
		}
		root=s.pop();
		root=root->right;
	}
}

void nonrin(tree *root)
{
	stack s;
	while(!s.empty()||root!=NULL)
	{
		while(root!=NULL)
		{
		   s.push(root);
		   root=root->left;
		}
		root=s.pop();
		cout<<root->data;
		root=root->right;
	}
}

void nonpost(tree *root)
{
	stack s;
	int i=0;
	char str[100];

	while(!s.empty()||root!=NULL)
	{
		while(root!=NULL)
		{
		    str[i++]=root->data;
		    s.push(root);
		    root=root->right;
		}
		root=s.pop();
		root=root->left;
	}
	while(--i>=0)
	   cout<<str[i];
}

int main()
{
	struct tree *root=NULL;
	char ch;
	int choice;

	root=create();
	
	do
	{
		cout<<"1.preorder\n2.inorder\n3.postorder";
		cin>>choice;

		switch(choice)
		{
		   case 1:
						cout<<"\n\t-----------------------";
						cout<<"\n\tPreorder Recursive :"; 
						preorder(root);

						cout<<"\n\t----------------------";
						cout<<"\n\tPeorder Non Recursive :"; 
						nonpre(root);
						break;
		   case 2:
						cout<<"\n\t-----------------------";
						cout<<"\n\tInorder Recursive :"; 
						inorder(root);

						cout<<"\n\t----------------------";
						cout<<"\n\tInorder Non Recursive :"; 
						nonrin(root);
						break;
		   case 3:
						cout<<"\n\t----------------------";
						cout<<"\n\tPostorder Recursive :"; 
						postorder(root);
			
						cout<<"\n\t-----------------------";
						cout<<"\n\tPostorder Non Recursive:"; 
						nonpost(root);
						break;
		}
		cout<<"\n\tDo u want to continue(y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	return 1;
} 