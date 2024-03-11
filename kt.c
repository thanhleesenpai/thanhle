#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 256

typedef struct node
{
    char malop[max];
    char mahocphan[max];
    struct node *next;
} node;

node *head = NULL;

node *makenode(char *malop, char *mahocphan)
{
    node *newnode = (node *)malloc(sizeof(node));
    strcpy(newnode->malop, malop);
    strcpy(newnode->mahocphan, mahocphan);
    newnode->next = NULL;
    return newnode;
}

void addlast(node **head, char *malop, char *mahocphan)
{
    if (*head == NULL)
    {
        *head = makenode(malop, mahocphan);
    }
    else
    {
        node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        node *newnode = makenode(malop, mahocphan);
        tmp->next = newnode;
    }
}
void addFront(node **head, char *malop, char *mahocphan)
{
    node *newNode = makenode(malop, mahocphan);
    newNode->next = (*head);
    (*head) = newNode;
}
void print(node *head)
{
    if (head == NULL)
    {
        printf("NULL");
        return;
    }
    else
    {
        while (head != NULL)
        {
            printf("%s\t%s\n", head->malop, head->mahocphan);
            head = head->next;
        }
    }
}

void readf(node **head)
{
    node *tmp = *head;
    *head = NULL;
    free(tmp);
    FILE *f;
    f = fopen("sinh_vien.txt", "r");
    if (f == NULL)
    {
        printf("file ko ton tai");
    }
    else
    {
        char malop[max], mahocphan[max];
        while (fscanf(f, "%s", malop) != EOF)
        {
            fscanf(f, "%s", mahocphan);
            addlast(*&head, malop, mahocphan);
        }
    }
    fclose(f);
}

void Remove(node **head, char *malop)
{
    if (*head == NULL)
    {
        return;
    }
    else
    {
        node *tmp = *head;
        if (strcmp(tmp->malop, malop) == 0)
        {
            *head = tmp->next;
            free(tmp);
        }
        else
        {
            while (tmp->next != NULL)
            {
                if (strcmp(tmp->malop, malop) == 0)
                {
                    node *tmp1 = tmp->next;
                    if (tmp->next->next != NULL)
                    {
                        tmp->next = tmp->next->next;
                        free(tmp1);
                    }
                    else
                    {
                        tmp->next = NULL;
                        free(tmp1);
                    }
                }
                tmp = tmp->next;
            }
        }
    }
}

void find(node *head, char *malop)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        while (head != NULL)
        {
            if (strcmp(head->malop, malop) == 0)
            {
                printf("%s\t%s\n", head->malop, head->mahocphan);
                return;
            }
            head = head->next;
        }
    }
}

void Printf(node *head)
{
    FILE *f;
    f = fopen("sinh_vien.txt", "w");
    while (head != NULL)
    {
        fprintf(f, "%s\t%s\n", head->malop, head->mahocphan);
        head = head->next;
    }
    fclose(f);
}
void addnodetofront()
{
    char malop[max];
    char mahocphan[max];

    printf("Enter malop: ");
    scanf("%s", malop);

    printf("Enter mahocphan: ");
    scanf("%s", mahocphan);

    addFront(&head, malop, mahocphan);
    printf("Node added to the front of the linked list.\n");
}
void addnodetoend()
{
    char malop[max];
    char mahocphan[max];

    printf("Enter malop: ");
    scanf("%s", malop);

    printf("Enter mahocphan: ");
    scanf("%s", mahocphan);

    addlast(&head, malop, mahocphan);
    printf("Node added to the end of the linked list.\n");
}

int main()
{
    int choice;
    char malop[max];
    char mahocphan[max];

    while (1)
    {
        printf("\n----- Linked List Operations -----\n");
        printf("1. Read from File\n");
        printf("2. Print Linked List\n");
        printf("3. Find Node\n");
        printf("4. Add Node To Front\n");
        printf("5. Add Node To End\n");
        printf("6. Remove Node\n");
        printf("7. Save to File\n");
        printf("8. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Read from file
            readf(&head);
            printf("Linked List loaded from file.\n");
            break;

        case 2:
            // Print Linked List
            printf("Linked List:\n");
            print(head);
            break;
        case 3:
            // Find Node
            printf("Enter malop to find: ");
            scanf("%s", malop);
            find(head, malop);
            break;
        case 4:
            // Add node to end
            addnodetofront();
            break;
        case 5:
            // Add node to end
            addnodetoend();
            break;

        case 6:
            // Remove Node
            printf("Enter malop to remove: ");
            scanf("%s", malop);
            Remove(&head, malop);
            printf("Node removed.\n");
            break;

        case 7:
            // Save to file
            Printf(head);
            printf("Linked List saved to file.\n");
            break;

        case 8:
            // Exit
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}