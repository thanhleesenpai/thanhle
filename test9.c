#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include <stdbool.h>
/*int f(int n)
{
    if (n == 1)
        return 1;
    return n + f(n - 1);
}
int main()
{
    printf("%d\n", f(4));
    return 0;
}*/
/*
int f(int n)
{
    if (n <= 1)
        return 1;
    return f(n - 1) + f(n - 2);
}
int main()
{
    for (int i = 0; i <= 10; i++)
        printf("%d ", f(i));
    return 0;
}*/
/*
int C(int k, int n)
{
    if (k == 0 || k == n)
        return 1;
    return C(k, n - 1) + C(k - 1, n - 1);
}
int main()
{
    printf("%d ", C(3, 5));
    return 0;
}*/
/*
#define MAX 100
int M[MAX][MAX]; // M[k][n] store the value of
// C(k,n)
int C(int k, int n)
{
    if (k == 0 || k == n)
        M[k][n] = 1;
    else if (M[k][n] == 0)
        M[k][n] = C(k, n - 1) + C(k - 1, n - 1);
    return M[k][n];
}
int main()
{
    memset(M, 0, sizeof(M));
    printf("%d ", C(3, 5));
}*/
/*
int cnt = 0;
void move(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cnt++;
        printf("Step %d: Move a disk from %c to %c\n", cnt, A, B);
    }
    else
    {
        move(n - 1, A, C, B);
        move(1, A, B, C);
        move(n - 1, C, B, A);
    }
}
int main()
{
    move(3, 'A', 'B', 'C');
}*/
/*
int n;
int x[MAX] = {0};
void printSolution()
{
    for (int k = 0; k < n; k++)
    {
        printf("%d", x[k]);
    }
    printf("\n");
}
int TRY(int k)
{
    for (int v = 0; v <= 1; v++)
    {
        if (x[k - 1] + v < 2)
        {
            x[k] = v;
            if (k == n)
                printSolution();
            else
                TRY(k + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    TRY(1);
}*/
/*
#include <stdbool.h>
int n;
int x[MAX] = {0};
bool m[MAX];
void printSolution()
{
    for (int a = 1; a <= n; a++)
    {
        printf("%d", x[a]);
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
            m[v] = true; // đánh dấu
            if (i == n)
                printSolution();
            else
                TRY(i + 1);
            m[v] = false; // khôi phục
        }
    }
}
void main()
{
    scanf("%d", &n);
    for (int v = 1; v <= n; v++)
        m[v] = false;
    TRY(1);
}
*/
/*
int x[MAX], n;
void printSolution()
{
    for (int a = 1; a <= n; a++)
    {
        printf("%d", x[a]);
    }
    printf("\n");
}
int check(int v, int k)
{
    // kiểm tra xem v có thể gán được
    // cho x[k] không
    for (int i = 1; i <= k - 1; i++)
    {
        if (x[i] == v)
            return 0;
        if (x[i] + i == v + k)
            return 0;
        if (x[i] - i == v - k)
            return 0;
    }
    return 1;
}
void TRY(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            if (k == n)
                printSolution();
            else
                TRY(k + 1);
        }
    }
}
void main()
{
    scanf("%d", &n);
    TRY(1);
}
*/
/*
#define N 100
int n, M, T;
int x[N];
void solution()
{
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
}
int check(int v, int k)
{
    if (k == n)
        return T + v == M;
    return 1;
}
void Try(int k)
{
    for (int v = 1; v <= M - T - (n - k); v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            T += v;
            if (k == n)
                solution();
            else
                Try(k + 1);
            T -= v;
        }
    }
}
int main()
{
    n = 3;
    M = 5;
    T = 0;
    Try(1);
}
*/
int x[MAX][MAX], n;
void printSolution()
{
    for (int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n");
}
bool check(int v, int r, int c)
{
    for (int i = 0; i <= r - 1; i++)
        if (x[i][c] == v)
            return false;
    for (int j = 0; j <= c - 1; j++)
        if (x[r][j] == v)
            return false;
    int I = r / 3;
    int J = c / 3;
    int i = r - 3 * I;
    int j = c - 3 * J;
    for (int i1 = 0; i1 <= i - 1; i1++)
        for (int j1 = 0; j1 <= 2; j1++)
            if (x[3 * I + i1][3 * J + j1] == v)
                return false;
    for (int j1 = 0; j1 <= j - 1; j1++)
        if (x[3 * I + i][3 * J + j1] == v)
            return false;
    return true;
}
void TRY(int r, int c)
{
    for (int v = 1; v <= 9; v++)
    {
        if (check(v, r, c))
        {
            x[r][c] = v;
            if (r == 8 && c == 8)
            {
                printSolution();
            }
            else
            {
                if (c == 8)
                    TRY(r + 1, 0);
                else
                    TRY(r, c + 1);
            }
        }
    }
}
void main()
{
    n = 9;
    TRY(0, 0);
}