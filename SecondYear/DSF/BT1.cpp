#include<iostream>

using namespace std;

class node
{
	public:
		node *left,*right;
		int data;
};

class tree:public node
{
	public:
		node *root,*root1;
		
		tree()
		{
			root=NULL;
		}

		node *insert();
		void display(node *);
		int height(node *);
		int leaf(node *);
		node *copy(node *);
};

node *tree::insert()
{
	node *p;
	int x;

	cout<<"\n\tEnter data : ";
	cin>>x;

	if(x==-1)
		return NULL;

	p=new node;
	p->data=x;

	cout<<"\n\tEnter left child of "<<x<<" = ";
	p->left=insert();

	cout<<"\n\tEnter right child of "<<x<<" = ";
	p->right=insert();

	return p;
}

/*void tree::insert(int x)
{
	node *p,*pre,*cu;
	p=new node;

	if(p==NULL)
		cout<<"\n\tOut of Memory :";

	p->data=x;
	p->left=p->right=NULL;

	if(root==NULL)
	{
		root=p;
		return;
	}

	pre=NULL;
	cu=root;

	while(cu!=NULL)
	{
		pre=cu;

		if(p->data < cu->data)
			cu=cu->left;
		else
			cu=cu->right;
	}
	
	if(p->data < pre->data)
		pre->left=p;
	else
		pre->right=p;


}*/

void tree::display(node *p)
{
	if(p==NULL)
		return;

	cout<<p->data<<" ";
	display(p->left);
	display(p->right);
}

int tree::height(node *p)
{
	int hl,hr;	

	if(p==NULL)
		return 0;

	if(p->left==NULL && p->right==NULL)
		return 0;

	hl=height(p->left);
	hr=height(p->right);

	if(hl > hr)
		return(hl+1);
	return(hr+1);
}

int tree::leaf(node *p)
{
	if(p!=NULL)
	{
		if(p->left==NULL && p->right==NULL)
			cout<<" "<<p->data;

		leaf(p->left);
		leaf(p->right);
	}
}

node *tree::copy(node *p)
{
	node *cp=new node;

	if(p==NULL)
		return NULL;
	else
	{
		cp->data=p->data;
		cp->left=copy(p->left);
		cp->right=copy(p->right);

		return(cp);
	}
}

int main()
{
	int choice,h,n,ch,i;
	tree t;
	node *root1,*root;

	do
	{
		cout<<"\n\t1.Insert\n\t2.Display\n\t3.Height\n\t4.Leaf Node\n\t5.Copy Tree\n";
		cout<<"\n\tEnter your choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				root=t.insert();		
				break;

			case 2:
				cout<<"\n\tDisplay Of Tree = ";
				t.display(root);
				cout<<"\n";
				break;

			case 3:
				h=t.height(root);
				cout<<"\n\tHeight Of the tree = "<<h<<"\n";
				break;

			case 4:
				cout<<"\n\tLeaf Node are : ";
				t.leaf(root);
				cout<<"\n";
				break;

			case 5:
				root1=t.copy(root);
				cout<<"\n\tCopy of Tree is = ";
				t.display(root1);
				cout<<"\n";
				break;

			case 6:
				break;
		}
	}while(choice!=6);
}