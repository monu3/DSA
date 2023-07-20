#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node Nodetype;
Nodetype *start = NULL;
Nodetype *last = NULL;

void insertAtFirst(int);
void insertAtLast(int);
void deleteAtfirst();
void deleteAtLast();
void display();

int main()
{
    int choice = 0;
    int item;
    printf("\n\n");
    printf("1.Insert at First:\n");
    printf("2.Insert at last:\n");
    printf("3.Delete at First:\n");
    printf("4.Delete at last:\n");
    printf("5.Display the content of list:\n");
    printf("6. EXIT!\n");
    printf("\n\n");
    while (choice != 6)
    {
        printf("Enter your choice: \t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted : \t");
            scanf("%d", &item);
            insertAtFirst(item);
            break;
        case 2:
            printf("Enter the item to be inserted : \t");
            scanf("%d", &item);
            insertAtLast(item);
            break;

        case 3:
            deleteAtfirst();
            break;
        case 4:
            deleteAtLast();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);
            break;
        default:
            printf("invalid choice!");
        }
    }
}

void insertAtFirst(int item)
{
     Nodetype *n;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    if (start == NULL)
    {
        n->info = item;
        n->next = n;
        n->prev = n;
        start = n;
        last = n;
    }
    else
    {
        n->info = item;
        n->next = start;
        n->prev = last;
        start->prev = n;
        start = n;
        last->next = n;
    }
}


void insertAtLast(int item)
{
    Nodetype *n;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    n->info = item;
    if (start == NULL)
    {
        start = n;
        last = n;
        n->prev = n;
        n->next = n;
        start=last=n;
    }
    else
    {
        last->next = n;
        n->prev = last;
        last = n;
        n->next = start;
        start->prev= n;
    }
}

void deleteAtfirst()
{
    Nodetype *temp;
    if (start == NULL)
    {
        printf("The list is empty!");
        exit(1);
    }
    else
    {
        temp = start;
        start = start->next;
        printf("The deleted item is:%d\n",start->info);
        start->prev = last;
        last->next = start;
        free(temp);
    }
}

void deleteAtLast()
{
    Nodetype *temp,*hold;
    if (start == NULL)
    {
        printf("The list is empty!");
        exit(1);
    }
    else if (start == last) // for only one node
    {
        temp = start;
        printf("The deleted item is:%d\n",start->info);
        start = NULL;
        last = NULL;
        free(temp);
    }
    else
    {

        temp = last;
        start->prev = last->prev;
        last = last->prev;
        last->next = start;
        printf("The deleted item is:%d\n",temp->info);
        free(temp);
    }
}

void display()
{
    Nodetype *temp;

    if (start == NULL)
    {
        printf("The list is empty!\n");
        return;
    }
    temp = start;
    printf("The list elements are: ");
    while (temp != last)
    {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("%d ", temp->info);
    printf("\n");
}



