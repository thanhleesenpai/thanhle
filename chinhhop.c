#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000
int n, M = 1000000007;
int x[MAX] = {0}, m[MAX] = {0};
void printSolution()
{
    for (int e = 1; e < n + 1; e++)
    {
        printf("%d ", x[e]);
    }
    printf("\n");
}
void TRY(int i)
{
    for (int v = 1; v <= n; v++)
    {
        if (!m[v])
        {
            x[i] = v;
            m[v] = 1;
            if (i == n)
                printSolution();
            else
                TRY(i + 1);
            m[v] = 0;
        }
    }
}
void main()
{
    scanf("%d", &n);
    for (int v = 1; v <= n; v++)
        m[v] = 0;
    TRY(1);
}
