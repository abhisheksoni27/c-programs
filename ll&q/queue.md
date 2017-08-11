## Enqueue[Insertion] (QUEUE, N, FRONT, REAR, ITEM)

**1.** [What if Queue has no empty space?]

_**If**_ `FRONT` = `1` and `REAR` = `N`, or if `FRONT` = `REAR + 1`, then
        
    Write `OVERFLOW` and return.

**2.** _**If**_ FRONT = NULL, then

    Set FRONT = 1 and REAR = 1

_**Else if**_ REAR = N, then [Because we are using Circular Array]

    Set REAR = 1

_**Else**_

    Set REAR = REAR + 1
**3.** Set `QUEUE[REAR]` = `ITEM`

**4.** Return

## Dequeue[Deletion] (QUEUE, N, FRONT, REAR, ITEM)

**1.** [What if Queue is empty?]

_**If**_ `FRONT` = `NULL`, then
        
    Write `UNDERFLOW` and return.

**2.** Set `ITEM` = `QUEUE[FRONT]`

**3.** _**If**_ FRONT = REAR, then

    Set FRONT = NULL and REAR = NULL

_**Else if**_ FRONT = N, then [Because we are using Circular Array]

    Set FRONT = 1

_**Else**_

    Set FRONT = FRONT + 1

**4.** Return

### Queue Implementation in `C` using Array

```C
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

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
```

### Queue Implementation in `C` using Linked Lists

```C
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
```