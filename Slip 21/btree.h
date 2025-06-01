//btree.h Header File of Slip 21 - Q.2

#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
typedef struct node
{
   int data;
   struct node *left,*right;
}Node;
Node *create(Node *root)
{
   Node *newnode,*temp,*parent;
   int i,n,num;
   printf("\nEnter Limit :");
   scanf("%d",&n);
   printf("\n");
   for(i=0;i<n;i++)
   {
      newnode=memory;
      printf("Enter Value :");
      scanf("%d",&num);
      newnode->data=num;
      newnode->left=NULL;
      newnode->right=NULL;
      if(root==NULL)
      {
         root=newnode;
         continue;
      }
      temp=root;
      while(temp!=NULL)
      {
         parent=temp;
         if(num<temp->data)
            temp=temp->left;
         else
            temp=temp->right;
      }
      if(num<parent->data)
         parent->left=newnode;
      else
         parent->right=newnode;
   }
   return root;
}
int count_totalnode(Node *root)
{
   static int c=0;
   Node *temp=root;
   if(temp!=NULL)
   {
      c++;
      count_totalnode(temp->left);
      count_totalnode(temp->right);
   }
   return c;
}
int count_leafnode(Node * root)
{
   static int leaf=0;
   Node *temp=root;
   if(temp!=NULL)
   {
      if((temp->left==NULL) && (temp->right==NULL))
      {
         leaf++;
      }
      count_leafnode(temp->left);
      count_leafnode(temp->right);
   }
   return leaf;
}