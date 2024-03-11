#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node
{
    char name[256];
    struct Node *leftMostChild;
    struct Node *rightSibling;
} Node;
Node *root;
Node *makeNode(char *name)
{
    Node *p = (Node *)malloc(sizeof(Node));
    strcpy(p->name, name);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}
Node *find(Node *r, char *name)
{
    if (r == NULL)
        return NULL;
    if (strcmp(r->name, name) == 0)
        return r;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *q = find(p, name);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }
}
Node *addLast(Node *p, char *name)
{
    if (p == NULL)
        return makeNode(name);
    p->rightSibling = addLast(p->rightSibling, name);
    return p;
}

void MakeRoot(char *name)
{
    if (root == NULL)
    {
        root = makeNode(name);
    }
}

void addChild(char *name, char *child)
{
    Node *r = find(root, name);
    if (r == NULL)
        return;
    r->leftMostChild = addLast(r->leftMostChild, child);
}

void loadTree(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("Failed to open file %s\n", filename);
        return;
    }
    root = NULL;
    char line[256];
    while (fgets(line, sizeof(line), f))
    {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, "$$") == 0)
            break;
        char *token = strtok(line, " ");
        char name[256];
        strcpy(name, token);
        if (root == NULL)
        {
            root = makeNode(name);
        }
        while (token != NULL)
        {
            token = strtok(NULL, " ");
            if (token == NULL || strcmp(token, "$") == 0)
                break;
            addChild(name, token);
        }
    }
    fclose(f);
}
void printTree(Node *r)
{
    if (r == NULL)
        return;
    printf("%s: ", r->name);
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        printf("%s ", p->name);
        p = p->rightSibling;
    }
    printf("\n");
    p = r->leftMostChild;
    while (p != NULL)
    {
        printTree(p);
        p = p->rightSibling;
    }
}
void printTreeF(Node *r, FILE *f)
{
    if (r == NULL)
        return;
    fprintf(f, "%s ", r->name);
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        fprintf(f, "%s ", p->name);
        p = p->rightSibling;
    }
    fprintf(f, " $\n");
    p = r->leftMostChild;
    while (p != NULL)
    {
        printTreeF(p, f);
        p = p->rightSibling;
    }
}
void processFind()
{
    char name[256];
    scanf("%s", name);
    Node *p = find(root, name);
    if (p == NULL)
        printf("Not Found %s\n", name);
    else
        printf("Found %s\n", name);
}
void processFindChildren()
{
    char name[256];
    scanf("%s", name);
    Node *p = find(root, name);
    if (p == NULL)
        printf("Not Found %s\n", name);
    else
    {
        printf("Found %s with children: ", name);
        Node *q = p->leftMostChild;
        while (q != NULL)
        {
            printf("%s ", q->name);
            q = q->rightSibling;
        }
    }
    printf("\n");
}
int height(Node *p)
{
    if (p == NULL)
        return 0;
    int maxH = 0;
    Node *q = p->leftMostChild;
    while (q != NULL)
    {
        int h = height(q);
        maxH = maxH < h ? h : maxH;
        q = q->rightSibling;
    }
    return maxH + 1;
}
void processHeight()
{
    char name[256];
    scanf("%s", name);
    Node *p = find(root, name);
    if (p == NULL)
        printf("Not Found %s\n", name);
    else
    {
        printf("Found %s having height = %d\n", name, height(p));
    }
}
int count(Node *r)
{
    if (r == NULL)
        return 0;
    int cnt = 1;
    Node *q = r->leftMostChild;
    while (q != NULL)
    {
        cnt += count(q);
        q = q->rightSibling;
    }
    return cnt;
}
void processCount()
{
    printf("Number of members is %d\n", count(root));
}
void processStore()
{
    char filename[256];
    scanf("%s", filename);
    FILE *f = fopen(filename, "w");
    printTreeF(root, f);
    fprintf(f, "$$");
    fclose(f);
}
void freeTree(Node *r)
{
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    while (p != NULL)
    {
        Node *sp = p->rightSibling;
        freeTree(p);
        p = sp;
    }
    // printf("free node %s\n", r->name);
    free(r);
    r = NULL;
}

// void PreOrder(Node *r)
// {
//     if (r == NULL)
//         return;
//     printf("%s ", r->name);
//     Node *p = r->leftMostChild;
//     PreOrder(p);
//     while (p != NULL)
//     {
//         PreOrder(p);
//         p = p->rightSibling;
//     }
// }

void PreOrder(struct Node *r)
{
    if (r == NULL)
        return;

    printf("%s ", r->name);

    // Duyệt qua cây con bên trái (leftMostChild)
    PreOrder(r->leftMostChild);

    // Duyệt qua cây con kế tiếp cùng cấp (rightSibling)
    PreOrder(r->rightSibling);
}

void InOrder(Node *r)
{
    if (r == NULL)
        return;
    Node *p = r->leftMostChild;
    InOrder(p);
    printf("%s ", r->name);
    if (p != NULL)
        p = p->rightSibling;
    while (p != NULL)
    {
        InOrder(p);
        p = p->rightSibling;
    }
}

// void PostOrder(Node *r)
// {
//     if (r == NULL)
//         return;
//     Node *p = r->leftMostChild;
//     PostOrder(p);
//     while (p != NULL)
//     {
//         PostOrder(p);
//         p = p->rightSibling;
//     }
//     printf("%s ", r->name);
// }

void PostOrder(struct Node *r)
{
    if (r == NULL)
        return;

    struct Node *p = r->leftMostChild;

    // Duyệt qua cây con bên trái (leftMostChild)
    PostOrder(p);

    // Duyệt qua cây con kế tiếp cùng cấp (rightSibling)
    while (p != NULL)
    {
        p = p->rightSibling;
        PostOrder(p);
    }

    // In giá trị của nút hiện tại sau khi đã duyệt qua tất cả các cây con
    printf("%s ", r->name);
}

void main()
{
    char command[100];
    char filename[50];
    char name[50];
    char child[50];
    while (1)
    {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0)
            break;
        else if (strcmp(cmd, "MakeRoot") == 0)
        {
            char name[256];
            scanf("%s", name);
            MakeRoot(name);
        }
        else if (strcmp(cmd, "Load") == 0)
        {
            printf("Filename: ");
            char filename[256];
            scanf("%s", filename);
            loadTree(filename);
        }
        else if (strcmp(cmd, "Print") == 0)
            printTree(root);
        else if (strcmp(cmd, "Find") == 0)
            processFind();
        else if (strcmp(cmd, "FindChildren") == 0)
            processFindChildren();
        else if (strcmp(cmd, "Height") == 0)
            processHeight();
        else if (strcmp(cmd, "Count") == 0)
            processCount();
        else if (strcmp(cmd, "Insert") == 0)
        {
            char name[256], child[256];
            scanf("%s", child);
            scanf("%s", name);
            addChild(name, child);
        }
        else if (strcmp(cmd, "InOrder") == 0)
        {
            InOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "PreOrder") == 0)
        {
            PreOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "PostOrder") == 0)
        {
            PostOrder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "Store") == 0)
            processStore();
    }
    freeTree(root);
}