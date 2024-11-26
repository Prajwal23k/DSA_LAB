#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
    	head = tail = newNode;
        newNode->next = head;
        newNode->prev = tail;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = tail;
        tail->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        head = tail = newNode;
        newNode->next = head;
        newNode->prev = tail;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next = head;
        head->prev = newNode;
        tail=newNode;
    }
}

void insertAtPosition(int value, int position)
{
	struct Node *temp = head;
	int i;
    if (position < 1)
    {
        printf("Position should be >= 1\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (position == 1)
    {
        insertAtBeginning(value);
        return;
    }

    for ( i = 1; i < position - 1; i++)
    {
        if (temp->next == head)
        {
            printf("Position is out of range\n");
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteFromBeginning()
{
	struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}

void deleteFromEnd()
{
	struct Node *temp = tail;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
    	tail=tail->prev;
    	tail->next=head;
    	head->prev=tail;
    	free(temp);
    }
}

void deleteFromPosition(int position)
{
	struct Node *temp = head;
	int i;
    if (position < 1)
    {
        printf("Position should be >= 1\n");
        return;
    }

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position == 1)
    {
        deleteFromBeginning();
        return;
    }

    for (i = 1; i < position; i++)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Position is out of range\n");
            return;
        }
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
	struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
	int ch,data,pos;
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
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
