#include <stdio.h>
#include <math.h>
int main()
{
    int a, b = 0;
    scanf("%d", &a);
    if (a % 50000 != 0 || a <= 0)
        printf("0");
    return 0;
}
