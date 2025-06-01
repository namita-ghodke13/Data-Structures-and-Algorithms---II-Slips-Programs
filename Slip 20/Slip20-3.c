/*Q.3.Write a C program that accepts the vertices and edges of a graph and 
store it as an adjacency matrix.Implement function to traverse the graph 
using Breadth First Search (BFS) traversal.*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct queue
{
   int data[MAX];
   int front,rear;
};
struct queue q;
void init()
{
   q.front=-1;
   q.rear=-1;
}
int isempty()
{
   return (q.front==q.rear);
}
int isfull()
{
   return (q.rear==MAX-1);
}
void addq(int v)
{
   q.data[++q.rear]=v;
}
int removeq()
{
   return (q.data[++q.front]);
}
void bfs(int a[10][10],int n)
{
   init();
   int v[10]={0},i,j;
   i=1;
   addq(i);
   v[i]=1;
   while(!isempty())
   {
      i=removeq();
      printf("v%d\t",i);
      for(j=1;j<=n;j++)
      {
         if((a[i][j]==1) && (v[j]==0))
         {
            addq(j);
            v[j]=1;
         }
      }
   }
}
int main()
{
   int a[10][10],n,i,j;
   printf("\nEnter no. of Vertices :");
   scanf("%d",&n);
   printf("\n");
   printf("Enter Matrix :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
   printf("\nBFS :\t");
   bfs(a,n);
}



/*
Input :

Enter no. of Vertices :5

Enter Matrix :
0 0 1 1 0
0 0 1 0 1
0 1 0 0 0
0 0 0 0 1
0 0 0 0 0

Output :

BFS :   v1      v3      v4      v2      v5
*/