/*Queue - Linked List implementation*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
} *front, *rear, *temp;

void main()
{

front = NULL;
rear = NULL;

    int choice;

    void enqueue();
    void dequeue();
    void display();

    while (1)
    {
        printf("\n1.Enqueue \n");
        printf("\n2.Dequeue \n");
        printf("\n3.Display \n");
        printf("\n4.Exit \n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\n Wrong choice \n");
        }
    }
}

// To Enqueue an integer
void enqueue()
{
    int data;

    printf("\n Enter item to be inserted: ");
    scanf("%d", &data);

    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->info = data;
    temp->next = NULL; // Always NULL since ended as last node (rear)

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

// To Dequeue an integer.
void dequeue()
{
    if (front == NULL)
    {
        printf("\n Queue is empty \n");
        return;
    }

    temp = front;
    
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {

        front = front->next;
    }

    free(temp);
}

void display()
{
    temp = front;

    if (front == NULL)
    {
        printf("\n Queue is empty \n");
    }
    while (temp != NULL)
    {
        printf("\n %d \n", temp->info);
        
        temp = temp->next;
    }
}