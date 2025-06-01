/*Q.1.Write a C program for the Implementation of Kruskal’s Minimum spanning 
tree algorithm.*/

#include<stdio.h>
int i,j,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
int main()
{
   printf("\nImplementation of Kruskal's Algorithm -\n");
   printf("\nEnter no. of Vertices :");
   scanf("%d",&n);
   printf("\nEnter Cost Matrix :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&cost[i][j]);
         if(cost[i][j]==0)
            cost[i][j]=999;
      }
   }
   printf("\nThe Edges of Minimum Cost Spanning Tree are -\n");
   printf("\n");
   while(ne<n)
   {
      for(i=1,min=999;i<=n;i++)
      {
         for(j=1;j<=n;j++)
         {
            if(cost[i][j]<min)
            {
               min=cost[i][j];
               a=u=i;
               b=v=j;
            }
         }
      }
      u=find(u);
      v=find(v);
      if(uni(u,v))
      {
         printf("Edge %d : (%d,%d) = %d\n",ne++,a,b,min);
         mincost += min;
      }
      cost[a][b]=cost[b][a]=999;
   }
   printf("\nMinimum Cost = %d\n",mincost);
}
int find(int i)
{
   while(parent[i])
     i=parent[i];
     return i;
}
int uni(int i,int j)
{
   if(i!=j)
   {
      parent[j]=i;
      return 1;
   }
   return 0;
}



/*
Input :

Implementation of Kruskal's Algorithm -

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
 
The Edges of Minimum Cost Spanning Tree are -

Edge 1 : (2,5) = 2
Edge 2 : (1,3) = 3
Edge 3 : (5,6) = 3
Edge 4 : (2,3) = 4
Edge 5 : (6,7) = 4
Edge 6 : (3,4) = 5

Minimum Cost = 21
*/