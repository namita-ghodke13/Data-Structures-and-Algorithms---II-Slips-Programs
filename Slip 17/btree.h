//btree.h Header File of Slip 17 - Q.3

#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
#define MAX 30
typedef struct node 
{
	int data;
	struct node *left,*right;
}Node;
struct queue
{
	int front,rear;
	Node *a[MAX];
};
struct queue q;
void init()
{
	q.front=q.rear=-1;
}
int isempty()
{
	return (q.front==q.rear);
}
int isfull()
{
   return (q.rear==MAX-1);
}
void addq(Node *temp)
{
	q.a[++q.rear]=temp;
}
Node *removeq()
{
	return (q.a[++q.front]);
}
Node *create(Node *root)
{
	int i,n;
	Node *temp,*parent,*newnode;
	printf("\nEnter Limit :");
	scanf("%d",&n);
   printf("\n");
	for(i=0;i<n;i++)
	{
	   printf("Enter Value :");
	   newnode=memory;
	   scanf("%d",&newnode->data);
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
	      if(newnode->data<temp->data)
	         temp=temp->left;
	      else
	         temp=temp->right;
	   }
	   if(newnode->data<parent->data)
	      parent->left=newnode;
	   else
	      parent->right=newnode;
	}
	return root;
}
void level(Node *root)
{
	Node *temp;
	int level=0;
	static int c=0;
   init();
	addq(root);
	addq(NULL);
	printf("\nLevel %d --> ",level);
	while(!isempty())
	{
	   temp=removeq();
	   if(temp==NULL)
	   {
	      level++;
	      if(!isempty())
	      {
	         addq(NULL);
            printf("\n");
	         printf("\nLevel %d --> ",level);
	      }
	      c++;
	   }
	   else
	   {
	      printf("%d\t",temp->data);
	      if(temp->left!=NULL)
	         addq(temp->left);
	      if(temp->right!=NULL)
	         addq(temp->right);
	   }
   }
	printf("\n\nTotal Levels = %d\t",c);
}