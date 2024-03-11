#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int x[MAX], n;

int check(int x[MAX], int n)
{
    int a = 0;
    if (x[1] != 1)
    {
        return 0;
    }
    if (x[n] != 2)
    {
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            a++;
        }
        if (x[i] == 2)
        {
            a--;
        }
        if (a < 0)
        {
            return 0;
        }
        if (x[i] == 0)
        {
            return 0;
        }
    }
    if (a > 0)
    {
        return 0;
    }
    return 1;
}

void TRY(int k)
{
    if (k == n + 1)
    {
        if (check(x, n) == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d", x[i]);
            }
            printf(" ");
        }
    }
    else
    {
        if (x[k] == 0)
        {
            for (int v = 1; v <= 2; v++)
            {
                x[k] = v;
                TRY(k + 1);
            }
            x[k] = 0;
        }
        else
        {
            TRY(k + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    TRY(1);
}