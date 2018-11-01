/*
You're given a list of Integer Items. You have to compare every item with 'K', if it is less than 'K' you have to remove the item from the list, and return the modified list.

Examples:
<pre>
Input : list: 4,5,1,3,5,7,9,3           k: 5
Output : 5,5,7,9
Explanation: Those item whose value is less than k, is removed from the list.

Approach:
1. change the head, if the head itself contains lower value than 'k'.
    1.1 traverse the loop until we are getting one value which is greater than 'k'.
    1.2. unlink the current 'head' from the original 'head'
2. erase/unlink those value from the list whose are contains lower value than 'k'.
3. return the head;

//Asked In: Microsoft
*/

struct node * fun(int k, struct node * head){
	if((head) == NULL)
		return NULL;
	
	if((head)->data < k && (head)->next == NULL)
		return NULL;
	
	struct node * temp = head;
	struct node * current = NULL;
	
	// change the head, if head itself contains lower value than k.
	// and traverse untill we are getting a value which are greater than 'k'
	while(temp != NULL && temp->data < k){
		current = temp;
		temp = temp->next;
	}
	
	// unlink the temporary head from the list
	if(current != NULL)
		current->next = NULL;
	
	struct node * newHead = temp;
	// erase the link of those node, from the list, whose having less value than k.
	while(temp->next != NULL){
		if(temp->next->data < k){
			temp->next = temp->next->next;
		}else{
			temp = temp->next;
		}
	}
	free(head);
	head = newHead;
	return head;
}
