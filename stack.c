#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
int main(){
	int opt;
	while(1){
		printf("\n1.push() \n2.pop()\n3.peek() \n4.display \n enter ur choice:");
		scanf("%d",&opt);
		switch(opt){
			case 1: push();break;
			case 2: pop();break;
			case 3: peek();break;
			case 4: display();break;
			default:"invalid choice";
		}	}
		return 0;
}
void push(){
	struct node *newnode;
	int ele;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf(" enter element to be insert:");
	scanf("%d",&ele);
	newnode->data=ele;
	
	if(newnode->next=NULL){
		top=newnode;
	}
	else{
		 newnode->next=top;
		 top=newnode;
	}
}
void pop(){
	struct node *ptr=top;
	if(top==NULL){
		printf("stack is empty");
	}
	else{
		top=top->next;
		printf(" %d is deleted",ptr->data);
		free(ptr);
	}
}
void peek(){
	struct node *ptr=top;
	if(top==NULL){
		printf("stack is empty");
	}
	else{
		printf("top most element =%d",ptr->data);
	}
}
void display(){
	struct node *ptr=top;
	while(ptr!=NULL){
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	printf("Null\n");
}
