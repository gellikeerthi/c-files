#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *start = NULL;

void create();
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void reverse();
void display();

int main() {
    int opt;
    while(1) {
        printf("\n1.create \n2.insertbeg \n3.insertend \n4.insertpos \n5.deletebeg \n6.deleteend \n7.deletepos \n8.reverse \n9.display \nenter your choice: ");
        scanf("%d", &opt);

        switch(opt) {
            case 1: create(); break;
            case 2: insertbeg(); break;
            case 3: insertend(); break;    
            case 4: insertpos(); break;    
            case 5: deletebeg(); break;
            case 6: deleteend(); break;    
            case 7: deletepos(); break;    
            case 8: reverse(); break;
            case 9: display(); break;
            default: exit(1);
        }
    }
}

void create() {
    struct node *ptr = start, *newnode;
    int ele;
    printf("Enter element to be inserted: ");
    scanf("%d", &ele);
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(start == NULL) {
        start = newnode;
    } else {
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void insertbeg() {
    struct node *ptr = start, *newnode;
    int ele;
    printf("Enter element to be inserted: ");
    scanf("%d", &ele);
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    if(start == NULL) {
        start = newnode;
    } else {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}

void insertend() {
    struct node *ptr = start, *newnode;
    int ele;
    printf("Enter element to be inserted: ");
    scanf("%d", &ele);
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(start == NULL) {
        start = newnode;
    } else {
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void insertpos() {
    struct node *ptr = start, *newnode;
    int ele, loc, i;
    
    printf("Enter element to be inserted: ");
    scanf("%d", &ele);
    printf("Enter location: ");
    scanf("%d", &loc);
    
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(start == NULL) {
        start = newnode;
    } else {
        for(i = 0; i < loc - 1 && ptr != NULL; i++) {
            ptr = ptr->next;
        }
        
        if(ptr == NULL) {
            printf("Location out of range\n");
            return;
        }

        newnode->next = ptr->next;
        if(ptr->next != NULL) {
            ptr->next->prev = newnode;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void deletebeg() {
    struct node *ptr = start;
    if(start == NULL) {
        printf("List is empty\n");
    } else {  
        if(start->next == NULL) {
            start = NULL;
            free(ptr);
        } else {
            start = ptr->next;
            start->prev = NULL;
            free(ptr);
        }
    }
}

void deleteend() {
    struct node *ptr1 = start, *ptr2;
    if(start == NULL) {
        printf("List is empty\n");
    } else { 
        if(start->next == NULL) {
            start = NULL;
            free(ptr1);
        } else {
            while(ptr1->next != NULL) {
                ptr2 = ptr1;
                ptr1 = ptr1->next;
            }
            ptr2->next = NULL;
            free(ptr1);
        }
    }
}

void deletepos() {
    struct node *ptr1 = start, *ptr2;
    int del;
    printf("Enter element to be deleted: ");
    scanf("%d", &del);

    while(ptr1 != NULL && ptr1->data != del) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }

    if(ptr1 == NULL) {
        printf("Element not found\n");
        return;
    }

    if(ptr1->next != NULL) {
        ptr1->next->prev = ptr2;
    }
    if(ptr2 != NULL) {
        ptr2->next = ptr1->next;
    } else {
        start = ptr1->next;
    }
    
    free(ptr1);
}

void reverse() {
    struct node *ptr = start;
    if(ptr == NULL) {
        printf("List is empty\n");
        return;
    }

    while(ptr->next != NULL) {
        ptr = ptr->next;
    }

    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}

void display() {
    struct node *ptr = start;
    if(ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

