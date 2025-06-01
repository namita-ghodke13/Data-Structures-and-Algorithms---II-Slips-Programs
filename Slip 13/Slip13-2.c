/*Q.2.Write a program which uses binary search tree library and counts the
total nodes and total leaf nodes in the tree.
int countLeaf(T) – returns the total number of leaf nodes from BST.*/

#include<stdio.h>
#include"btree.h"
int main()
{
   int ans,ans1;
   Node *root=NULL;
   root=create(root);
   ans=count_totalnode(root);
   printf("\nTotal Nodes = %d",ans);
   ans1=count_leafnode(root);
   printf("\nTotal Leaf Nodes = %d",ans1);
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

Total Nodes = 7
Total Leaf Nodes = 3
*/