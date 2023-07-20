#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
}; 
typedef struct node Nodetype;
Nodetype *head = NULL;

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
    n->info = item;
    if (head == NULL)
    {
        n->prev = NULL;
        n->next = NULL;
        head = n;
    }
    else
    {
        n->prev = NULL;
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void insertAtLast(int item)
{
    Nodetype *n, *temp;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    n->info = item;
    n->next = NULL;
    if (head == NULL)
    {
        head = n;
        n->prev = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void deleteAtfirst()
{
    Nodetype *temp;

    if (head == NULL)
    {
        printf("The list is empty!");
        return;
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        free(temp);
    }
    else
    {
        temp = head;
        printf("The deleted item is %d\n", head->info);
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void deleteAtLast()
{
    Nodetype *temp, *hold;
    if (head == NULL)
    {
        printf("The list is empty!");
        return;
    }
    else if (head->next == NULL)
    {
        temp = head;
        printf("\n the Deleted item is %d\n", head->info);
        head = NULL;
        free(temp);
    }
    else
    {

        temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
        hold = temp->next;
        temp->next = NULL;
        printf("\n The deleted item is %d\n", hold->info);
        free(hold);
    }
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n The list is empty");
        return;
    }
    else
    {

        temp = head;
        printf("\n The list is:\t");
        while (temp != NULL)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
       // printf("%d\t",temp->info);
        printf("\n");
    }
}