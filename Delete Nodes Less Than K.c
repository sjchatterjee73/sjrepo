#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
	int data;
	struct LinkedList * next;
};

struct LinkedList * push(int element, struct LinkedList * head){
	struct LinkedList * newnode = (struct LinkedList *)malloc(sizeof(struct LinkedList));
	newnode->next = NULL;
	newnode->data = element;

	if(head == NULL)
		head = newnode;
	else if(head->next == NULL)
		head->next = newnode;
	else{
		struct LinkedList * temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;		
	}
	return head;
}
void display(struct LinkedList * head){
	struct LinkedList * temp = head;
	while(temp != NULL){
		printf("%i ->", temp->data);
		temp = temp->next;
	}
	printf("\n");	
}
struct LinkedList * deleteLessNodes(struct LinkedList * head, int k){	
	// return if head is NULL;
	if(head == NULL)
		return head;
	// return, if head contains only element and that is also greater than k
	if(head->data > k && head->next == NULL)
		return head;

	struct LinkedList * temp = head;
	struct LinkedList * current = NULL;
	// erase link of all the starting nodes, whose value less than K.
	while(temp != NULL && temp->data < k){
		current = temp;
		temp = temp->next;
	}
	// unlink the new link from the list. 
	if(current != NULL)
		current->next = NULL;

	//skip the node whose value is less than K.
	struct LinkedList * anotherHead = temp;
	while(temp->next != NULL){
		if(temp->next->data < k)
			temp->next = temp->next->next;
		else
			temp = temp->next;
	}
	return anotherHead;
	
}
int main(void){
	int array[] = {5, 1, 3, 55,7 ,18, 4, 6, 20};
	int k = 10;
	int size = sizeof(array)/sizeof(int);

	struct LinkedList * head = NULL;

	// push all array elements into list..
	for(int i=0; i<size; i++){
		head = push(array[i], head);
	}
	display(head);

	// delete those node whose value is less than k..
	head = deleteLessNodes(head, k);
	display(head);
}