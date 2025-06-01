/*Q.3.Write a C program which uses Binary search tree library and displays
nodes at each level,and total levels in the tree.*/

#include<stdio.h>
#include"btree.h"
int main()
{
	Node *root=NULL;
	root=create(root);
   printf("\nNodes at each Levels are -\n");
	level(root);
}



/*
Input :

Enter Limit :7

Enter Value :10
Enter Value :20
Enter Value :15
Enter Value :5
Enter Value :1
Enter Value :6
Enter Value :13

Output :

Nodes at each Levels are -

Level 0 --> 10

Level 1 --> 5   20

Level 2 --> 1   6       15

Level 3 --> 13

Total Levels = 4
*/