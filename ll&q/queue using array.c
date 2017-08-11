#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int queue[MAX];

int rear = -1;

int front = -1;

void main()
{
    int choice;

    void insert();
    void delete ();
    void display();

    while (1)
    {
        printf("1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display \n");
        printf("4.Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice \n");
        }
    }
}

void insert()
{
    int data;

    if (rear == MAX - 1)
        printf("\n Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        printf("\n Element to be inserted : ");

        scanf("%d", &data);

        rear = rear + 1;

        queue[rear] = data;
    }
}

void delete ()
{
    if (front == -1 || front > rear)
    {
        printf("\n UNDERFLOW \n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}