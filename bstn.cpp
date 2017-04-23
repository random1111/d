#include<iostream>				//Header Files
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct node				//Node for a BST
{
	int data;
	struct node *left;
	struct node *right;
}node;
class bst						//Class for BST
{
public:
	node *root;
	bst()						//Default constructor
	{
		root=NULL;
	}
	void insert();				//Member Functions
	void create_tree(int);
	node *search(node *,int);
	void display(node *);
	void inorder_nonrec(node *);
	void levelwise(node *);
	void deleten(node *);
	node *findmax(node *);
	void mirror(node *);
};
void bst::insert()
{
	int n,x,i;
	cout<<"Enter no of nodes"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter value"<<endl;
		cin>>x;
		create_tree(x);
	}
}
void bst::create_tree(int x)
{
	node *temp,*temp1,*r;
	r=new node();
	r->data=x;
	if(root==NULL)
	{
		root=r;
		return ;
	}
	temp=root;
	while(temp!=NULL)
	{
		temp1=temp;
		if(x>temp->data)
		{
			temp=temp->right;
		}
		else
		{
			temp=temp->left;
		}
	}
	if(x>temp1->data)
	{
		temp1->right=r;
	}
	else
	{
		temp1->left=r;
	}
}
node *bst::search(node *root,int x)
{
	node *temp=root;
	while(temp!=NULL )
	{
		if(x==temp->data)
			break;
		else if(x>temp->data)
			temp=temp->right;
		else if(x<temp->data)
			temp=temp->left;
	}
 return temp;
}
void bst::display(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"\t";
		display(root->left);
		display(root->right);
	}
}
void bst::inorder_nonrec(node *root)
{
	node *temp=root;
	node **Stack=new node*[20];
	int top=-1;
	do
	{
		while(temp!=NULL)
		{
			Stack[++top]=temp;
			temp=temp->left;
		}
		temp=Stack[top--];
		cout<<"\t"<<temp->data;
		temp=temp->right;

	}
	while(top!=-1 || temp!=NULL);
}
void bst::levelwise(node *root)			//Levelwise display
{
	node *temp=root,*temp1;
	node **Q1=new node*[20];
	node **Q2=new node*[20];
	int R1=-1,F1=-1,R2=-1,F2=-1;
	Q1[++R1]=temp;
	int i=0;
	do
	{
		i++;
		while(R1!=F1)
		{
			temp1=Q1[++F1];
			cout<<"Level "<<i<<" : ";
			if(temp1!=NULL)
			{
				cout<<temp1->data;
				cout<<endl;
			}
			if(temp1->left!=NULL)
			{
				Q2[++R2]=temp1->left;
			}
			if(temp1->right!=NULL)
			{
				Q2[++R2]=temp1->right;
			}
		}
		i++;
		while(R2!=F2)
		{
			temp1=Q2[++F2];
			cout<<"Level "<<i<<" : ";
			if(temp1!=NULL)
			{
				cout<<temp1->data;
				cout<<endl;
			}
			if(temp1->left!=NULL)
			{
				Q1[++R1]=temp1->left;
			}
			if(temp1->right!=NULL)
			{
				Q1[++R1]=temp1->right;
			}
		}
	}
	while(R1!=F1 || R2!=F2);
}
void bst::deleten(node *root)			//Delete a node
{
	node *temp=root,*temp1=NULL,*temp2=NULL;
	int x;
	cout<<"Enter data to be deleted"<<endl;
	cin>>x;
	while(temp!=NULL )
	{
		if(x==temp->data)
			break;
		else if(x>temp->data)
		{
			temp1=temp;
			temp=temp->right;
		}
		else if(x<temp->data)
		{
			temp1=temp;
			temp=temp->left;
		}
	}
	if(temp==NULL)
	{
		cout<<"Data "<<x<<" is not present in tree"<<endl;
	}
	else
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			if(temp1->data>temp->data)
				temp1->left=NULL;
			else if(temp1->data<temp->data)
				temp1->right=NULL;
			cout<<"Data "<<x<<" deleted"<<endl;
			delete temp;
		}
		else if(temp->right!=NULL && temp->left!=NULL)
		{
			temp2=findmax(temp->right);
			temp1=temp2->left;
			temp->data=temp1->data;
			temp2->left=temp1->right;
			cout<<"Data "<<x<<" deleted"<<endl;
			delete temp1;
		}
		else if(temp->left!=NULL)
		{
			temp1->right=temp->left;
			cout<<"Data "<<x<<" deleted"<<endl;
			delete temp;
		}
		else if(temp->right!=NULL)
		{
			temp1->left=temp->right;
			cout<<"Data "<<x<<" deleted"<<endl;
			delete temp;
		}
	}

}
node *bst::findmax(node *root)
{
	node *temp=root,*temp1;
	while(temp->left!=NULL)
	{
		temp1=temp;
		temp=temp->left;
	}
	return temp1;
}
void bst::mirror(node *root)			//Mirror image of a tree
{
	node *temp=root,*temp1;
	node **Q=new node*[20];
	int R=-1,F=-1;
	Q[++R]=temp;
	do
	{
		temp=Q[++F];
		temp1=temp->left;
		temp->left=temp->right;
		temp->right=temp1;
		if(temp->left!=NULL)
			Q[++R]=temp->left;
		if(temp->right!=NULL)
			Q[++R]=temp->right;
	}
	while(R!=F);
	display(root);
}
int main()							//main function
{
	bst b;							//object of class
	node *temp=NULL;
	int ch;
	do
	{
		cout<<endl<<"MENU";
		cout<<endl<<"1.Accept a BST"<<endl;
		cout<<"2.Display a BST"<<endl;
		cout<<"3.Search a data in BST"<<endl;
		cout<<"4.Display Inorder Non-Recursive"<<endl;
		cout<<"5.Display levelwise"<<endl;
		cout<<"6.Delete a node"<<endl;
		cout<<"7.Mirror of BST"<<endl;
		cout<<"8.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:	b.insert();
		break;
		case 2:	b.display(b.root);
		break;
		case 3: int x;
				cout<<"Enter data to search"<<endl;
				cin>>x;
				temp=b.search(b.root,x);
				if(temp==NULL)
					cout<<"Data "<<x<<" is not present in tree"<<endl;
				else
				cout<<"Data "<<x<<" found"<<endl;
		break;
		case 4:	b.inorder_nonrec(b.root);
		break;
		case 5:	b.levelwise(b.root);
		break;
		case 6: b.deleten(b.root);
		break;
		case 7: b.mirror(b.root);
		break;
		case 8:exit(0);
		break;
		}
	}
	while(ch<=8);

	return 0;
}
