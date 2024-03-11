#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000000
typedef struct sinh_vien
{
    char fname[11];
    char mname[11];
    char lname[11];
    char dob[20];
} SV;

SV *create_sv(char n1[], char n2[], char n3[], char dob[])
{
    SV *p = (SV *)malloc(sizeof(SV));
    strcpy(p->fname, n1);
    strcpy(p->mname, n2);
    strcpy(p->lname, n3);
    strcpy(p->dob, dob);
    return p;
}
SV *A[MAX];
SV *TA[MAX];
int n = 0;

int compare(SV *a, SV *b)
{
    if (strcmp(a->lname, b->lname) > 0)
        return 1;
    if (strcmp(a->lname, b->lname) < 0)
        return 0;
    if (strcmp(a->mname, b->mname) > 0)
        return 1;
    if (strcmp(a->mname, b->mname) < 0)
        return 0;
    if (strcmp(a->fname, b->fname) > 0)
        return 1;
    if (strcmp(a->fname, b->fname) < 0)
        return 0;
    if (strcmp(a->dob, b->dob) > 0)
        return 1;
    if (strcmp(a->dob, b->dob) < 0)
        return 0;
    return 1;
}
void merge(SV *A[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    for (int k = l; k <= r; k++)
    {
        if (i > m)
        {
            TA[k] = A[j];
            j++;
        }
        else if (j > r)
        {
            TA[k] = A[i];
            i++;
        }
        else
        {
            if (compare(A[j], A[i]))
            {
                TA[k] = A[i];
                i++;
            }
            else
            {
                TA[k] = A[j];
                j++;
            }
        }
    }
    for (int k = l; k <= r; k++)
        A[k] = TA[k];
}
void mergeSort(SV *A[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}
void load()
{
    FILE *fptr = fopen("profile-n.txt", "r");
    if (fptr == NULL)
    {
        printf("Can't open input file\n");
        return;
    }
    char fname[11];
    char mname[11];
    char lname[11];
    char dob[15];
    while (1)
    {
        fscanf(fptr, "%s %s %s\n%s\n", &fname, &mname, &lname, &dob);
        if (strcmp(fname, "#") == 0)
            break;
        A[n] = create_sv(fname, mname, lname, dob);
        n++;
    }
    fclose(fptr);
}
void pLoad()
{
    load();
    mergeSort(A, 0, n - 1);
    FILE *fptr = fopen("sorted-profile-n.txt", "w+");
    for (int i = 0; i < n; i++)
    {
        fprintf(fptr, "%s %s %s\n%s\n", A[i]->fname, A[i]->mname, A[i]->lname, A[i]->dob);
    }
    fprintf(fptr, "#");
    fclose(fptr);
}
int main()
{
    pLoad();
    return 0;
}