#include<stdio.h>
#define SIZE 100
int htable[SIZE];
int hfunction(int key){
	return (key%SIZE);
}
void insert(){
	int key;
	printf("Enter key to be insert:");
	scanf("%d",&key);
	int index=hfunction(key);
	if(htable[index]==NULL){
		htable[index]=key;
	}else{
		printf("Collision occured\n");
	}
}
void search(){
	int x;
	printf("enter key to be search:");
	scanf("%d",&x);
	int res=hfunction(x);
	if(htable[res]==x){
		printf("%d is found at %d\n",x,res);
	}else{
		printf("%d is not found\n");
	}
}
void display(){
	int i,index;
	for(i=0;i<SIZE;i++){
		if(htable[index]!=-1){
			printf("%d ",htable[i]);
		}
	}
	printf("\n");
}
int main(){
	int i,n;
	for(i=0;i<SIZE;i++){
		htable[i]=-1;
	}
		printf("enter no of elements: ");
		scanf("%d",&n);
		for(i=0;i<n;i++){
			insert();
		}
		search();
		display();
		return 0;
	
}
