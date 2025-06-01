/*Q.1.Write a C program which uses Binary search tree library and displays 
nodes at each level,count of node at each level.*/

#include<stdio.h>
#include"btree.h"
int main()
{
	Node *root=NULL;
	root=create(root);
	printf("\nNodes at each Levels and Count of Nodes at each Levels are -\n");
	level(root);
}



/*
Input :

Enter Limit :5

Enter Value :10
Enter Value :20
Enter Value :5
Enter Value :7
Enter Value :15

Output :

Nodes at each Levels and Count of Nodes at each Levels are -

Level 0 --> 10
Total Nodes in 0 Level = 1

Level 1 --> 5   20
Total Nodes in 1 Level = 2

Level 2 --> 7   15
Total Nodes in 2 Level = 2

Total Levels = 3
*/