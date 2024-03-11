/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct Node
{
    int value;
    struct Node *next; // point to the next
    // element of the current element
} Node;
Node *makeNode(int v)
{ // allocate memory for a new node
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}
Node *insertLastRecursive(Node *h, int v)
{
    if (h == NULL)
    {
        return makeNode(v);
    }
    h->next = insertLastRecursive(h->next, v);
    return h;
}
void printfNode(Node *node)
{
    printf("%d", node->value);
}
void printfList(Node *h)
{
    printf("\n");
    for (Node *p = h; p != NULL; p = p->next)
    {
        printfNode(p);
    }
    printf("\n");
}
int main(){
    int value[MAX];
    for(i=0;;i++){
        scanf("%d",value[i]);
        if(value[i]==NULL){
            break;
        }
    }
}*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *makenode(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void addelement(node **head, int x)
{
    node *newnode = makenode(x);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    }
}

bool check_recycle(node *head)
{
    node *first = head;
    node *last = head;
    while (first != NULL && first->next != NULL)
    {
        first = first->next->next;
        last = last->next;
        if (first == last)
        {
            return true;
        }
    }
    return false;
}
void make_link_list(node *head, int pos)
{
    node *curr = NULL;
    int i = 0;
    node *tmp = head;
    while (tmp != NULL)
    {
        if (i == pos)
        {
            curr = tmp;
        }
        tmp = tmp->next;
        i++;
    }
    tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = curr;
}

int main()
{
    node *head = NULL;
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++)
    {
        int k;
        scanf("%d", &k);
        addelement(&head, k);
    }
    int pos;
    scanf("%d", &pos);
    make_link_list(head, pos);
    if (check_recycle(head))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}