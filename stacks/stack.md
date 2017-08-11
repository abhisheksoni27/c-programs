# Stack Representaion using ARRAY

## PUSH (STACK, TOP, MAXSTK, ITEM)

**1.** _**If**_ `TOP` = `MAXSTK`, then Print `OVERFLOW` and Return

**2.** Set TOP = TOP + 1

**3.** Set STACK[TOP] = ITEM

**4.** Return.

## POP (STACK, TOP, ITEM)

**1.** **_If_** `TOP` = `0`, then Print `UNDERFLOW` and Return

**2.** Set `ITEM` = `STACK[TOP]`

**3.** `TOP` = `TOP - 1`

**4.** Return

### Stack Implementation in `C` using Array

```C

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
```

# Stack Representaion using LINKED LIST

## PUSH_LINKED_STACK (INFO, LINK, TOP, AVAIL, ITEM)

**1.** If `AVAIL` = `NULL`, then Print `OVERFLOW` and return

**2.** [Remove first node from `AVAIL`]

`NEW` = `AVAIL` and `AVAIL` = `LINK[AVAIL]`

**3.** Set `INFO[NEW]` = `ITEM` [Copies `ITEM` into new node]

**4.** Set `LINK[NEW]` = `TOP` [New node points to where `TOP` was pointing]

**5.** Set `TOP` = `NEW` [`TOP` now points to the new node.]

**6.** Exit

`NEW` = `AVAIL` and `AVAIL` = `LINK[AVAIL]`

## POP_LINK_STACK (INFO, LINK, TOP, AVAIL, ITEM)

**1.** [What if Stack is empty?]

If `TOP` = `NULL` then Write `UNDERFLOW` and `EXIT`

**2.** Set `ITEM` = `INFO[TOP]` [Copy the item at the `TOP` to be shown to the user].

**3.** Set `TEMP` = `TOP` and `TOP` = `LINK[TOP]`    

[Save previous value of top(because we need to put it in the `AVAIL` list, and also make `TOP` point to the next node(hence deleting the current `TOP` node))]

**4.** Set `LINK[TEMP]` = `AVAIL` and `AVAIL` = `TEMP`

**5.** Exit

### Stack Implementation in `C` using Linked List

```C
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
```
