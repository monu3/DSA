#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
typedef struct node Nodetype;
Nodetype *top = 0;

void push(int);
void pop();
void display();

int main()
{
    int choice = 0;
    int item;

    printf("\n\n");
    printf("\n1.Push \n2.Pop \n3.Display\n4:Exit\n");
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
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting.....");
            exit(0);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}

void push(int item)
{
    Nodetype *n;
    int data;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    if (top == 0)
    {
        n->info = item;
        n->next = NULL;
        top = n;
    }
    else
    {
        n->info = item;
        n->next = top;
        top = n;
    }
}

void pop()
{
    Nodetype *temp;
    if (top == 0)
    {
        printf("Stack contain no elements:\n");
        return;
    }
    else
    {
        temp = top;
        top = top->next;
        printf("\ndeleted item is %d\t", temp->info);
        free(temp);
    }
    printf("\n\n");
}

void display()
{
    Nodetype *temp;
    if (top == 0)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        temp = top;
        printf("Stack items are:\n");
        while (temp != 0)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
        printf("\n\n");
    }
}