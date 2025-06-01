/*Q.2.Write a menu driven program to implement hash table using array 
(insert,search,display).Use any of the above-mentioned hash functions. 
In case of collision apply linear probing.*/

#include<stdio.h>
int ht[10];
void init()
{
   int i;
   for(i=0;i<10;i++)
   {
      ht[i]=-1;
   }
}
int hash(int num,int i)
{
   return (num%10+i)%10;
}
void insert(int num)
{
   int i,index;
   for(i=0;i<10;i++)
   {
      index=hash(num,i);
      if(ht[index]==-1)
      {
         ht[index]=num;
         break;
      }
   }
}
int search(int num)
{
   int i,index;
   for(i=0;i<10;i++)
   {
      index=hash(num,i);
      if(ht[index]==num)
      {
         return index;
      }
   }
   return -1;
}
void display()
{
   int i;
   printf("   HT\n");
   for(i=0;i<10;i++)
   {
      printf("%d [%d]\n",i,ht[i]);
   }
}
int main()
{
   int ch,num,index;
   init();
   do
   {
      printf("\nMENU");
      printf("\n1-Insert \n2-Search \n3-Display\n");
      printf("\nEnter Your Choice :");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:printf("\nEnter Number :");
                 scanf("%d",&num);
                 insert(num);
                 break;
          case 2:printf("\nEnter Number to Search :");
                 scanf("%d",&num);
                 index=search(num);
                 if(index==-1)
                    printf("\nNumber not Found\n");
                 else
                    printf("\nNumber Found at Position = %d\n",index);
                 break;
          case 3:printf("\n");
                 display();
                 printf("\n");
                 break;
          default :printf("\nInvalid Choice...");
      } 
   }while(ch<4);
}



/*
Input and Output :

MENU
1-Insert 
2-Search 
3-Display

Enter Your Choice :1

Enter Number :42

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [-1]
1 [-1]
2 [42]
3 [-1]
4 [-1]
5 [-1]
6 [-1]
7 [-1]
8 [-1]
9 [-1]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :1

Enter Number :17

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [-1]
1 [-1]
2 [42]
3 [-1]
4 [-1]
5 [-1]
6 [-1]
7 [17]
8 [-1]
9 [-1]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :1

Enter Number :86

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [-1]
1 [-1]
2 [42]
3 [-1]
4 [-1]
5 [-1]
6 [86]
7 [17]
8 [-1]
9 [-1]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :1

Enter Number :34

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [-1]
1 [-1]
2 [42]
3 [-1]
4 [34]
5 [-1]
6 [86]
7 [17]
8 [-1]
9 [-1]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :1

Enter Number :23

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [-1]
1 [-1]
2 [42]
3 [23]
4 [34]
5 [-1]
6 [86]
7 [17]
8 [-1]
9 [-1]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :1

Enter Number :12

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [-1]
1 [-1]
2 [42]
3 [23]
4 [34]
5 [12]
6 [86]
7 [17]
8 [-1]
9 [-1]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :1

Enter Number :9

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [-1]
1 [-1]
2 [42]
3 [23]
4 [34]
5 [12]
6 [86]
7 [17]
8 [-1]
9 [9]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :1

Enter Number :59

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :3

   HT
0 [59]
1 [-1]
2 [42]
3 [23]
4 [34]
5 [12]
6 [86]
7 [17]
8 [-1]
9 [9]


MENU
1-Insert
2-Search
3-Display

Enter Your Choice :2

Enter Number to Search :86

Number Found at Position = 6

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :2

Enter Number to Search :42

Number Found at Position = 2

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :2

Enter Number to Search :74

Number not Found

MENU
1-Insert
2-Search
3-Display

Enter Your Choice :4

Invalid Choice...
*/