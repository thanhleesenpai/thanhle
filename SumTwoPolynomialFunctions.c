#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100

typedef struct node
{
    int coef;
    int exp;
    struct node *next;
} node;

node *head1 = NULL, *head2 = NULL, *head3 = NULL;
node *makenode(int coef, int exp)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = NULL;

    return newnode;
}
void addlast(node **head, int coef, int exp)
{
    if (*head == NULL)
    {
        *head = makenode(coef, exp);
        return;
    }
    node *p = *head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = makenode(coef, exp);
}

int count(node *head)
{
    int a = 0;
    if (head == NULL)
    {
        return 0;
    }
    while (head != NULL)
    {
        head = head->next;
        a++;
    }
    return a;
}
void print(node *head, int n)
{
    int i = 0;
    if (head == NULL)
    {
        printf("1 0");
        return;
    }
    printf("%d ", n);
    while (head != NULL)
    {
        if (head->exp == i)
        {
            printf("%d ", head->coef);
            head = head->next;
        }
        else
        {
            printf("0 ");
        }

        i++;
    }
}
void input(node **head1, node **head2)
{
    int n, m, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a != 0)
        {
            addlast(head1, a, i);
        }
    }
    //	print(*head1,0);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        if (a != 0)
        {
            addlast(head2, a, i);
        }
    }
    //	print(*head2,0);
}
void processplus(node *head1, node *head2, node **head3)
{
    int i = 0;
    while (1)
    {
        if (head1 == NULL)
        {
            while (head2 != NULL)
            {
                addlast(head3, head2->coef, head2->exp);
                head2 = head2->next;
            }
            break;
        }
        if (head2 == NULL)
        {
            while (head1 != NULL)
            {
                addlast(head3, head1->coef, head1->exp);
                head1 = head1->next;
            }
            break;
        }
        if ((head1->exp == i) && (head2->exp == i))
        {
            if (head1->coef + head2->coef != 0)
            {
                addlast(head3, head1->coef + head2->coef, i);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else
        {
            if (head1->exp == i)
            {
                addlast(head3, head1->coef, i);
                head1 = head1->next;
            }
            if (head2->exp == i)
            {
                addlast(head3, head2->coef, i);
                head2 = head2->next;
            }
        }
        i++;
    }
}
void processminus(node *head1, node *head2, node **head3)
{
    int i = 0;
    while (1)
    {
        if (head1 == NULL)
        {
            while (head2 != NULL)
            {
                addlast(head3, -head2->coef, head2->exp);
                head2 = head2->next;
            }
            break;
        }
        if (head2 == NULL)
        {
            while (head1 != NULL)
            {
                addlast(head3, head1->coef, head1->exp);
                head1 = head1->next;
            }
            break;
        }
        if ((head1->exp == i) && (head2->exp == i))
        {
            if (head1->coef - head2->coef != 0)
            {
                addlast(head3, head1->coef - head2->coef, i);
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else
        {
            if (head1->exp == i)
            {
                addlast(head3, head1->coef, i);
                head1 = head1->next;
            }
            if (head2->exp == i)
            {
                addlast(head3, -head2->coef, i);
                head2 = head2->next;
            }
        }
        i++;
    }
}

int main()
{
    char a[1000];
    input(&head1, &head2);
    scanf("%s", a);
    if (strcmp(a, "plus") == 0)
    {
        processplus(head1, head2, &head3);
    }
    if (strcmp(a, "minus") == 0)
    {
        processminus(head1, head2, &head3);
    }
    print(head3, count(head3));
    return 1;
}