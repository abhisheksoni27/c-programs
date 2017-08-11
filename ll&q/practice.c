#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
} * front, *rear, *temp;

void enqueue();
void dequeue();
void display();

void enqueue()
{
    int data;

    // get data

    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->info = data;
    temp->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    if (front == NULL)
    {
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

void display(){
    temp = front;
    if (front == NULL)
    {
        printf("\n Queue is empty \n");
    }

    while(temp!=NULL){
        printf("%d", temp->info);
        temp = temp->next;
    }
}