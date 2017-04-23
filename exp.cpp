//exp tree

#include<iostream>
#include<ctype.h>
using namespace std;

struct node
{
 char data;
 int flag;
 struct node *left;
 struct node *right;
};

class stack
{
	node *data[30];
	int top;
public:
	stack()
{
		top=-1;
}

	bool isempty()
	{
		if(top==-1)
			return true;
		return false;
	}

	void push(node *p)
	{
		top=top+1;
		data[top]=p;
	}

	node *pop()
	{
		return(data[top--]);
	}
};


void preorder_rec(node *t)
{
	if(t!=NULL)
	{
		cout<<t->data;
	    preorder_rec(t->left);
	    preorder_rec(t->right);
	}

}

void postorder_rec(node *t)
{
	if(t!=NULL)
	{
		postorder_rec(t->left);
		postorder_rec(t->right);
		cout<<t->data;
	}
}

void inorder_rec(node *t)
{
	if(t!=NULL)
	{
		inorder_rec(t->left);
		cout<<t->data;
		inorder_rec(t->right);
	}
}

void preorder_nonrec(stack s,node *t)
{
	while(t!=NULL)
	{
		cout<<t->data;
		s.push(t);
		t=t->left;
	}
	while(!s.isempty())
	{
         t=s.pop();
		 t=t->right;
		 while(t!=NULL)
		 {
			 cout<<t->data;
			 s.push(t);
			 t=t->left;
		 }
	}

}

void inorder_nonrec(stack s,node *t)
{
	while(t!=NULL)
	{
		s.push(t);
		t=t->left;
	}
	while(!s.isempty())
	{
		t=s.pop();
		cout<<t->data;
		t=t->right;
		while(t!=NULL)
		{
			s.push(t);
			t=t->left;
		}
	}

}

void postorder_nonrec(node *root)
{
	stack s,s1;
	node *t=root;
	while(t!=NULL)
	{
		s.push(t);
		s1.push(NULL);
		t=t->left;
	}
	while(!s.isempty())
	{
		t=s.pop();
		if(s1.pop()==NULL)
		{
			s.push(t);
			s1.push((node*)1);
			t=t->right;
			while(t!=NULL)
			{
				s.push(t);
				s1.push(NULL);
				t=t->left;
			}
		}
		else
			cout<<t->data;
	}

}

int main()
{
	stack s;
	node *top,*t1,*t2;
    top=NULL;
    char postfix[30];
	int ch,op;

	cout<<"\n ENTER A POSTFIX EXPRESIION ";
    cin>>postfix;


   	    for(int i=0;postfix[i]!=0;i++)
   	    {
   	    	if(isalnum(postfix[i]))
   	    	{
   	    		top=new node;
   	    		top->left=NULL;
   	    		top->right=NULL;
   	    		top->data=postfix[i];
   	    		s.push(top);
   	    	}
   	    	else
   	    	{
   	    		t2=s.pop();
   	    		t1=s.pop();
   	    		top=new node;
   	    		top->data=postfix[i];
   	    		top->left=t1;
   	    		top->right=t2;
   	    		s.push(top);
   	    	}
   	    }
   	    top=s.pop();
   	    cout<<"\n EXPRESSION HAS BEEN CONVERTED INTO EXPRESSION TREE SUCCESSFULLY!";
    do
    {
    cout<<"\n ***MENU***";
    cout<<"\n 1. PREORDER  TRAVERSAL(REC.) ";
    cout<<"\n 2. POSTORDER TRAVERSAL(REC.) ";
    cout<<"\n 3. INORDER   TRAVERSAL(REC.) ";
    cout<<"\n 4. PREODER   TRAVERSAL(NON-REC.)";
    cout<<"\n 5. INORDER   TRAVERSAL(NON-REC.) ";
    cout<<"\n 6. POSTORDER TRAVERSAL(NON-REC.) ";

    cout<<"\n ENTER YOUR CHOICE! ";
    cin>>ch;
    switch(ch)
    {

    case 1:cout<<"\n RECURSIVE PREORDER TRAVERSAL IS :";
    	   preorder_rec(top);
           break;

    case 2:cout<<"\n RECURSIVE POSTORDER TRAVERSAL IS :";
           postorder_rec(top);
           break;

    case 3:cout<<"\n RECURSIVE INORDER TRAVERSAL IS :";
           inorder_rec(top);
           break;

    case 4:cout<<"\n NON-RECURSIVE PREORDER TRAVERSAL IS :";
           preorder_nonrec(s,top);
           break;

    case 5:cout<<"\n NON-RECURSIVE INORDER TRAVERSAL IS :";
           inorder_nonrec(s,top);
           break;

    case 6:cout<<"\n NON-RECURSIVE POSTORDER TRAVERSAL IS :";
           postorder_nonrec(top);
           break;
   }

    cout<<"\n PRESS 1 TO CONTINUE OR 0 TO EXIT!";
    cin>>op;
    }while(op==1);
 return 0;
}

/*

