#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
int happynumber(int a)
{
    int i = 0, number;
    int b[MAX] = {0};
    if (a < 10)
    {
        if (a == 1 || a == 7)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (a >= 10)
    {
        while (a >= 10)
        {
            b[i] = a % 10;
            a = a / 10;
            i++;
        }
        b[i] = a;
        for (int j = 0; j < i; j++)
        {
            number = b[j] * b[j];
        }
        happynumber(number);
    }
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", happynumber(a));
    return 0;
}