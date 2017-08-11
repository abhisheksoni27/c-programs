#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *ptr;
} *top, *temp;

void push();
void pop();
void display();

void main()
{
    int choice;
    top = NULL;

    while (1)
    {
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Display");
        printf("\n 4 - Exit");
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Wrong choice, Please enter correct choice \n");
            break;
        }
    }
}

/* Push data into stack */
void push()
{
    int data;

    printf("\nEnter data : ");

    scanf("%d", &data);

    if (top == NULL)
    {
        top = (struct node *)malloc(sizeof(struct node));
        top->info = data;
        top->ptr = NULL;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = data;
        temp->ptr = top;
        top = temp;
    }
}

/* Pop Operation on stack */
void pop()
{
    temp = top;

    if (temp == NULL)
    {
        printf("\n UNDERFLOW\n");
        return;
    }
    else
        temp = temp->ptr;
    printf("\n Popped value : %d \n", top->info);

    free(top);

    top = temp;
}

/* Display stack elements */
void display()
{
    temp = top; // So that TOP's contents are not destroyed.

    if (temp == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("\n %d \n", temp->info);
        temp = temp->ptr;
    }
}
