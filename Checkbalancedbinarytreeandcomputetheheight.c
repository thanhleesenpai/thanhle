#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *root = NULL;

Node *makeNode(int id)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = id;
    p->leftChild = NULL;
    p->rightChild = NULL;
    return p;
}

Node *find(Node *u, int id)
{
    if (u == NULL)
        return NULL;
    if (u->id == id)
        return u;
    Node *p = find(u->leftChild, id);
    if (p != NULL)
        return p;
    return find(u->rightChild, id);
}
void AddLeft(int u, int left)
{
    Node *pu = find(root, u);
    if (pu == NULL)
    {
        return;
    }
    if (pu->leftChild != NULL)
    {
        return;
    }
    pu->leftChild = makeNode(left);
}
void AddRight(int u, int right)
{
    Node *pu = find(root, u);
    if (pu == NULL)
    {
        return;
    }
    if (pu->rightChild != NULL)
    {
        return;
    }
    pu->rightChild = makeNode(right);
}
void printTree(Node *r)
{
    if (r == NULL)
        return;
    printf("%d: ", r->id);
    if (r->leftChild == NULL)
        printf("leftChild = NULL");
    else
        printf("leftChild = %d", r->leftChild->id);
    if (r->rightChild == NULL)
        printf(", rightChild = NULL");
    else
        printf(", rightChild = %d", r->rightChild->id);
    printf("\n");
    printTree(r->leftChild);
    printTree(r->rightChild);
}
int height(Node *p)
{
    if (p == NULL)
        return 0;
    int maxH = 0;
    int hl = height(p->leftChild);
    if (maxH < hl)
        maxH = hl;
    int hr = height(p->rightChild);
    if (maxH < hr)
        maxH = hr;
    return maxH + 1;
}

// Node *balanceornot(Node *p)
// {
//     if (p == NULL)
//         return NULL;
//     if (p->leftChild == NULL && p->rightChild == NULL)
//     {
//         return NULL;
//     }
//     if (p->leftChild != NULL && p->rightChild == NULL)
//     {

//         return p;
//     }
//     if (p->leftChild == NULL && p->rightChild != NULL)
//     {

//         return p;
//     }
//     Node *q = balanceornot(p->leftChild);
//     if (q != NULL)
//     {
//         return q;
//     }
//     q = balanceornot(p->rightChild);
//     if (q != NULL)
//     {
//         return q;
//     }
//     return NULL;
// }
int isBalanced(struct Node *root)
{
    if (root == NULL)
        return 1;

    int leftHeight = height(root->leftChild);
    int rightHeight = height(root->rightChild);

    // Kiểm tra sự chênh lệch chiều cao
    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root->leftChild) &&
        isBalanced(root->rightChild))
        return 1;

    return 0;
}
void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->leftChild);
    freeTree(root->rightChild);
    free(root);
}

int main()
{
    char cmd[256];
    // printf("Enter a command: ");
    while (1)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "MakeRoot") == 0)
        {
            int id;
            scanf("%d", &id);
            root = makeNode(id);
            // printTree(root);
        }
        if (strcmp(cmd, "AddLeft") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            AddLeft(v, u);
            // printTree(root);
        }
        if (strcmp(cmd, "AddRight") == 0)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            AddRight(v, u);
            // printTree(root);
        }
        if (strcmp(cmd, "*") == 0)
        {
            break;
        }
    }
    // printTree(root);
    //  Node *p = balanceornot(root);
    //  if (p != NULL)
    //  {
    //      printf("0");
    //  }
    //  else
    //  {
    //      printf("1");
    //  }
    printf("%d", isBalanced(root));
    printf(" %d", height(root));
    freeTree(root);
}