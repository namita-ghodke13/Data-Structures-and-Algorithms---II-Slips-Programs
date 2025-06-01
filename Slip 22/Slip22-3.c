/*Q.3.Write a C program that accepts the vertices and edges of a graph and 
store it as an adjacency matrix.Implement function to traverse the graph 
using Depth First Search (DFS) traversal.*/

#include<stdio.h>
#include<stdlib.h>
void dfs(int a[10][10],int n,int i)
{
   int j;
   static int v[10]={0};
   v[i]=1;
   printf("v%d\t",i);
   for(j=1;j<=n;j++)
   {
      if(a[i][j]==1 && v[j]==0)
      {
         dfs(a,n,j);
      }
   }
}
int main()
{
   int i,j,n,a[10][10];
   printf("\nEnter no. of Vertices :");
   scanf("%d",&n);
   printf("\nEnter Graph Matrix :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
   printf("\nDFS : ");
   dfs(a,n,1);
}



/*
Input :

Enter no. of Vertices :5

Enter Graph Matrix :
0 0 1 1 0
0 0 1 0 1
0 1 0 0 0
0 0 0 0 1
0 0 0 0 0

Output :

DFS : v1        v3      v2      v5      v4
*/