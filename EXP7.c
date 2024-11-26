//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node
//{
//    int data;
//    struct Node *next;
//};
//
//struct Node *head = NULL;
//
//void insertAtBeginning(int value)
//{
//	struct Node *temp = head;
//    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//    newNode->data = value;
//
//    if (head == NULL)
//    {
//        head = temp = newNode;
//        newNode->next = newNode;
//    }
//    else
//    {
//        while (temp->next != head)
//        {
//            temp = temp->next;
//        }
//        newNode->next = head;
//        temp->next = newNode;
//        head = newNode;
//    }
//}
//
//void insertAtEnd(int value)
//{
//	struct Node *temp = head;
//    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//    newNode->data = value;
//
//    if (head == NULL)
//    {
//        head = temp = newNode;
//        newNode->next = newNode;
//    }
//    else
//    {
//        while (temp->next != head)
//        {
//            temp = temp->next;
//        }
//        newNode->next = head;
//        temp->next = newNode;
//    }
//}
//
//void insertAtPosition(int value, int position)
//{
//	struct Node *temp = head;
//	int i;
//    if (position < 1)
//    {
//        printf("Position cannot be less than 1\n");
//    }
//
//    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//    newNode->data = value;
//
//    if (position == 1)
//    {
//        insertAtBeginning(value);
//    }
//
//    for (i = 1; i < position - 1; i++)
//    {
//        if (temp->next == head)
//        {
//            printf("Invalid Position\n");
//            return;
//        }
//        temp = temp->next;
//    }
//
//    newNode->next = temp->next;
//    temp->next = newNode;
//}
//
//void deleteFromBeginning()
//{
//	struct Node *temp = head;
//	struct Node *del = head;
//    if (head == NULL)
//    {
//        printf("List is empty\n");
//    }
//
//    if (head->next == head)
//    {
//        free(head);
//        head = NULL;
//    }
//    else
//    {
//        while (temp->next != head)
//        {
//            temp = temp->next;
//        }
//        temp->next = head->next;
//        head = head->next;
//        free(del);
//    }
//}
//
//void deleteFromEnd()
//{
//	struct Node *temp = head;
//    struct Node *del;
//    if (head == NULL)
//    {
//        printf("List is empty\n");
//        return;
//    }
//
//    if (head->next == head)
//    {
//        free(head);
//        head = NULL;
//    }
//    else
//    {
//        while (temp->next->next != head)
//        {
//            temp = temp->next;
//        }
//        del = temp->next;
//        temp->next = head;
//        free(del);
//    }
//}
//
//void deleteFromPosition(int position)
//{
//	struct Node *temp = head;
//	struct Node *del;
//	int i;
//    if (position < 1)
//    {
//        printf("Position cannot be less than 1\n");
//    }
//
//    if (head == NULL)
//    {
//        printf("List is empty\n");
//    }
//
//    if (position == 1)
//    {
//        deleteFromBeginning();
//    }
//    for (i = 1; i < position - 1; i++)
//    {
//        if (temp->next == head)
//        {
//            printf("Position is out of range\n");
//            return;
//        }
//        temp = temp->next;
//    }
//    del=temp->next;
//    temp->next = del->next;
//    free(del);
//}
//
//void display()
//{
//	printf("Elements are :\n");
//	struct Node *temp = head;
//    if (head == NULL)
//    {
//        printf("List is empty\n");
//        return;
//    }
//    while(temp->next != head)
//    {
//    	printf("%d\n",temp->data);
//    	temp=temp->next;
//	}
//    printf("%d\n",temp->data);
//}
//
//int main()
//{
//	int ch,data,pos;
//	while (1) {
//        printf("1. Insert at Beginning\n");
//        printf("2. Insert at End\n");
//        printf("3. Insert at Position\n");
//        printf("4. Delete from Beginning\n");
//        printf("5. Delete from End\n");
//        printf("6. Delete from Position\n");
//        printf("7. Display List\n");
//        printf("8. Exit\n");
//        printf("Enter your choice: ");
//        scanf("%d", &ch);
//        switch (ch) {
//            case 1:
//                printf("Enter data: ");
//                scanf("%d", &data);
//                insertAtBeginning(data);
//                break;
//            case 2:
//                printf("Enter data: ");
//                scanf("%d", &data);
//                insertAtEnd(data);
//                break;
//            case 3:
//                printf("Enter data: ");
//                scanf("%d", &data);
//                printf("Enter position: ");
//                scanf("%d", &pos);
//                insertAtPosition(data, pos);
//                break;
//            case 4:
//                deleteFromBeginning();
//                break;
//            case 5:
//                deleteFromEnd();
//                break;
//            case 6:
//                printf("Enter position: ");
//                scanf("%d", &pos);
//                deleteFromPosition(pos);
//                break;
//            case 7:
//                display();
//                break;
//            case 8:
//                exit(0);
//            default:
//                printf("Invalid choice\n");
//        }
//    }
//}


























