/*Q.1.Write a C program for the Implementation of Prim’s Minimum spanning 
tree algorithm.*/

#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];
int main()
{
  printf("\nEnter no. of Vertices :");
  scanf("%d",&n);
  printf("\nEnter Cost Matrix :");
  printf("\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&cost[i][j]);
      if(cost[i][j]==0)
        cost[i][j]=999;
    }
  }
  visited[1]=1;
  printf("\n");
  while(ne<n)
  {
    for(i=1,min=999;i<=n;i++)
    for(j=1;j<=n;j++)
      if(cost[i][j]<min)
      if(visited[i]!=0)
      {
        min=cost[i][j];
        a=u=i;
        b=v=j;
      }
      if(visited[u]==0 || visited[v]==0)
      {
        printf("\nEdge %d : (%d -> %d) Cost : %d",ne++,a,b,min);
        mincost=mincost+min;
        visited[b]=1;
      }
      cost[a][b]=cost[b][a]=999;
  }
  printf("\n\nMinimum Cost = %d",mincost);
}



/*
Input :

Enter no. of Vertices :7

Enter Cost Matrix :
0 5 3 0 0 0 0
5 0 4 6 2 0 0 
3 4 0 5 0 6 0
0 6 5 0 8 6 0
0 2 0 8 0 3 5
0 0 6 6 3 0 4
0 0 0 0 5 4 0

Output :

Edge 1 : (1 -> 3) Cost : 3
Edge 2 : (3 -> 2) Cost : 4
Edge 3 : (2 -> 5) Cost : 2
Edge 4 : (5 -> 6) Cost : 3
Edge 5 : (6 -> 7) Cost : 4
Edge 6 : (3 -> 4) Cost : 5

Minimum Cost = 21
*/