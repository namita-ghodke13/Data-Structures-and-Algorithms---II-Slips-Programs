//btree.h Header File of Slip 18 - Q.2 

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
Node *insert(Node *root)
{
   Node *newnode,*temp,*parent;
   int i,n,num;
   newnode=memory;
   printf("\nEnter Value to Insert :");
   scanf("%d",&num);
   newnode->data=num;
   newnode->left=NULL;
   newnode->right=NULL;
   if(root==NULL)
   {
      root=newnode;
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

   printf("\n%d Insert Successfully\n",num);
   return root;
}
void inorder(Node *root)
{
  Node *temp=root;
  if(temp!=NULL)
  {
     inorder(temp->left);
     printf("%d\t",temp->data);
     inorder(temp->right);
  }
}