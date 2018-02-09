#include<iostream>
#include<stdlib.h>

using namespace std;

class node
{
	public:
		node *left,*right;
		int data;
};
 
class tree: public node
{
	public:
		int stk[50],top;
		node *root;

		tree()
		{
			root=NULL;
			top=0;
		}
		void insert(int);
		void display(node *);
		node *search(node *,int ch );
		void preorder( node *root);
		void inorder(node *root);
		void postorder( node *root);
		int height(node *p);
		int leaf_node(node *p);
		node *pop(node *p);
};

void tree::insert(int ch)
{
	node *temp,*temp1;
	if(root== NULL)
	{
		root=new node;
		root->data=ch;
		root->left=NULL;
		root->right=NULL;
		return;
	}
	temp1=new node;
	temp1->data=ch;
	temp1->right=temp1->left=NULL;
	temp=search(root,ch);
	if(temp->data>ch)
		temp->left=temp1;
	else
		temp->right=temp1;
}

node *tree::search(node *temp,int ch)
{
		if(root== NULL)
		{
			cout <<"no node present";
			return NULL;
		}
		if(temp->left==NULL && temp->right== NULL)
			return temp;
 
		if(temp->data>ch)
		{
			if(temp->left==NULL) 
				return temp;
			search(temp->left,ch);
		}
		else
		{ 
			if(temp->right==NULL) 
				return temp;
			search(temp->right,ch);
		}              
}

void tree::display(node *temp)
{
	if(temp==NULL)
	   return ;
	 
	display(temp->left);
    	cout<<temp->data <<" ";
	display(temp->right);
}

void tree::preorder( node *root)
{
	node *p,*q;
	p=root;
	q=NULL;
	top=0;
 
	while(p!=NULL)
	{
		cout <<p->data  << " ";
		if(p->right!=NULL)
		{
			stk[top]=p->right->data;
			top++;
		}
		p=p->left;
		if(p==NULL && top>0)
			p=pop(root);
	}
}

void tree::inorder(node *root)
{
	node *p;
	p=root; 
	top=0;
	do
	{
		while(p!=NULL)
		{
			stk[top]=p->data;
			top++;
			p=p->left;
		}
		if(top>0)
		{
			p=pop(root);
			cout << p->data<<" ";
			p=p->right;
		}
	}while(top!=0 || p!=NULL);
}

void tree::postorder( node *root)
{
	node *p;
	p=root;
	top=0;
 
	while(1)
	{
		while(p!=NULL)
		{
			stk[top]=p->data;
			top++;
			
			if(p->right!=NULL)
				stk[top++]=-p->right->data;
			p=p->left; 
		}
		while(stk[top-1] > 0 || top==0)
		{
			if(top==0) return;
	   			cout << stk[top-1] <<" ";
	   		p=pop(root);
		}
		if(stk[top-1]<0)
		{
	  		stk[top-1]=-stk[top-1];
	  		p=pop(root);
      		}
	}
}

node *tree:: pop(node *p)
{
	int ch;
	ch=stk[top-1];

	if(p->data==ch)
	{
		top--;
		return p;
	}
	if(p->data>ch)	
		pop(p->left);
	else
		pop(p->right);
}

int tree::height(node *p)
{
	int hl,hr;

	if(p==NULL)
		return(0);
	if(p->left==NULL && p->right==NULL)
		return(0);

	hl=height(p->left);
	hr=height(p->right);

	if(hl>hr)
		return(hl+1);
	return(hr+1);
}

int tree::leaf_node(node *p)
{
	if(p==NULL)
		return(0);
	if(p->left==NULL && p->right==NULL)
	{
		cout<<"  "<<p->data;
		return 1;
	}
	return(leaf_node(p->left)+leaf_node(p->right));
}

int main()
{
	tree t1;
	int ch,n,i,choice,h;
	char c;
	while(1)
	{
		cout <<"\n1.Insert\n2.Display\n3.Preorder Traverse\n4.Inorder Traverse\n5.Postorder traverse\n6.Height\n7.Exit\nEnter your choice:";
		cin >> ch;

		switch(ch)
		{
			case 1:  
						cout <<"\nEnter no of elements to insert:";
						cin >> n;
		
						cout<<"\nEnter the elements : ";
						for(i=1;i<=n;i++)
						{
							cin >> ch;
							t1.insert(ch);
						}
						break;
			case 2:
						t1.display(t1.root);
						break;
			case 3:
						cout<<"\n\tPreorder Traverse: ";
						t1.preorder(t1.root); 
						break;
			case 4:
						cout<<"\n\tInorder Traverse: ";
						t1.inorder(t1.root); 
						break;
			case 5:
						cout<<"\n\tPostorder Traverse: ";
						t1.postorder(t1.root);
						break;
			case 6: 
						h=t1.height(t1.root);
						cout<<"\nHeight of tree="<<h;
						break;
			case 7:
						int x=t1.leaf_node(t1.root);
						cout<<"\nNo of leaf Node = "<<x;
						break;
			case 8:   exit(1);
		}
	}
}