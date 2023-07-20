#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
typedef struct node Nodetype;
Nodetype *head;

void insertAtFirst(int);
void insertAtLast(int);
void insertAtPosition(int);
void deleteAtfirst();
void deleteAtLast();
void deleteAtPosition();
void display();
void countNode();

int main()
{
    int choice = 0;
    int item;
    printf("\n\n");
    printf("1.Insert at First:\n ");
    printf("2.Insert at last:\n");
    printf("3.Insert at Given position:\n ");
    printf("4.Delete at First:\n");
    printf("5.Delete at last:\n");
    printf("6.Delete at Given position:\n ");
    printf("7.Display the content of list:\n ");
    printf("8.Counting of Nodes:\n");
    printf("9. EXIT!\n");
    printf("\n\n");
    while (choice != 9)
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
            printf("Enter the item to be inserted : \t");
            scanf("%d", &item);
            insertAtPosition(item);
            break;
        case 4:
            deleteAtfirst();
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            display();
            break;
        case 8:
            countNode();
            break;
        case 9:
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
    n->next = head;
    head = n;
}

void insertAtLast(int item)
{
    Nodetype *n;
    Nodetype *temp;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    n->info = item;
    if (head == NULL)
    {
        n->next = NULL;
        head = n;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        n->next = NULL;
        temp->next = n;
    }
}

// void insertAtLast(int item)
// {
//     Nodetype *n,*temp;
//     n = (Nodetype *)malloc(sizeof(Nodetype));
//     if(n==NULL)
//     {
//         printf("Invalid operation!");
//     }
//     else
//     {
//         n->info = item;
//         if(head==NULL)
//         {
//             n->next = NULL;
//             head = n;
//             printf("\nNode inserted");
//         }
//         else
//         {
//             temp = head;
//             while(temp->next!=NULL)
//             {
//                 temp = temp ->next;
//             }
//             temp->next = n;
//             n->next = NULL;
//             printf("\nNode inserted..");
//         }
//     }
// }

void insertAtPosition(int item)
{
    int pos, i;
    Nodetype *n;
    Nodetype *temp;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    temp = head;
    n->info = item;
    if (head == NULL)
    {
        n->next = NULL;
        head = n;
    }
    else
    {
        printf("Enter the position of a node at which u want to insert an new node:\t");
        scanf("%d", &pos);
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteAtfirst()
{
    Nodetype *temp;
    if (head == NULL)
    {
        printf("Invalid operation");
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Item deleted \n");
    }
}

void deleteAtLast()
{
    Nodetype *hold, *temp;
    if (head == NULL)
    {
        printf("Invalid operarion\n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            hold = temp;
            temp = temp->next;
        }
        hold->next = NULL;
        free(temp);
        printf("Deleted Node from the last....\n");
    }
}

void deleteAtPosition()
{
    Nodetype *n, *temp;
    int pos, i;
    printf("\n Enter the location of the node which you want to perform deletion: \t");
    scanf("%d", &pos);
    n = head;
    for (i = 1; i <= pos - 1; i++)
    {
        temp = n;
        n = n->next;

        if (n == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    temp->next = n->next;
    free(n);
    printf("\nDeleted node %d ", pos);
}

void countNode()
{
    int cnt = 0;
    Nodetype *temp;
    temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    printf("\n\n");
    printf("Total nodes=%d\n", cnt);
}
void display()
{
    Nodetype *n;
    n = head;
    if (n == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("The items are: \n");
        while (n != NULL)
        {
            printf("%d\t", n->info);
            n = n->next;
        }
        printf("\n\n");
    }
}