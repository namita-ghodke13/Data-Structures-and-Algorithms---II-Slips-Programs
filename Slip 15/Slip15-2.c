/*Q.2.Write a C program for the implementation of Dijkstra’s shortest path
algorithm for finding shortest path from a given source vertex using 
adjacency cost matrix.*/

#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
void dijkstra(int G[MAX][MAX],int n,int startnode) 
{ 
   int cost[MAX][MAX],distance[MAX],pred[MAX]; 
   int visited[MAX],count,mindistance,nextnode,i,j;   
   for(i=0;i<n;i++) 
   for(j=0;j<n;j++) 
    if(G[i][j]==0) 
      cost[i][j]=INFINITY; 
    else 
      cost[i][j]=G[i][j]; 
   for(i=0;i<n;i++) 
   { 
     distance[i]=cost[startnode][i]; 
     pred[i]=startnode; 
     visited[i]=0; 
   } 
   distance[startnode]=0; 
   visited[startnode]=1; 
   count=1; 
   while(count<n-1)   
   { 
     mindistance=INFINITY; 
     for(i=0;i<n;i++) 
       if(distance[i]<mindistance&&!visited[i]) 
       { 
         mindistance=distance[i]; 
         nextnode=i; 
       } 
       visited[nextnode]=1; 
     for(i=0;i<n;i++) 
       if(!visited[i]) 
          if(mindistance+cost[nextnode][i]<distance[i]) 
          { 
             distance[i]=mindistance+cost[nextnode][i]; 
             pred[i]=nextnode; 
          } 
          count++; 
   }  
   for(i=0;i<n;i++) 
     if(i!=startnode) 
     { 
       printf("\nDistance of Node %d = %d",i,distance[i]); 
       printf("\nPath = %d",i); 
       j=i; 
       do 
       { 
          j=pred[j]; 
          printf(" <- %d",j);
       }while(j!=startnode); 
       printf("\n");
     }
} 
int main() 
{ 
   int G[MAX][MAX],i,j,n,u; 
   printf("\nEnter no. of Vertices :"); 
   scanf("%d",&n); 
   printf("\nEnter the Adjacency Matrix :\n"); 
   for(i=0;i<n;i++) 
   for(j=0;j<n;j++) 
     scanf("%d",&G[i][j]); 
   printf("\nEnter the Starting Node :"); 
   scanf("%d",&u); 
   dijkstra(G,n,u); 
   return 0; 
} 



/*
Input :

Enter no. of Vertices :8

Enter the Adjacency Matrix :
0     999     999     999     999     999     999     999
30     0      999     999     999     999     999     999
100    80      0      999     999     999     999     999
999   999     120      0      999     999     999     999
999   999     999     150      0       25     999     999
999   999     999     100     999      0       90     140
999   999     999     999     999     999      0      100
170   999     999     999     999     999     999      0

Enter the Starting Node :4

Output :

Distance of Node 0 = 335
Path = 0 <- 7 <- 5 <- 4

Distance of Node 1 = 325
Path = 1 <- 2 <- 3 <- 5 <- 4

Distance of Node 2 = 245
Path = 2 <- 3 <- 5 <- 4

Distance of Node 3 = 125
Path = 3 <- 5 <- 4

Distance of Node 5 = 25
Path = 5 <- 4

Distance of Node 6 = 115
Path = 6 <- 5 <- 4

Distance of Node 7 = 165
Path = 7 <- 5 <- 4
*/