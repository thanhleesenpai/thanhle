#include <stdio.h>
#include <string.h>
int main()
{
    char a[20];
    scanf("%s", a);
    int n = strlen(a), check = 1;
    for (int i = 0; i <= n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
        {
            printf("0");
            check = 0;
            break;
        }
    }
    if (check)
        printf("1");

    return 0;
}
