/*Q.3.Write a C program for the implementation of Topological sorting.*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int a[10][10];
int n,i,j,k;
struct stack
{
   int data[MAX];
   int top;
};
struct stack s;
void init()
{
   s.top=-1;
}
int isempty()
{
   return (s.top=-1);
}
int isfull()
{
   return (s.top==MAX-1);
}
void push(int v)
{
   s.data[++s.top]=v;
}
int pop()
{
   return (s.data[s.top--]);
}
void topological_sort()
{
   init();
   int v[10]={0};
   int ind[10]={0};
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         ind[i]=ind[i]+a[j][i];
      }
   }
   while(1)
   {
      for(i=1;i<=n;i++)
      {
         if(ind[i]==0 && v[i]==0)
           push(i);
           v[i]=1;
           printf("v%d\t",i);
      }
      k=pop();
      for(j=1;j<=n;j++)
      {
         if(a[k][j]==1)
         {
            ind[j]=ind[j]-1;
         }
      }
      if(isempty())
      {
         break;
      }
   }
}
int main()
{
   printf("\nEnter no. of Vertices :");
   scanf("%d",&n);
   printf("\nEnter Matrix :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
   printf("\nTopological Sort : ");
   topological_sort();
}



/*
Input :

Enter no. of Vertices :5

Enter Matrix :
0 1 1 0 0 
0 0 0 1 0
0 0 0 1 1
0 0 0 0 1
0 0 0 0 0

Output :

Topological Sort : v1   v2      v3      v4      v5
*/