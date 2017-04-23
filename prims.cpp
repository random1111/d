#include <iostream>
using namespace std;
class graph
{
  int n,cost[10][10],visited[10],mst[10][10];
  string city[10];
public:
  graph()
  {
	  int i,j;
	  for(i=0;i<10;i++)
	  {
		  for(j=0;j<10;j++)
		  {
			  mst[i][j]=0;
			  cost[i][j]=0;
		      visited[i]=0;
		  }
	  }
  }
  void accept_data();
  void accept_cost();
  int location(string );
  void display();
  void display_mst();
  void create_mst();
};
void graph :: accept_data()
{
	int i;
	cout<<"Enter total number of cities : ";
	cin>>n;
	cout<<"Enter the name of cities : ";
	for(i=0;i<n;i++)
	{
		cin>>city[i];
	}
	accept_cost();
}
int graph :: location(string key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(city[i]==key)
			return i;
	}
}
void graph :: accept_cost()
{
	int i,j,c;
	char ch;
	string loc1,loc2;
	do
	{
	cout<<"Enter the city with a route and its cost : ";
	cin>>loc1>>loc2>>c;
	i=location(loc1);
	j=location(loc2);
	if(cost[i][j]==0)
			cost[i][j]=cost[j][i]=c;
		else
			cout<<"A flight already exits.\n";
	cout<<"Any more routes (y/n) : ";
	cin>>ch;
	}while(ch=='y');
}
void graph :: display()
{
	int i,j,c=65;
	cout<<"  ";
	for(i=0;i<n;i++)
	{	cout<<(char)c<<" ";
	    c++;
	}
	cout<<endl;
	c=65;
	for(i=0;i<n;i++)
	{
		cout<<(char)c<<" ";
		c++;
		for(j=0;j<n;j++)
		{
			cout<<cost[i][j]<<" ";
		}
		cout<<endl;
	}
	c=65;
	for(i=0;i<n;i++)
	{
		cout<<(char)c<<" -> "<<city[i]<<endl;
		c++;
	}
}
void graph :: create_mst()
{
  int i,j,k=0,min,sum=0,source,destination;
  string start;
  cout<<"Enter the source city : ";
  cin>>start;
  visited[location(start)]=1;
  while(k<n)
  {
	  min=999;
	  for(i=0;i<n;i++)
	  {
		  if( visited[i]==1)
		  {
			  for(j=0;j<n;j++)
			  {
				  if(visited[j]==0)
				  {
					  if(cost[i][j]!=0 && cost[i][j]<min)
					  {
						  min=cost[i][j];
						  source=i;
						  destination=j;
					  }
				  }
			  }
		  }
	  }
	  if(min!=999)
	   {
             visited[destination]=1;
	     mst[source][destination]=mst[destination][source]=min;
	     sum=sum+min;
           }
	  k++;
  }
  cout<<"Cost of minimum spanning tree : "<<sum<<endl; 
}
void graph :: display_mst()
{
	int i,j,c=65;
	cout<<"  ";
	for(i=0;i<n;i++)
	{	cout<<(char)c<<" ";
	    c++;
	}
	cout<<endl;
	c=65;
	for(i=0;i<n;i++)
	{
		cout<<(char)c<<" ";
		c++;
		for(j=0;j<n;j++)
		{
			cout<<mst[i][j]<<" ";
		}
		cout<<endl;
	}
	c=65;
	for(i=0;i<n;i++)
	{
		cout<<(char)c<<" -> "<<city[i]<<endl;
		c++;
	}
}
int main()
{
    graph g;
    g.accept_data();
    cout<<"Adjacency matrix : \n";
    g.display();
    g.create_mst();
    cout<<"Minimum spanning tree matrix : \n";
    g.display_mst();
	return 0;
}
