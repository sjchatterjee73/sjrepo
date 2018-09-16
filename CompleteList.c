#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
  int data;
  struct Node * next;
};
void insertFirst(int data, struct Node ** head){
  struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  newNode->next = *head;
  *head = newNode;
  return;
}
void insertPosition(int pos, int data, struct Node ** head){
  struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->next = NULL;
  newNode->data = data;

  int count=0;
  struct Node * temp = * head;
  struct Node * current = NULL;
  if(pos == 1){
    newNode->next = * head;
    * head = newNode;
    return;
  }
  while(++count != pos){
    if(temp == NULL)
      break;
    current = temp;
    temp = temp->next;
  }

  if(count != pos){
    printf("error!\n");
    return;
  }

  newNode->next = current->next;
  current->next = newNode;
  return;
}
void insertBefore(int node, int data, struct Node ** head){
  struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->next = NULL;
  newNode->data = data;

  struct Node * temp = * head;
  struct Node * current = NULL;

  bool ch = false;
  while(temp->next != NULL){
    if(temp->data == node){
      ch = true;
      break;
    }

    current = temp;
    temp = temp->next;
  }
  if(!ch){
    printf("node not found to insert!\n");
    return;
  }

  newNode->next = current->next;
  current->next = newNode;
  return;
}
void insertAfter(int node, int data, struct Node ** head){
  struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->next = NULL;
  newNode->data = data;

  struct Node * temp = *head;
  struct Node * current = NULL;
  bool ch= false;
  while(temp->next != NULL){
    if(temp->data == node){
      ch = true;
      break;
    }
    temp = temp->next;
    current = temp;
  }
  if(!ch){
    printf("node not found!\n");
    return;
  }
  newNode->next = current->next;
  current->next = newNode;
  return;
}
void insertMiddle(int data, struct Node ** head){
  struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  int count = 0;
  struct Node * temp = * head;
  while(temp != NULL){
    count++;
    temp = temp->next;
  }
  if(count == 1){
    printf("insertion isn't possible!\n");
    return;
  }
  count /=2;
  int i=0;
  temp = *head;
  struct Node * current = NULL;
  while(i++ != count){
      current = temp;
      temp = temp->next;
  }

  newNode->next = current->next;
  current->next = newNode;
  return;
}
void insertLast(int data, struct Node ** head){
  struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  struct Node * temp = *head;
  while((temp)->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  return;
}
void display(struct Node * temp){
  printf("\nlist in current:\n");
  while (temp != NULL) {
    printf("%i ->", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
void swap(struct Node * i, struct Node *j){
  int temp = i->data;
  i->data = j->data;
  j->data = temp;
}
void bubbleSort(struct Node * head){
    int swapped, i;
    struct Node * first = head;
    struct Node * second = NULL;

    if(head == NULL || head->next == NULL){
        printf("nothing to sort!");
        return;
    }
    bool ch = false;
    while(!ch){
        while (first->next != second){
            if (first->data > first->next->data){
                swap(first, first->next);
                ch = true;
            }
            first = first->next;
        }
        second = first;
    }
}
void deleteFirst(struct Node ** head){
  if(* head == NULL){
    printf("no such node to delete!");
    return;
  }
  struct Node * temp = (* head)->next;
  free(*head);
  *head = temp;
  return;
}
void deleteLast(struct Node **head){
  if(* head == NULL){
    printf("no such element to delete!\n");
    return;
  }

  if((*head)->next == NULL){
    free(*head);
    *head= NULL;
    return;
  }

  struct Node * temp = * head;
  struct Node * current = NULL;

  while((temp)->next != NULL) {
    current = temp;
    temp = temp->next;
  }
  free((current)->next);
  current->next = NULL;
  return;
}
void deleteNode(int node, struct Node ** head){
  struct Node * temp = *head;
  struct Node * current = NULL;
  if(temp->data == node){
    temp = (*head)->next;
    free(*head);
    * head= temp;
    return;
  }
  while(temp != NULL){
    current = temp;
    if(temp->next == NULL){
      printf("error in deletion\n");
      return;
    }

    if(temp->next->data == node){
      break;
    }
    temp = temp->next;
  }

  current = temp->next;
  temp->next = current->next;
  free(current);
  current->next =NULL;
}
int getSize(struct Node * head){
  int count=0;
  while (head != NULL) {
    count++;
    head = head->next;
  }
  return count;
}
void deletePosition(int pos, struct Node ** head){
  if(pos > getSize(*head) || pos < 0){
    printf("invalid position to delete\n");
    return;
  }

  if(pos == 1){
    deleteFirst(head);
    return;
  }

  if(pos == getSize(*head)){
    deleteLast(head);
    return;
  }

  int count = 1;
  struct Node * temp = *head;
  struct Node * current = NULL;

  while(temp != NULL){
    if(++count == pos){
      current = temp->next;
      temp->next = current->next;
    }
    temp = temp->next;
  }

  free(current);
  return;
}
void deleteAfter(int node, struct Node ** head){
  bool ch = false;
  struct Node * temp = * head;
  struct Node * current = NULL;

  while(temp != NULL){
    current = temp;
    if(temp->data == node){
      ch = true; break;
    }
    temp = temp->next;
  }

  if(!ch){
    printf("node not found!\n");
    return;
  }

  if(temp->next == NULL){
    printf("error in deletion!\n");
    return;
  }

  if(ch){
    current = temp->next;
    temp->next = current->next;
    free(current);
    return;
  }
}
void deleteBefore(int node, struct Node ** head){
  bool ch = false;
  struct Node * temp = * head;
  struct Node * current = NULL;

  if(temp->data == node){
    printf("error in deletion!\n");
    return;
  }

  if(temp->next->data == node){
    temp = (*head)->next;
    free(*head);
    *head = temp;
    return;
  }

  while(temp != NULL){
    if(temp->next->next == NULL){
      printf("error in deletion!\n");
      return;
    }

    if(temp->next->next->data == node){
      ch = true;
      break;
    }

    current = temp;
    temp = temp->next;
  }

  current = temp->next;
  temp->next = current->next;
  free(current);
  return;
}
void search(int node, struct Node * head){
  int count =0;
  bool ch = false;
  while(head != NULL){
    count++;
    if(head->data == node){
        printf("item %i found at %i position!\n",node, count);
        return;
    }
    head = head->next;
  }
  printf("item not found!\n");
  return;
}
int main(void){
    struct Node * head = NULL;
    int num, node;
    while(true){
      printf("1: to insert at first.\n");
      printf("2: to insert at last.\n");
      printf("3: to insert at middle.\n");
      printf("4: to insert after node.\n");
      printf("5: to insert before node.\n");
      printf("6: to insert at position.\n");
      printf("7: to sort the list.\n");
      printf("8: to delete from first.\n");
      printf("9: to delete from last.\n");
      printf("10: to delete the node itself.\n");
      printf("11: to delete at position.\n");
      printf("12: to delete at after a node.\n");
      printf("13: to delete at before a node.\n");
      printf("14: to search a node:\n");
      printf("15: to get size of the entire list.\n");
      int sc;
      scanf("%i",&sc);
      switch(sc){
        case 1:
          printf("enter node:");
          scanf("%i",&num);
          insertFirst(num, &head);
          display(head);
          break;
        case 2:
          printf("enter node:");
          scanf("%i",&num);
          insertLast(num, &head);
          display(head);
          break;
        case 3:
          printf("enter node:");
          scanf("%i",&num);
          insertMiddle(num, &head);
          display(head);
          break;
        case 4:
          printf("enter node:");
          scanf("%i",&num);
          printf("enter node after which to insert:\n");
          scanf("%i",&node);
          insertAfter(node,num, &head);
          display(head);
          break;
        case 5:
          printf("enter node:");
          scanf("%i",&num);
          printf("enter node before which to insert:\n");
          scanf("%i",&node);
          insertBefore(node, num, &head);
          display(head);
          break;
        case 6:
          printf("enter node:");
          scanf("%i",&num);
          printf("enter position:\n");
          int pos; scanf("%i",&pos);
          insertPosition(pos, num, &head);
          display(head);
          break;
        case 7:
          bubbleSort(head);
          display(head);
          break;
        case 8:
          deleteFirst(&head);
          display(head);
          break;
        case 9:
          deleteLast(&head);
          display(head);
          break;
        case 10:
          printf("enter node to delete:\n");
          scanf("%i",&num);
          deleteNode(num, &head);
          display(head);
          break;
        case 11:
          printf("enter position to delete:");
          scanf("%i",&num);
          deletePosition(num, &head);
          display(head);
          break;
        case 12:
          printf("enter node position:\n");
          scanf("%i",&num);
          deleteAfter(num, &head);
          display(head);
          break;
        case 13:
          printf("enter node position:\n");
          scanf("%i",&num);
          deleteBefore(num, &head);
          display(head);
          break;
        case 14:
          printf("enter node to search:\n");
          scanf("%i",&num);
          search(num, head);
          break;
        case 15:
          printf("currently, list size is: %i\n",getSize(head));
          break;
      }
    }
}
