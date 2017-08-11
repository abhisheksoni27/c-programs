
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

struct stack
{
    int stk[MAXSIZE];
    int top;
};

struct stack s;

void push(void);

int pop(void);

void display(void);

void main()
{

    int choice;

    s.top = -1;

    while (1)
    {
        printf("\n------------------------------------------\n");
        printf("      1    -->    PUSH               \n");
        printf("      2    -->    POP               \n");
        printf("      3    -->    DISPLAY               \n");
        printf("      4    -->    EXIT           \n");
        printf("\n------------------------------------------\n");

        printf("\n Enter your choice \n");

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
            return;
        }
    }
}

/*  Function to add an element to the stack */

void push()
{
    int num;

    if (s.top == (MAXSIZE - 1))
    {
        printf("\nStack is Full\n");
        return;
    }

    else
    {
        printf("\nEnter the element to be pushed\n");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}

/*  Function to delete an element from the stack */

int pop()
{
    int num;
    if (s.top == -1)
    {
        printf("\nStack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf("\nDeleted element is = %d\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return (num);
}

/*  Function to display the status of the stack */

void display()
{
    int i;
    if (s.top == -1)
    {
        printf("\nStack is empty\n");
        return;
    }
    else
    {
        printf("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}