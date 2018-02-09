#include<iostream>
#include<stdlib.h>
#define MAX 20
#define infinte 999

using namespace std;

class prims
{
	public:
		int G[MAX][MAX],n;
		
		prims()
		{
			n=0;
		}
		void create();
		void display();
		int span(prims &);
};

void prims::create()
{
	int i,k;
	
	cout<<"\n\nEnter Number of nodes:";
	cin>>n;

	cout<<"\n\nEnter the Adjacency matrix:";
	for(i=0; i<n; i++)
	    for(k=0; k<n; k++)
		cin>>G[i][k];
}

int prims::span(prims &spanning)
{
	int cost[MAX][MAX],u,v,min_distance,distance[MAX],from[MAX],visited[MAX],no_of_edges,i,mincost,k;

	for(i=0; i<n; i++)
	   for(k=0; k<n; k++)
	   {
		if(G[i][k]==0)
			cost[i][k]=infinte;
		else
			cost[i][k]=G[i][k];
		spanning.G[i][k]=0;
	   }

	distance[0]=0,visited[0]=1;
	for(i=1; i<n; i++)
	{
		distance[i]=cost[0][i];
		from[i]=0;
		visited[i]=0;
	}
	
	mincost=0;
	no_of_edges=n-1;

	while(no_of_edges > 0)
	{
		min_distance=infinte;
		
		for(i=1; i<n; i++)
			if(visited[i]==0 && (distance[i] < min_distance))	
			{
				v=i;
				min_distance=distance[i];
			}
	
		u=from[v];
		spanning.G[u][v]=distance[v];
		spanning.G[v][u]=distance[v];

		no_of_edges;
		visited[v]=1;

		for(i=1; i<n; i++)
			if(visited[i]==0 && (cost[i][v] < distance[i]))
			{
				distance[i]=cost[i][v];
				from[i]=v;
			}

		mincost=mincost+cost[u][v];

	}
	
	spanning.n=n;
	return(mincost);
}

void prims::display()
{
	int i,k;
	
	for(i=0; i<n; i++)
	{
		cout<<"\n";
		for(k=0; k<n; k++)
			cout<<"  "<<G[i][k];
	}
}


int main()
{
	prims p,spanning;
	int choice,total_cost;
	char ch;

	cout<<"\n\n----------Minimum Cost Spanning Tree Using Prim's Algorithm----------";

	do
	{
		cout<<"\n\n MENU: ";
		cout<<"\n\n\t1.Create Graph\n\n\t2.Spanning tree Matrix\n\n\t3.Find Minimum Cost Spanning Tree\n\n\t4.Exit";

		cout<<"\n\nEnter Your Choice: " ;
		cin>>choice;

		switch(choice)
		{
			case 1:
						p.create();
						break;
			case 2:
						total_cost=p.span(spanning);
						spanning.display();
						break;
			/*case 3:
						break;*/
			default:
						cout<<"\n\nPlease Enter Valid choice.";
						break;
		}
		
		cout<<"\n\nDo You Want To Continue To main Program?(Y/N): " ;
		cin>>ch;
	}while(ch=='Y' || ch=='y');

	return 0;
}