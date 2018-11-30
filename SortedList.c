/*insert value in sorted order... */
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct List{
	struct List * next;
	int data;
};

struct List * insert(int data, struct List * head){
	struct List * newnode = (struct List *)malloc(sizeof(struct List));
	newnode->next = NULL;
	newnode->data = data;
	
	if(head == NULL){
		head = newnode;
		return head;
	}else if(head->data > data){
		newnode->next = head;
		head = newnode;
		return head;
	}
	
	struct List * temp = head;
	struct List * current = NULL;
	
	while(temp != NULL){
		if(temp->next == NULL && temp != NULL){
			temp->next = newnode;
			return head;
		}
		
		current = temp;
		if(data == temp->data || (temp->data < data && temp->next->data > data)){
			newnode->next = current->next;
			current->next = newnode;
			return head;
		}
		
		temp = temp->next;
	}
	
}

void display(struct List * head){
	struct List * temp = head;
	while(temp != NULL){
		printf("%i ->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main(void){
	int data, ch;
	struct List * head = NULL;
	
	while(1){
		printf("1. to insert value..\n");
		printf("2. to exit..\n");
		
		scanf("%i",&ch);
		
		switch(ch){
			case 1:
				printf("enter data insert .. \n");
				scanf("%i",&data);
				head = insert(data, head);
				display(head);
				break;
				
			case 2:
				exit(0);
		}
		
	}
}