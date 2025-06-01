/*Q.3.Write a C program that accepts the vertices and edges of a graph and
store it as an adjacency list.Implement function to traverse the graph using 
Breadth First Search (BFS) traversal.*/

#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
#define MAX 50
typedef struct node
{
   int data;
   struct node *next;
}Node;
Node *list[10];
struct queue
{
   int data1[MAX];
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
   q.data1[++q.rear]=v;
}
int removeq()
{
   return (q.data1[++q.front]);
}
void createlist(int a[10][10],int n)
{
   int i,j;
   Node *temp,*new;
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         if(a[i][j]==1)
         {
            new=memory;
            new->next=NULL;
            new->data=j;
            if(list[i]==NULL)
            {
               list[i]=temp=new;
            }
            else
            {
               temp->next=new;
               temp=new;
            }
         }
      }
   }
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
void displaylist(int n)
{
   Node *temp;
   int i;
   for(i=1;i<=n;i++)
   {
      printf("\nv%d -> ",i);
      for(temp=list[i];temp!=NULL;temp=temp->next)
      {
         printf("v%d -> ",temp->data);
      }
      printf("NULL\n");
   }
}
int main() 
{ 
   int a[10][10],n,i,j;
   printf("\nEnter no. of Vertices :");
   scanf("%d",&n);
   printf("\nEnter Vertices as Matrix :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
   createlist(a,n);
   printf("\nAdjacency List :\n");
   displaylist(n);
   printf("\nBFS :\t");
   bfs(a,n);
} 



/*
Input :

Enter no. of Vertices :5

Enter Vertices as Matrix :
0 0 1 1 0
0 0 1 0 1
0 1 0 0 0
0 0 0 0 1
0 0 0 0 0

Output :

Adjacency List :

v1 -> v3 -> v4 -> NULL

v2 -> v3 -> v5 -> NULL

v3 -> v2 -> NULL

v4 -> v5 -> NULL

v5 -> NULL

BFS :   v1      v3      v4      v2      v5
*/