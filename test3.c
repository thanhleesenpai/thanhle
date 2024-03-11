#include <stdio.h>
enum
{
    SUCCESS,
    FAIL
};
/*
void CharReadWrite(FILE *fin, FILE *fout)
{
    int c, n = 2;
    while ((c = fgetc(fin)) != EOF)
    {
        fputc(c, fout);
        putchar(c);
        if (c == '\n')
        {
            printf("%d", n);
            n++;
        }
    }
}

int main(void)
{
    FILE *fptr1, *fptr2;
    char filename1[] = "file1.txt";
    char filename2[] = "file2.txt";
    int reval = SUCCESS;
    if ((fptr1 = fopen(filename1, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
    }
    else if ((fptr2 = fopen(filename2, "w")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
    }
    else
    {
        CharReadWrite(fptr1, fptr2);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;

}
*/
typedef struct
{
    int no;
    char name[20];
    double price;
} product;

int main(void)
{
    FILE *fptr1, *fptr2;
    char filename1[] = "file1.txt";
    char filename2[] = "file2.txt";
    product arr[MAX];
    fptr1 = fopen(filename1, "r");
    fptr2 = fopen(filename2, "r");
    while (fscanf(fp, "%d%s%lf", &arr[i].no, &arr[i].name, &arr[i].price) != EOF)
    {
        printf("%d\t%s\t%.2lf\n", arr[i].no, arr[i].name, arr[i].price);
        i++;
    }
