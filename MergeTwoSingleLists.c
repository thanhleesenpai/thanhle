/*typedef struct Node
{
    int value;
    struct Node *next;
} Node;
Node *makeNode(int v)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}
Node *head;
Node *head1;
Node *head2;
Node *insertLastRecursive(Node *h, int v)
{
    if (h == NULL)
    {
        return makeNode(v);
    }
    h->next = insertLastRecursive(h->next, v);
    return h;
}
Node *reverse(Node *h)
{
    Node *p = h;
    Node *pp = NULL;
    Node *np = NULL;
    while (p != NULL)
    {
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}
void printfNode(Node *node)
{
    printf("Value: %d", node->value);
}
void printfList(Node *h)
{
    printf("List:\n");
    for (Node *p = h; p != NULL; p = p->next)
    {
        printfNode(p);
    }
    printf("\n");
}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 1000

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head1 = NULL, *head2 = NULL, *head3 = NULL;

node *makenode(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void addlast(node **head, int a)
{
    if (*head == NULL)
    {
        *head = makenode(a);
    }
    else
    {
        node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        node *newnode = makenode(a);
        tmp->next = newnode;
    }
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
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

void reverse(node **head)
{
    node *tmp = *head;
    node *tmp1 = NULL;
    node *tmp2 = NULL;
    while (tmp != NULL)
    {
        tmp1 = tmp->next;
        tmp->next = tmp2;
        tmp2 = tmp;
        tmp = tmp1;
    }
    *head = tmp2;
}

void iSort(node *head1, node *head2, node **head3)
{

    while (1)
    {
        if (head1 == NULL)
        {
            while (head2 != NULL)
            {
                addlast(head3, head2->data);
                head2 = head2->next;
            }
            break;
        }
        if (head2 == NULL)
        {
            while (head1 != NULL)
            {
                addlast(head3, head1->data);
                head1 = head1->next;
            }
            break;
        }
        if ((head1->data) > (head2->data))
        {
            addlast(head3, head2->data);
            head2 = head2->next;
        }
        else
        {
            addlast(head3, head1->data);
            head1 = head1->next;
        }
    }
}

void dSort(node *head1, node *head2, node **head3)
{
    while (1)
    {
        if (head1 == NULL)
        {
            while (head2 != NULL)
            {
                addlast(head3, head2->data);
                head2 = head2->next;
            }
            break;
        }
        if (head2 == NULL)
        {
            while (head1 != NULL)
            {
                addlast(head3, head1->data);
                head1 = head1->next;
            }
            break;
        }
        if ((head1->data) < (head2->data))
        {
            addlast(head3, head2->data);
            head2 = head2->next;
        }
        else
        {
            addlast(head3, head1->data);
            head1 = head1->next;
        }
    }
}

int main()
{
    int n, m, a, b;
    char s[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        addlast(&head1, a);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b);
        addlast(&head2, b);
    }
    scanf("%s", s);
    if (strcmp(s, "iSort") == 0)
    {
        if ((head1->data) > (head1->next->data))
        {
            reverse(&head1);
        }
        if ((head2->data) > (head2->next->data))
        {
            reverse(&head2);
        }
        iSort(head1, head2, &head3);
    }
    if (strcmp(s, "dSort") == 0)
    {
        if ((head1->data) < (head1->next->data))
        {
            reverse(&head1);
        }
        if ((head2->data) < (head2->next->data))
        {
            reverse(&head2);
        }
        dSort(head1, head2, &head3);
    }
    print(head3);
}