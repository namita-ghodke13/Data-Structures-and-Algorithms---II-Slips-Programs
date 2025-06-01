/*Q.1.Implement a Binary search tree (BST) library (btree.h) with operations
– create,insert,preorder.Write a menu driven program that performs the above
operations.*/

#include<stdio.h>
#include"btree.h"
int main()
{
  int ch,ans;
  Node *root=NULL;
  do
  {
    printf("\nMENU");
    printf("\n1-Create \n2-Insert \n3-Preorder\n");
    printf("\nEnter Your Choice :");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:root=create(root);
             break;
      case 2:root=insert(root);
             break;
      case 3:printf("\nPreorder :\t");
             preorder(root);
             printf("\n");
             break;
      default:printf("\nInvalid Choice...");
              break;
    }
  }while(ch<4);
}



/*
Input and Output :

MENU
1-Create
2-Insert
3-Preorder

Enter Your Choice :1

Enter Limit :5

Enter Value :10
Enter Value :20
Enter Value :5
Enter Value :7
Enter Value :15

MENU
1-Create
2-Insert
3-Preorder

Enter Your Choice :3

Preorder :      10      5       7       20      15

MENU
1-Create
2-Insert
3-Preorder

Enter Your Choice :2

Enter Value to Insert :12

12 Insert Successfully

MENU
1-Create
2-Insert
3-Preorder

Enter Your Choice :3

Preorder :      10      5       7       20      15      12

MENU
1-Create
2-Insert
3-Preorder

Enter Your Choice :4

Invalid Choice...
*/