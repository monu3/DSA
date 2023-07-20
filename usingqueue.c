#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
typedef struct node Nodetype;
Nodetype *rear=0, *front=0;
//Nodetype rear = front = 0;

void enqueue(int);
void dequeue();
void display();

int main()
{
    int choice = 0;
    int item;

    printf("\n\n");
    printf("\n1.For Enqueue \n2.For Dequeue \n3.For Display \n4.Exit\n");
    printf("\n\n");
    while (choice != 4)
    {
        printf("enter ur choice: \t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted:\t");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}

void enqueue(int item)
{
    Nodetype *n;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    if (rear == 0)
    {
        n->info = item;
        n->next = NULL;
        rear = front = n;
    }
    else
    {
        n->info = item;
        n->next = NULL;
        rear->next = n;
        rear = n;
    }
}

void dequeue()
{
    Nodetype *temp;
    if (front == 0)
    {
        printf("Queue contain no elements:\n");
        return;
    }
    else if (front->next == NULL)
    {
        temp = front;
        rear = front = NULL;
        printf("\nDeleted item is %d\n", temp->info);
        free(temp);
    }
    else
    {
        temp = front;
        front = front->next;
        printf("\nDeleted item is %d\n", temp->info);
        free(temp);
    }
}

void display()
{
    Nodetype *temp;
    temp = front;
    printf("\nQueue items are:\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n\n");
}
