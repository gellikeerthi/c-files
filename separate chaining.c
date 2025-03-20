#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int *a[SIZE]={NULL};
struct node{
	int data;
	struct node*next;
};


void insert(){
	struct node *newnode,*ptr;
	int key,i;
	printf("Enter ele to be inserted in to hash table:");
	scanf("%d",&key);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next=NULL;
	i=key%SIZE;
	if(a[i]==NULL){
		a[i]=newnode;
	}
	else{
		ptr=a[i];
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}
void search(){
	struct node *ptr;
	int key,i,search=0;
	printf("enter key to be insert: ");
	scanf("%d",&key);
	i=key%SIZE;
	ptr=a[i];
	while(ptr!=NULL){
		if(ptr->data==key){
			search=1;
			break;
		}
		ptr=ptr->next;
	}
	if(search==1){
		printf("key is found\n");
	}
	else{
		printf("key not found\n");
	}
}
void display(){
	struct node *ptr;
	int i;
	for(i=0;i<SIZE;i++){
		ptr=a[i];
		printf("\n a[%d]-->",i);
		while(ptr!=NULL){
			printf("%d-->",ptr->data);
			ptr=ptr->next;
		}	
		printf("NULL\n");
		}
}int main(){
	int opt;
	while(1){
	printf("\n1.insert \n2.search \n3.display \n exit");
	printf("enter ur option");
	scanf("%d",&opt);
	switch(opt){
		case 1:insert();break;
		case 2:search();break;
		case 3:display();break;
		case 4:exit(0);break;
		default:printf("wrong choice\n");
	}
}return 0;
}
