/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    enum
    {
        SUCCESS,
        FAIL,
        MAX_LEN = 10000
    };
    int num;
    int reval = SUCCESS;
    FILE *fptr2;
    char filename2[] = "fin.txt";
    char buff[MAX_LEN + 1];
    if ((fptr2 = fopen(filename2, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename2);
        reval = FAIL;
        exit(1);
    }
    num = fread(buff, sizeof(char), MAX_LEN, fptr2);
    buff[num * sizeof(char)] = '\0';
    printf("%s", buff);
    return 0;
}
*/
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

int main()
{
    enum
    {
        SUCCESS,
        FAIL,
        MAX_LEN = 10000
    };
    int num;
    int reval = SUCCESS;
    FILE *fptr1, *fptr2;

    char filename1[] = "fin.txt";

    char filename2[] = "fout.txt";
    char buff[MAX_LEN + 1];
    if ((fptr1 = fopen(filename1, "r")) == NULL)
    {
        printf("Cannot open %s.\n", filename1);
        reval = FAIL;
        exit(1);
    }
    fptr2 = fopen(filename2, "w");
    num = fread(buff, sizeof(char), MAX_LEN, fptr1);
    buff[num * sizeof(char)] = '\0';
    fwrite(buff, sizeof(char), num * sizeof(char), fptr2);
    return 0;
}
