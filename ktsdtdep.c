#include <stdio.h>
#include <string.h>

int main()
{
    /*int b = 0;
    char a[15], s1[] = "111", s2[] = "222", s3[] = "333", s4[] = "444", s5[] = "555", s6[] = "666", s7[] = "777", s8[] = "888", s9[] = "999", s10[] = "321", s11[] = "432", s12[] = "543", s13[] = "654", s14[] = "765", s15[] = "876", s16[] = "987";
    scanf("%s", a);
    strrev(a);
    if (strncmp(a, s1, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s2, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s3, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s4, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s5, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s6, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s7, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s8, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s9, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s10, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s11, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s12, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s13, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s14, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s15, 3) == 0)
    {
        b = 1;
    }
    if (strncmp(a, s16, 3) == 0)
    {
        b = 1;
    }
    /*printf("%s\n", a);*/

    char a[12];
    int x, y, z;

    scanf("%s", a);

    x = strlen(a) - 3;
    y = strlen(a) - 2;
    z = strlen(a) - 1;

    if ((a[x] == a[y] && a[y] == a[z]) || (a[x] == a[y] - 1 && a[y] == a[z] - 1))
        printf("1");
    else
        printf("0");
    return 0;
}
