#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *next;
}*start,*ptr,*newnode;


int create()
{
ptr=start;
newnode=malloc(sizeof(struct node))	;
printf("enter data\n");
scanf("%d",&newnode->data);
if(start==NULL)
{
	start=newnode;
	newnode->next=start;
}
else
{
while(ptr->next!=start)
{
	ptr=ptr->next;
}
ptr->next=newnode;
newnode->next=start;
}
}


int insertatbeg()
{
	ptr=start;
newnode=malloc(sizeof(struct node))	;
printf("enter data\n");
scanf("%d",&newnode->data);
if(start==NULL)
{
	start=newnode;
	newnode->next=start;
}
else
{

while(ptr->next!=start)
{
	ptr=ptr->next;
}
newnode->next=start;
start=newnode;
ptr->next=newnode;
}
}
int insertatend()
{
	ptr=start;
newnode=malloc(sizeof(struct node))	;
printf("enter data\n");
scanf("%d",&newnode->data);
while(ptr->next!=start)
{
	ptr=ptr->next;
}
ptr->next=newnode;
newnode->next=start;
}

int display()
{
	ptr=start;
	while(ptr->next!=start)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("%d",ptr->data);
}
int main()
{
      int ch;
      while(1)
      {
            printf("\n1.create \n2.insert at beg\n3.insert at end\n4.display\n5.inatsp\n6.delatbeg\n7.delatend\n8.delete at sp\n");
            printf("Enter choice: ");
           scanf("%d",&ch);
           switch(ch)
           {
            case 1:create();
            break;
            case 2:insertatbeg();
            break;
            case 3:insertatend();
            break;
            case 4:display();
            break;
            
           	default:
			   exit(1);
        
            }
}
}
