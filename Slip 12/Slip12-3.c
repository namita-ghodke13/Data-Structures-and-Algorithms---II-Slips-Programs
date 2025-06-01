/*Q.3.Write a C program that accepts the vertices and edges of a graph and 
store it as an adjacency matrix.Implement functions to print indegree, 
outdegree and total degree of all vertices of graph.*/

#include<stdio.h>
int main()
{
   int n,a[10][10],i,j;
   printf("\nEnter no. of Vertices :");
   scanf("%d",&n);
   printf("\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         a[i][j]=0;
         if(i!=j)
         {
            printf("Enter Edge Between v%d and v%d (0/1) :",i,j);
            scanf("%d",&a[i][j]);
         }
      }
   }
   printf("\nAdjacency Matrix :\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         printf("\t%d",a[i][j]);
      }
      printf("\n");
   }
   printf("\nVertex and their Indegree,Outdegree and Total Degree -\n");
   printf("\nVertex   Indegree   Outdegree   Total Degree\n");
   for(i=1;i<=n;i++)
   {
      int ind=0,outd=0;
      for(j=1;j<=n;j++)
      {
         outd=outd+a[i][j];
         ind=ind+a[j][i];
      }
      printf("\n  v%d         %d         %d             %d\t",i,ind,outd,ind+outd);
   }
}



/*
Input :

Enter no. of Vertices :5

Enter Edge Between v1 and v2 (0/1) :1
Enter Edge Between v1 and v3 (0/1) :1
Enter Edge Between v1 and v4 (0/1) :1
Enter Edge Between v1 and v5 (0/1) :0
Enter Edge Between v2 and v1 (0/1) :0
Enter Edge Between v2 and v3 (0/1) :1
Enter Edge Between v2 and v4 (0/1) :0
Enter Edge Between v2 and v5 (0/1) :0
Enter Edge Between v3 and v1 (0/1) :0
Enter Edge Between v3 and v2 (0/1) :0
Enter Edge Between v3 and v4 (0/1) :1
Enter Edge Between v3 and v5 (0/1) :1
Enter Edge Between v4 and v1 (0/1) :0
Enter Edge Between v4 and v2 (0/1) :0
Enter Edge Between v4 and v3 (0/1) :0
Enter Edge Between v4 and v5 (0/1) :1
Enter Edge Between v5 and v1 (0/1) :0
Enter Edge Between v5 and v2 (0/1) :0
Enter Edge Between v5 and v3 (0/1) :0
Enter Edge Between v5 and v4 (0/1) :0

Output :

Adjacency Matrix :
        0       1       1       1       0
        0       0       1       0       0
        0       0       0       1       1
        0       0       0       0       1
        0       0       0       0       0

Vertex and their Indegree,Outdegree and Total Degree -

Vertex   Indegree   Outdegree   Total Degree

  v1         0         3             3
  v2         1         1             2
  v3         2         2             4
  v4         2         1             3
  v5         2         0             2
*/