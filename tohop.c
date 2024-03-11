#include <stdio.h>
#include <string.h>
#define MAX 1000
int N = 1000000007;
int M[MAX][MAX];
int C(int k, int n)
{
    if (k == 0 || k == n)
        M[k][n] = 1;
    else if (M[k][n] == 0)
        M[k][n] = (C(k, n - 1) + C(k - 1, n - 1)) % N;
    return M[k][n];
}
int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    memset(M, 0, sizeof(M));
    printf("%d ", C(k, n));
}
