
#include<iostream>
#include<string>
using namespace std;

class pqueue
{
	struct node
	{
		int pcode;
		string pname;
		string psymptoms;
		node *next;
	};
	node *front, *rear;
	int i = 1;
	public:
	pqueue()
	{
		front = rear = NULL;
	}
		void enqueue(string, string);
		//void dequeue();
		bool pqueue_empty();
		char check_priority(string);
		void display();
		void dequeue();
};

bool pqueue :: pqueue_empty()
{
	if(front == NULL && rear == NULL)
		return true;
	return false;
}

char pqueue :: check_priority(string psymptoms)
{
	if(psymptoms == "fever" || psymptoms == "allergy" || psymptoms == "deficiency" || psymptoms == "thyroid" || psymptoms == "chickenpox")
		return 'l';
	if(psymptoms == "eyeinfection" || psymptoms == "jaundice" || psymptoms == "diabetes" || psymptoms == "ulcer" || psymptoms == "paralysis")
		return 'm';
	if(psymptoms == "heartattack" || psymptoms == "cancer" || psymptoms == "brainhamarage" || psymptoms == "kidneyfailure" || psymptoms == "severeinjury")
		return 'h';
}

void pqueue :: enqueue(string pname, string psymptoms)
{
	node *newptr = new node;
	newptr->next = NULL;
	if(pqueue_empty())
	{
		newptr->pcode = i;
		newptr->pname = pname;
		newptr->psymptoms = psymptoms;
		front = rear = newptr;
	}
	else
	{
		newptr->pcode = ++i;
		newptr->pname = pname;
		newptr->psymptoms = psymptoms;
		rear->next = newptr;
		rear = newptr;
	}
}

void pqueue :: display()
{
	node *p = front;
	if(pqueue_empty())
		cout << "Queue is empty";
	else
	{
		while(p != NULL)
		{
			cout << "\n" << p->pcode << "\t" << p->pname << "\t" << p->psymptoms;
			p = p->next;
		}
	}
}
void pqueue :: dequeue()
{
	node *p;
	if(front == rear)
	{
		 p = front;
		 cout << "\n Patient to be served:";
		 cout << "\n Patient code " << front->pcode;
		 cout << "\n Patient name " << front->pname;
		 cout << "\n Patient symptoms " << front->psymptoms;
		 front = rear = NULL;
		 delete p;
	}
	else
	{
		p = front;
		cout << "\n Patient to be served:";
		cout << "\n Patient code " << front->pcode;
		cout << "\n Patient name " << front->pname;
		cout << "\n Patient symptoms " << front->psymptoms;
		front = front->next;
		delete p;
	}

}

int main()
{
	pqueue p1, p2, p3;
	string name, symptoms;
	int ch;
	char op;
	do
	{
		cout << "\n Menu \n 1. Accept patient details and Insert patient in priority queue \n 2. Display patient list";
		cout << "\n 3. Delete patient from the queue \n 4. Exit \n Enter your choice: \n";
		cin >> ch;
		switch(ch)
		{
			case 1:
				cout << "\n Enter Patient's name:";
				cin >> name;
				cout << "\n Enter Patient's Symptoms: ";
				cin >> symptoms;
				op = p1.check_priority(symptoms);
				switch(op)
				{
					case 'l':
						p3.enqueue(name, symptoms);
						break;
					case 'm':
						p2.enqueue(name, symptoms);
						break;
					case 'h':
						p1.enqueue(name, symptoms);
						break;
				}
				break;
			case 2:
				cout << "\n Displaying serious patients list:";
				p1.display();
				cout << "\n Displaying medium illness patients list:";
				p2.display();
				cout << "\n Displaying general patients list:";
				p3.display();
				break;
			case 3:
				cout << "\n Serving patient according to priority:";
				if(p1.pqueue_empty())
					cout << "\n Serious Patients Queue is empty";
				else
				{
					p1.dequeue();
					break;
				}
				if(p1.pqueue_empty())
				{
					if(p2.pqueue_empty())
						cout << "\n Medium illness Patients Queue is empty";
					else
					{
						p2.dequeue();
						break;
					}
				}
				if(p1.pqueue_empty() && p2.pqueue_empty())
				{
					if(p3.pqueue_empty())
						cout << "\n General Patients Queue is empty";
					p3.dequeue();
				}
				break;
		}
	}while(ch != 4);
}

