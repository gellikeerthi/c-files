#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
}*start=NULL,*newnode,*ptr;
void create();
void display();
void count();
void sum();
void search();
void insertbeg();
void insertpos();
void insertdel();
void deletebeg();
void deletepos();
void deleteend();
void maxnode();
void minnode();
int main()
{
	int number;
	while(1)
	{
		printf("enter 1 for create\n");
		printf("enter 2 for display\n");
		printf("enter 3 for count\n");
		printf("enter 4 for  sum \n");
		printf("enter 5 for search\n");
		printf("enter 6 for insertbeg\n");
		printf("enter 7 for insertpos\n");
		printf("enter 8 for insertdel\n");
		printf("enter 9 for deletebeg\n");
		printf("enter 10 for deletepos\n");
		printf("enter 11 for deleteend\n");
		printf("enter 12 for maxnode\n");
		printf("enter 13 for minnode\n");
		printf("enter the number  ");
		scanf("%d",&number);
		switch (number) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                count();
                break;
            case 4:
                sum();
                break;
            case 5:
                search();
                break;
            case 6:insertbeg(); break;
            case 7:insertpos(); break;
            case 8:insertdel(); break;
            case 9:deletebeg(); break;
            case 10:deletepos(); break;
            case 11:deleteend(); break;
            case 12:maxnode(); break;
            case 13:minnode(); break;
            default:
                exit(1);
		}
	}
}
void create()
{
	int ele;
	printf("enter ele  ");
	scanf("%d",&ele);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}
void display() {
    ptr = start;
    printf("The linked list is: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
   
}

void count() {
    int count = 0;
    ptr = start;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    printf("node count: %d\n", count);
}
void sum() {
    int sum = 0;
    ptr = start;
    while (ptr != NULL) {
        sum += ptr->data;
        ptr = ptr->next;
    }
    printf(" sum  is: %d\n", sum);
}
void search() {
    int ele, flag = 0;
    printf("Enter  the element to search: ");
    scanf("%d", &ele);
    ptr = start;
    while (ptr != NULL) {
        if (ptr->data == ele) {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag==1) {
        printf("Ele  found \n");
    } else {
        printf("Ele not found \n");
    }
}
void insertbeg(){
	struct node *newnode;
	int ele;
	printf("enter ele to insert at beg ");
	scanf("%d",&ele);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{
		newnode->next=start;
		start=newnode;
}
}
void insertpos(){
	struct node *newnode;
	int ele,loc,i;
	printf("enter ele to be insert at spec pos  ");
	scanf("%d",&ele);
	printf("enter loc after which node u want to insert");
	scanf("%d",&loc);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	if(loc==0)
	{
		start=newnode;
	}
	else{
		for(i=0;i<loc-1;i++){
			ptr=ptr->next;
		}
		newnode->next=ptr->next;
		ptr->next=newnode;
	}
}
void insertend(){
	struct node *newnode;
	int ele;
	printf("enter ele to insert at end ");
	scanf("%d",&ele);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{	ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}
void deletebeg(){
	struct node *ptr;
if(start==NULL)
	{
		printf("sll is empty");
	}
	else{
		ptr=start;
		start=start->next;
		free(ptr);
	}	
}
void deletepos(){
	
}
void deleteend(){
	struct node *ptr1=start,*ptr2;
	if(start==NULL)
	{
		printf("sll is empty");
	}
	else{
		if(start->next==NULL){
			start=NULL;
			free(ptr1);
		}
		else{
			while(ptr1->next!=NULL){
				ptr2 =ptr1;
				ptr1=ptr1->next;
			}
			ptr2->next=NULL;
			free(ptr1);
		}
	}
}
void maxnode(){
	struct node *ptr=start;
	int max;
	max=ptr->data;
	while(ptr!=NULL){
		if (max<ptr->data){
			max=ptr->data;
		}
		ptr=ptr->next;
	}
	printf("max node :%d",max);
	}
void minnode(){
	struct node *ptr=start;
	int min;
	min=ptr->data;
	while(ptr!=NULL){
		if (min<ptr->data){
			min=ptr->data;
		}
		ptr=ptr->next;
	}
	printf("min node :%d",min);
	}
