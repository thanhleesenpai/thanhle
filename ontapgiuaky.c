#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAX_L 256
typedef struct Profile
{
    char number[MAX_L];
    char name[MAX_L];
    struct Profile *next;
} Profile;
Profile *first, *last;
Profile *makeProfile(char *number, char *name)
{
    Profile *node = (Profile *)malloc(sizeof(Profile));
    strcpy(node->number, number);
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
void insertLast(char *number, char *name)
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
        printf("%s, %s, %p\n", p->number, p->name, p);
}
Profile *removeProfile(Profile *f, char *number)
{
    if (listEmpty())
        return NULL;
    if (strcmp(f->number, number) == 0)
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
        char number[256], name[256];
        fscanf(f, "%s%s", number, name);
        insertLast(number, name);
    }
    fclose(f);
}
void processFind()
{
    char number[256];
    scanf("%s", number);
    Profile *profile = NULL;
    for (Profile *p = first; p != NULL; p = p->next)
    {
        if (strcmp(p->number, number) == 0)
        {
            profile = p;
            break;
        }
    }
    if (profile == NULL)
    {
        printf("NOT FOUND profile %s\n", number);
    }
    else
    {
        printf("FOUND profile %s, %s\n", profile->number, profile->name);
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
        fprintf(f, "%s %s", p->number, p->name);
        if (p->next != NULL)
            fprintf(f, "\n");
    }
    fclose(f);
}
void processInsert()
{
    char number[256], name[256];
    scanf("%s%s", number, name);
    insertLast(number, name);
}
void processRemove()
{
    char number[256];
    scanf("%s", number);
    first = removeProfile(first, number);
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