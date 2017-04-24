

#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{
  int data;
  node *left;
  node *right;
}node;
class tree
{
  public:
 	node *root;
	tree()
	{
	   root=NULL;
	}
	void create(int dat);
	void insert(int key,int dat);
	node *search(int key,node *temp);
	node* returnroot();
	void display(node *temp);
	int depth(node *temp);
	void leaf(node *temp);
	node* copy(node *t);

};
void tree::create(int dat)
{
  root=new node;
  root->data=dat;
  root->left=NULL;
  root->right=NULL;
}
node* tree::search(int key,node *temp)
{
   if(temp->data==key)
   {
	return temp;
   }
   else
   {
	   if(temp->data!=key)

 return  search(key,temp->left);
	   else
  return search(key,temp->right);
   }
}
void tree::insert(int key,int dat)
{
   node *temp,*t;
   int ch;
   temp=search(key,root);
   if(temp==NULL)
   {
	cout<<"The key is not present "<<endl;
   }
   else
   {
	t=new node;
	t->left=NULL;
	t->right=NULL;
	t->data=dat;

	cout<<"Enter \n1.Left \n2. Right";
	cin>>ch;
	switch(ch)
	{
	case 1:if(temp->left==NULL)
           temp->left=t;
	       else
		   cout<<"The key node has left children,so data is not inserted "<<endl;
	       break;

	case 2:if(temp->right==NULL)
           temp->right=t;
	       else
		   cout<<"The key node has right children,so data is not inserted "<<endl;
	       break;
	}
   }
}
node* tree::returnroot()
{
   return root;
}
void tree:: display(node *temp)
{
  if(temp!=NULL)
   {
	cout<<temp->data<<" ";
	display(temp->left);
	display(temp->right);
   }
}
int tree:: depth(node *temp)
{
  if(temp==NULL)
  return 0;
  else
  {
  	int hl,hr;
  	if(temp==NULL)
  		return 0;

  	if(temp->left==NULL && temp->right==NULL)
  		return 0;

  	hl=depth(temp->left);
  	hr=depth(temp->right);

  	if(hl>hr)
  		return(hl+1);
  	else
  		return(hr+1);
  }
}
void tree::leaf(node *temp)
{
   if(temp!=NULL)
   {
	if(temp->left==NULL && temp->right==NULL)
	cout<<temp->data<<" ";
	leaf(temp->left);
	leaf(temp->right);
   }
}
node* tree:: copy(node *t)
{
  node  *p;
  p=NULL;
  if(t!=NULL)
  {
    p=new node;
    p->data=t->data;
    p->left=copy(t->left);
    p->right=copy(t->right);
   }
  return p;
}
int main()
{
  int ch,data,key,ans;
  node *r,*te;
  te=NULL;
  tree t;
  cout<<"Enter the root node data: ";
  cin>>data;
  t.create(data);
  do
  {
    cout<<"Enter your choice "<<endl;
    cout<<"1.Insert \n2.Display \n3.Depth \n4.Display leaf nodes \n5.Create copy \n6.Exit: ";
    cin>>ch;
    switch(ch)
    {
	case 1: cout<<"INSERT "<<endl;
		cout<<"Enter the key after which the data is to be inserted: ";
		cin>>key;
		cout<<endl<<"Enter the data which to be inserted: ";
		cin>>data;
		t.insert(key,data);
		break;
	case 2: cout<<"DISPLAY "<<endl;
		r=t.returnroot();
		if(r==NULL)
		{
		   cout<<"The tree is empty "<<endl;
		}
		else
		t.display(r);
		cout<<endl;
		break;
	case 3: cout<<"DEPTH "<<endl;
		r=t.returnroot();
		if(r==NULL)
		{
		   cout<<"The tree is empty "<<endl;
		}
		else
		ans=t.depth(r);
		cout<<"The depth is "<<ans<<endl;
		break;
	case 4: cout<<"LEAF NODES "<<endl;
		r=t.returnroot();
		if(r==NULL)
		{
		   cout<<"The tree is empty "<<endl;
		}
		else
		t.leaf(r);
		cout<<endl;
		break;
	case 5: cout<<"EXACT COPY OF A TREE "<<endl;
		r=t.returnroot();
		if(r==NULL)
		{
		   cout<<"The tree is empty "<<endl;
		}
		else
		te=t.copy(r);
		t.display(te);
		break;
	case 6: cout<<"EXIT "<<endl;
		exit(0);



    }
   }while(1);
}





