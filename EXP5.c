#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

void insertAtBeginning(struct Node **head, int data) {
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = *head;
   *head = newNode;
}

void insertAtEnd(struct Node **head, int data) {
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node *temp;
   newNode->data = data;
   newNode->next = NULL;
   temp=*head;
   if (*head == NULL) {
       *head = newNode;
       return;
   }
   while (temp->next != NULL){
       temp = temp->next;
	}
	temp->next = newNode; 
}

void insertAtPosition(struct Node **head, int data, int position) {
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   struct Node *temp;
	struct Node *count = *head; 
   int c=0,k=1;
   if (position == 1) {
       newNode->next = *head;
       *head = newNode;
   }
   while(count!=NULL)
   {
   	c++;
   	count=count->next;
	}
	if(position > c || position < 1) 
	{
		printf("Invalid Position\n");
	}
	else{
		temp=*head;
		while(k < (position-1))
		{
			temp=temp->next;
			k++;
		}
		newNode->data = data;
		newNode->next=temp->next;
		temp->next=newNode;
	}
}

void deleteFromBeginning(struct Node **head) {
   if (*head == NULL)
   {
       printf("List is Empty\n");
	}
   struct Node *temp = *head;
   *head = (*head)->next;
   free(temp);
}

void deleteFromEnd(struct Node **head) {
   if (*head == NULL)
   {
       printf("List is Empty\n");
	}
   struct Node *temp = *head;
   struct Node *prev = NULL;
   if (temp->next == NULL) {
       free(temp);
       *head = NULL;
   }
   while (temp->next != NULL) {
       prev = temp;
       temp = temp->next;
   }
   prev->next = NULL;
   free(temp);
}

void deleteFromPosition(struct Node **head, int position) {
	struct Node *count = *head;
	int c=0,k=1;
   if (head == NULL)
   {
       printf("List is Empty\n");
	}
   struct Node *temp;
   struct Node *prev;
   while(count!=NULL)
   {
   	c++;
   	count=count->next;
	}
   if (position == 1) {
       *head = temp->next;
       free(temp);
       return;
   }
   if(position > c || position < 1) 
	{
		printf("Invalid Position\n");
	}
	else{
		temp=*head;
		while(k < position)
		{
			prev=temp;
			temp=temp->next;
			k++;
		}
		prev->next=temp->next;
		free(temp);
	}
}

void displayList(struct Node *head) {
	struct Node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("NULL\n");
	}
   while (temp != NULL) {
       printf("%d\n", temp->data);
       temp = temp->next;
   }
}


int main() {
   struct Node *head=NULL;
   int ch, data, pos;
   while (1) {
       printf("1. Insert at Beginning\n");
       printf("2. Insert at End\n");
       printf("3. Insert at Position\n");
       printf("4. Delete from Beginning\n");
       printf("5. Delete from End\n");
       printf("6. Delete from Position\n");
       printf("7. Display List\n");
       printf("8. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &ch);
       switch (ch) {
           case 1:
               printf("Enter data: ");
               scanf("%d", &data);
               insertAtBeginning(&head, data);
               break;
           case 2:
               printf("Enter data: ");
               scanf("%d", &data);
               insertAtEnd(&head, data);
               break;
           case 3:
               printf("Enter data: ");
               scanf("%d", &data);
               printf("Enter position: ");
               scanf("%d", &pos);
               insertAtPosition(&head, data, pos);
               break;
           case 4:
               deleteFromBeginning(&head);
               break;
           case 5:
               deleteFromEnd(&head);
               break;
           case 6:
               printf("Enter position: ");
               scanf("%d", &pos);
               deleteFromPosition(&head, pos);
               break;
           case 7:
               displayList(head);
               break;
           case 8:
               exit(0);
           default:
               printf("Invalid choice\n");
       }
   }
   return 0;
}


