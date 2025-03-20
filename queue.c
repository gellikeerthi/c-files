#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void display();
int main(){
	int option;
	while(1){
		printf("\nenter 1 to enqueue:\n");
		printf("enter 2 to dequeue:\n");
		printf("enter 3 to display:\n");
		printf("enter ur option:\n");
		scanf("%d",&option);
		switch(option){
			case 1:enqueue();break;
			case 2:dequeue();break;
			case 3:display();break;
			default:exit(1);
		}
	}
}
void enqueue(){
	struct node *newnode;
	int ele;
	printf("enter element to be insert");
	scanf("%d",&ele);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->next=NULL;
	if(front==NULL||rear==NULL){
		front=newnode;
		rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue(){
	struct node *ptr;
		if(front==NULL||rear==NULL){
	printf("queue is empty");
	}
	else{
		ptr=front;
		printf("%d is deleted ",front->data);
		front=front->next;
		free(ptr);
	}
}
void display(){
	struct node *ptr;
	ptr=front;
	while(ptr!=NULL){
	printf("%d->",ptr->data);
	ptr=ptr->next;
}}
