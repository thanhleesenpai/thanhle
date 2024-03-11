#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
/*
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
Node *removeNodeRecursive(Node *h, int v)
{
    if (h == NULL)
        return NULL;
    if (h->value == v)
    {
        Node *tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }
    h->next = removeNodeRecursive(h->next, v);
    return h;
}
Node *removeAll(Node *h, int v)
{
    // remove all nodes having value v from the linked list headed by h
    if (h == NULL)
        return NULL;
    if (h->value == v)
    {
        Node *tmp = h;
        h = h->next;
        free(tmp);
        h = removeAll(h, v); // continue to remove other elements having value v
        return h;
    }
    h->next = removeAll(h->next, v);
    return h;
}
int countRecursive(Node *h)
{
    if (h == NULL)
        return 0;
    return 1 + countRecursive(h->next);
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
int main()
{
    Node *h = makeNode(2000);
    insertLastRecursive(h, 1000);
    printfList(h);
    removeNodeRecursive(h, 2000);
    removeAll(h, 3000);
    printfList(h);
    return 0;
}
*/
/*
#define MAX_L 256
typedef struct Profile
{
    char name[MAX_L];  // ten sinh vien
    char email[MAX_L]; // email cua sinh vien
    struct Profile *next;
} Profile;
Profile *first, *last;
Profile *makeProfile(char *name, char *email)
{
    Profile *node = (Profile *)malloc(sizeof(Profile));
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    return node;
}
void initList()
{
    first = NULL;
    last = NULL;
}
int listEmpty()
{
    return first == NULL && last == NULL;
}
void insertLast(char *name, char *email)
{
    Profile *profile = makeProfile(name, email);
    if (listEmpty())
    {
        first = profile;
        last = profile;
    }
    else
    {
        last->next = profile;
        last = profile;
    }
}
void printList()
{
    for (Profile *p = first; p != NULL; p = p->next)
        printf("%s, %s\n", p->name, p->email);
}
Profile *removeProfile(Profile *f, char *name)
{
    if (listEmpty())
        return NULL;
    if (strcmp(f->name, name) == 0)
    {
        Profile *tmp = f->next;
        free(f);
        if (tmp == NULL)
            last = NULL;
        return tmp;
    }
    else
    {
        f->next = removeProfile(f->next, name);
        return f;
    }
}
void load(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        printf("Load data -> file not found\n");
    while (!feof(f))
    {
        char name[256], email[256];
        fscanf(f, "%s%s", name, email);
        insertLast(name, email);
    }
    fclose(f);
}
void processFind()
{
    char name[256];
    scanf("%s", name);
    Profile *profile = NULL;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (strcmp(p->name, name) == 0)
        {
            profile = p;
            break;
        }
    }
    if (profile == NULL)
    {
        printf("NOT FOUND profile %s\n", name);
    }
    else
    {
        printf("FOUND profile %s, %s\n", profile->name, profile->email);
    }
}
void processLoad()
{ // load du lieu tu file vao bo nho
    char filename[256];
    scanf("%s", filename);
    load(filename);
}
void processStore()
{ // luu du lieu DS vao file van ban
    char filename[256];
    scanf("%s", filename);
    FILE *f = fopen(filename, "w");
    for (Profile *p = first; p != NULL; p = p->next)
    {
        fprintf(f, "%s %s", p->name, p->email);
        if (p->next != NULL)
            fprintf(f, "\n");
    }
    fclose(f);
}
void processInsert()
{
    char name[256], email[256];
    scanf("%s%s", name, email);
    insertLast(name, email);
}
void processRemove()
{
    char name[256];
    scanf("%s", name);
    first = removeProfile(first, name);
}
int main()
{ // chay chuong trinh trong che do interactive
    initList();
    while (1)
    {
        printf("Enter command: ");
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0)
            break;
        else if (strcmp(cmd, "Load") == 0)
            processLoad();
        else if (strcmp(cmd, "Print") == 0)
            printList();
        else if (strcmp(cmd, "Find") == 0)
            processFind();
        else if (strcmp(cmd, "Insert") == 0)
            processInsert();
        else if (strcmp(cmd, "Remove") == 0)
            processRemove();
        else if (strcmp(cmd, "Store") == 0)
            processStore();
    }
}
*/
/*
#define MAX_L 256
typedef struct Profile
{
    char name[MAX_L];
    char email[MAX_L];
    struct Profile *next; // pointer to the next element
    struct Profile *prev; // pointer to the predecessor
} Profile;
Profile *first, *last;
Profile *makeProfile(char *name, char *email)
{
    Profile *node = (Profile *)malloc(sizeof(Profile));
    strcpy(node->name, name);
    strcpy(node->email, email);
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void initList()
{
    first = NULL;
    last = NULL;
}
int listEmpty()
{
    return first == NULL && last == NULL;
}
void printListLeft2Right()
{
    for (Profile *p = first; p != NULL; p = p->next)
        printf("%s, %s\n", p->name, p->email);
}
void printListRight2Left()
{
    for (Profile *p = last; p != NULL; p = p->prev)
        printf("%s, %s\n", p->name, p->email);
}
void insertLast(char *name, char *email)
{
    Profile *profile = makeProfile(name, email);
    if (listEmpty())
    {
        first = profile;
        last = profile;
    }
    else
    {
        last->next = profile;
        profile->prev = last;
        last = profile;
    }
}
Profile *find(char *name)
{
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (strcmp(p->name, name) == 0)
        {
            return p;
        }
    }
    return NULL;
}
void removeProfile(char *name)
{
    if (listEmpty())
        return NULL;
    Profile *profile = find(name);
    if (profile == NULL)
    {
        printf("NOT FOUND %s\n", name);
    }
    else
    {
        Profile *left = profile->prev;
        Profile *right = profile->next;
        if (left != NULL)
            left->next = right;
        if (right != NULL)
            right->prev = left;
        if (left == NULL)
            first = right;
        if (right == NULL)
            last = left;
        free(profile);
    }
}
void load(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        printf("Load data -> file not found\n");
    initList();
    while (!feof(f))
    {
        char name[256], email[256];
        fscanf(f, "%s%s", name, email);
        insertLast(name, email);
        printf("insert %s, %s\n", name, email);
    }
    fclose(f);
}
void processFind()
{
    char name[256];
    scanf("%s", name);
    Profile *profile = find(name);
    if (profile == NULL)
    {
        printf("NOT FOUND profile %s\n", name);
    }
    else
    {
        printf("FOUND profile %s, %s\n", profile->name, profile->email);
    }
}
void processLoad()
{
    char filename[256];
    scanf("%s", filename);
    load(filename);
}
void processStore()
{
    char filename[256];
    scanf("%s", filename);
    FILE *f = fopen(filename, "w");
    for (Profile *p = first; p != NULL; p = p->next)
    {
        fprintf(f, "%s %s", p->name, p->email);
        if (p->next != NULL)
            fprintf(f, "\n");
    }
    fclose(f);
}
void processInsert()
{
    char name[256], email[256];
    scanf("%s%s", name, email);
    insertLast(name, email);
}
void processRemove()
{
    char name[256];
    scanf("%s", name);
    removeProfile(name);
}
void processPrintList()
{
    printf("Danh sach tu trai qua phai\n");
    printListLeft2Right();
    printf("Danh sach tu phai qua trai\n");
    printListRight2Left();
}
void finalize()
{
    Profile *p = first;
    while (p != NULL)
    {
        Profile *np = p->next;
        free(p);
        p = np;
    }
}
int main()
{
    initList();
    while (1)
    {
        printf("Enter command: ");
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0)
            break;
        else if (strcmp(cmd, "Load") == 0)
            processLoad();
        else if (strcmp(cmd, "Print") == 0)
            processPrintList();
        else if (strcmp(cmd, "Find") == 0)
            processFind();
        else if (strcmp(cmd, "Insert") == 0)
            processInsert();
        else if (strcmp(cmd, "Remove") == 0)
            processRemove();
        else if (strcmp(cmd, "Store") == 0)
            processStore();
    }
    finalize();
}
*/
/*
typedef struct Node
{
    char c;
    struct Node *next;
} Node;
Node *top;
Node *makeNode(char x)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->c = x;
    p->next = NULL;
    return p;
}
void initStack()
{
    top = NULL;
}
int stackEmpty()
{
    return top == NULL;
}
void push(char x)
{
    Node *p = makeNode(x);
    p->next = top;
    top = p;
}
char pop()
{
    if (stackEmpty())
        return ' ';
    char x = top->c;
    Node *tmp = top;
    top = top->next;
    free(tmp);
    return x;
}
int match(char a, char b)
{
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}
int check(char *s)
{
    initStack();
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
        }
        else
        {
            if (stackEmpty())
                return 0;
            char x = pop();
            if (!match(x, s[i]))
                return 0;
        }
    }
    return stackEmpty();
}
int main()
{
    char s[MAX];
    scanf("%s", &s);
    printf("%d", check(s));
}
typedef struct Node
{
    int row, col;        // chỉ số hang và cột của trạng thái hiện tại
    int step;            // số bước di chuyển để đi từ trạng thái xuất phát đến trạng thái hiện tại
    struct Node *next;   // con trỏ đến phần tử tiếp theo trong hàng đợi
    struct Node *parent; // con trỏ trỏ đến trạng thái sinh ra trạng thái hiện tại
} Node;
Node *head, *tail;
Node *listNode[MAX * MAX]; // mảng lưu các phần tử được cấp phát động, để giải phóng BN
int szList = 0;            // số phần tử của listNode
int A[MAX][MAX];
int n, m;
int r0, c0;
int visited[MAX][MAX];
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
Node *finalNode;
Node *makeNode(int row, int col, int step, Node *parent)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->next = NULL;
    node->parent = parent;
    node->step = step;
    return node;
}
void initQueue()
{
    head = NULL;
    tail = NULL;
}
int queueEmpty()
{
    return head == NULL && tail == NULL;
}
void pushQueue(Node *node)
{
    if (queueEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}
Node *popQueue()
{
    if (queueEmpty())
        return NULL;
    Node *node = head;
    head = node->next;
    if (head == NULL)
        tail = NULL;
    return node;
}

void input()
{
    FILE *f = fopen("maze.txt", "r");
    fscanf(f, "%d%d%d%d", &n, &m, &r0, &c0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            fscanf(f, "%d", &A[i][j]);
        }
    }
    fclose(f);
}

int legal(int row, int col)
{
    return A[row][col] == 0 && !visited[row][col];
}
int target(int row, int col)
{
    return row < 1 || row > n || col < 1 || col > m;
}
void finalize()
{
    for (int i = 0; i < szList; i++)
    {
        free(listNode[i]);
    }
}
void addList(Node *node)
{ // them phan tu vao listNode de thuc hien giai phong bo nho
    listNode[szList] = node;
    szList++;
}
int main()
{
    // input();
    scanf("%d%d%d%d", &n, &m, &r0, &c0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int r = 1; r <= n; r++)
        for (int c = 1; c <= m; c++)
            visited[r][c] = 0;
    initQueue();
    Node *startNode = makeNode(r0, c0, 0, NULL);
    addList(startNode);
    pushQueue(startNode);
    visited[r0][c0] = 1;
    int count = -1;
    while (!queueEmpty())
    {
        Node *node = popQueue();
        // printf("POP (%d,%d)\n", node->row, node->col);
        for (int k = 0; k < 4; k++)
        {
            int nr = node->row + dr[k];
            int nc = node->col + dc[k];
            if (legal(nr, nc))
            {
                visited[nr][nc] = 1;
                Node *newNode = makeNode(nr, nc, node->step + 1, node);
                addList(newNode);
                if (target(nr, nc))
                {
                    finalNode = newNode;
                    break;
                }
                else
                    pushQueue(newNode);
            }
        }
        if (finalNode != NULL)
            break; // found solution
    }
    Node *s = finalNode;
    while (s != NULL)
    {
        count++;
        printf("(%d,%d) ", s->row, s->col);
        s = s->parent;
    }
    printf("%d", count);
    finalize();
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAX_L 256
typedef struct Profile
{
    int number;
    char name[MAX_L];
    struct Profile *next;
} Profile;
Profile *first, *last;
Profile *makeProfile(int number, char *name)
{
    Profile *node = (Profile *)malloc(sizeof(Profile));
    node->number = number;
    strcpy(node->name, name);
    node->next = NULL;
    return node;
}
void initList()
{
    first = NULL;
    last = NULL;
}
int listEmpty()
{
    return first == NULL && last == NULL;
}
void insertLast(int number, char *name)
{
    Profile *profile = makeProfile(number, name);
    if (listEmpty())
    {
        first = profile;
        last = profile;
    }
    else
    {
        last->next = profile;
        last = profile;
    }
}
void printList()
{
    for (Profile *p = first; p != NULL; p = p->next)
        printf("%d, %s, %p\n", p->number, p->name, p);
}
Profile *removeProfile(Profile *f, int number)
{
    if (listEmpty())
        return NULL;
    if (f->number == number)
    {
        Profile *tmp = f->next;
        free(f);
        if (tmp == NULL)
            last = NULL;
        return tmp;
    }
    else
    {
        f->next = removeProfile(f->next, number);
        return f;
    }
}
void load(char *filename)
{
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        printf("Load data -> file not found\n");
    while (!feof(f))
    {
        int number;
        char name[256];
        fscanf(f, "%d%s", &number, name);
        insertLast(number, name);
    }
    fclose(f);
}
void processFind()
{
    int number;
    scanf("%d", &number);
    Profile *profile = NULL;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (p->number == number)
        {
            profile = p;
            break;
        }
    }
    if (profile == NULL)
    {
        printf("NOT FOUND profile %d\n", number);
    }
    else
    {
        printf("FOUND profile %d, %s\n", profile->number, profile->name);
    }
}
void processLoad()
{
    char filename[256];
    scanf("%s", filename);
    load(filename);
}
void processStore()
{
    char filename[256];
    scanf("%s", filename);
    FILE *f = fopen(filename, "w");
    for (Profile *p = first; p != NULL; p = p->next)
    {
        fprintf(f, "%d %s", p->number, p->name);
        if (p->next != NULL)
            fprintf(f, "\n");
    }
    fclose(f);
}
void processInsert()
{
    int number;
    char name[256];
    scanf("%d%s", &number, name);
    insertLast(number, name);
}
void processRemove()
{
    int number;
    scanf("%d", &number);
    first = removeProfile(first, number);
}
int main()
{
    initList();
    while (1)
    {
        printf("________________________________\n Nhap mot trong nhung cau lenh: \n Quit \n Load \n Print \n Find \n Insert \n Remove \n Store \n ______________________________\n nhap:");
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "Quit") == 0)
            break;
        else if (strcmp(cmd, "Load") == 0)
            processLoad();
        else if (strcmp(cmd, "Print") == 0)
            printList();
        else if (strcmp(cmd, "Find") == 0)
            processFind();
        else if (strcmp(cmd, "Insert") == 0)
            processInsert();
        else if (strcmp(cmd, "Remove") == 0)
            processRemove();
        else if (strcmp(cmd, "Store") == 0)
            processStore();
    }
}