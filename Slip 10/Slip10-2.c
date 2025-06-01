/*Q.2.Write a C program that accepts the vertices and edges of a graph. 
Create adjacency list and display the adjacency list.*/

#include<stdio.h>
#include<stdlib.h>
#define memory (struct node *)malloc(sizeof(struct node))
struct node
{
   int data;
   struct node *next;
};
struct node *list[10];
void createlist(int a[10][10],int n)
{
   int i,j;
   struct node *temp,*new;
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
void displaylist(int n)
{
   struct node *temp;
   int i;
   for(i=1;i<=n;i++)
   {
      printf("\nv%d->",i);
      for(temp=list[i];temp!=NULL;temp=temp->next)
      {
         printf("v%d->",temp->data);
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
}



/*
Input :

Enter no. of Vertices :5

Enter Vertices as Matrix :
0 1 1 1 0
1 0 1 0 0
1 1 0 1 1
1 0 1 0 1
0 0 1 1 0

Output :

Adjacency List :

v1->v2->v3->v4->NULL

v2->v1->v3->NULL

v3->v1->v2->v4->v5->NULL

v4->v1->v3->v5->NULL

v5->v3->v4->NULL
*/