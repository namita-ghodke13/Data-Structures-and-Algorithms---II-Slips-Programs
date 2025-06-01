/*Q.3.Write a C program for the implementation of Floyd Warshall’s algorithm 
for finding all pairs shortest path using adjacency cost matrix.*/

#include<stdio.h>
void floyd(int a[10][10],int n)
{
   int i,j,k;
   for(k=1;k<=n;k++)
   {
      for(i=1;i<=n;i++)
      {
         for(j=1;j<=n;j++)
         {
            if(a[i][k]+a[k][j]<a[i][j])
              a[i][j]=a[i][k]+a[k][j];
         }
      }
   }
   printf("\nOutput :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         printf("%d\t",a[i][j]);
      }
      printf("\n");
   }
}
int main()
{
   int a[10][10],i,j,n;
   printf("\nEnter no. of Vertices :");
   scanf("%d",&n);
   printf("\nEnter Cost Matrix :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         scanf("%d",&a[i][j]);
      }
   }
   floyd(a,n);
}



/*
Input :

Enter no. of Vertices :4

Enter Cost Matrix :
0     8     999     1
999   0      1     999
4    999     0     999
999   2      9      0

Output :

0       3       4       1
5       0       1       6
4       7       0       5
7       2       3       0
*/