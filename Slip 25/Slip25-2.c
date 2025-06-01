/*Q.2.Write a program to sort n randomly generated elements using Heap sort
method.*/

#include<stdio.h>
#include<stdlib.h>
void accept(int a[],int n)
{
	int i;
	printf("\n");
	printf("Enter Values : ");
	for(i=0;i<n;i++)
	{
	   a[i]=rand()%100;
	   printf("%d\t",a[i]);
   }
	printf("\n");
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	   printf("%d\t",a[i]);
	}
	
}
void heapify(int a[],int i,int n)
{
	int key=a[i];
	int j=(2*i)+1;
	if(j<=n && a[j]<a[j+1])
	{
	   j=j+1;
	}
	if(j<=n && key<a[j])
	{
	   int t=a[i];
	   a[i]=a[j];
	   a[j]=t;
	   heapify(a,j,n);
	}
}
void buildheap(int a[],int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
	   heapify(a,i,n-1);
	}
}
void heapsort(int a[],int n)
{
	int last,top=0,temp;
	buildheap(a,n);
	printf("\nInitial Heap :\t");
	display(a,n);
	printf("\n");
	for(last=n-1;last>=1;last--)
	{
	   temp=a[top];
	   a[top]=a[last];
	   a[last]=temp;
	   printf("\nIteration %d : \t",n-last);
	   display(a,n);
	   heapify(a,top,last-1);
	}
}
int main()
{
	int a[100],n;
	printf("\nEnter Limit :");
	scanf("%d",&n);
	accept(a,n);
	heapsort(a,n);
	printf("\n");
	printf("\nSorted Elements : ");
   display(a,n);
}



/*
Input :

Enter Limit :5

Enter Values : 41       67      34      0       69

Output :

Initial Heap :  69      67      34      0       41

Iteration 1 :   41      67      34      0       69
Iteration 2 :   0       41      34      67      69
Iteration 3 :   34      0       41      67      69
Iteration 4 :   0       34      41      67      69

Sorted Elements : 0     34      41      67      69
*/