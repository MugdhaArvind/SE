#include<iostream>
using namespace std;

#define ROW 10
#define COL 10
#define infinity 9999


class prim
{
    int graph[ROW][COL], nodes;
    public:
        void CreateGraph();
        void PrimsAlgo();

};

void prim::CreateGraph()
{
    int i,j;
    cout<<"\nEnter number of cities connected through wire(no. of nodes): ";
    cin>>nodes;
    cout<<"\nCost of connecting a pair of cities is as follows....";
    for(i=0;i<nodes;i++)
    {
        for(j=i;j<nodes;j++)
        {
            cout<<"\nEnter the cost of connecting city "<<i+1<<" and city "<<j+1<<":";
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
        }
    }
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            if(graph[i][j]==0)
               graph[i][j]=infinity;
        }
    }
}

void prim::PrimsAlgo()
{
    int selected[ROW], min=0 , zero=0 , one=1 , x , y , i , j , ne=0;
    int cost=0;
    for(i=0;i<nodes;i++)
    {
        selected[i]=zero;
    }
    selected[0]=one;
    while(ne<nodes-1)
    {
       min=infinity;
       for(i=0;i<nodes;i++)
       {
          if(selected[i]==one)
          {
            for(j=0;j<nodes;j++)
            {
                if(selected[j]==zero)
                {
                    if(min>graph[i][j])
                    {
                        min=graph[i][j];
                        x=i;
                        y=j;
                    }
                }

            }
          }
       }
       selected[y]=one;
       cout<<"\nThe path "<<x+1<<"->"<<y+1<<" is selected with a minimum cost "<<min;
       cost+=graph[x][y];
       ne++;
    }
    cout<<"\nThe minimum cost for the connection of wires between cities is: "<<cost<<" units";
}

int main()
{
    prim p;
    p.CreateGraph();
    p.PrimsAlgo();
    return 0;
}