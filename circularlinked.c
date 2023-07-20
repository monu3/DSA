#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
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
        start = n;
        last = n;
    }
    else
    {

        n->info = item;
        n->next = start;
        start = n;
        last->next = n;
    }
}

void insertAtLast(int item)
{
    Nodetype *n;
    n = (Nodetype *)malloc(sizeof(Nodetype));
    if (start == NULL)
    {
        n->info = item;
        n->next = n;
        start = n;
        last = n;
    }
    else
    {
        n->info = item;
        n->next = start;
        last->next = n;
        last = n;
        last->next = start;
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
        printf("The deleted item is:%d\n",temp->info);
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
        printf("The deleted item is:%d\n",temp->info);
        free(temp);
        start = last = NULL;
    }
    else
    {

        temp = start;
        while (temp->next != last)
            temp = temp->next;
        hold = temp->next;
        last = temp;
        last->next = start;
        printf("The deleted item is:%d\n",hold->info);
        free(hold);
    }
}

void display()
{
    Nodetype *temp;
    if(start == NULL)
    {
        printf("The list is empty!");
        return ;
    }

    else
    {
        temp = start;
        printf("\nThe list is:\t");
        while (temp!=last)
        {
            printf("%d\t",temp->info);
            temp = temp->next;
        }
         printf("%d\t",temp->info);
         printf("\n");
    }

}