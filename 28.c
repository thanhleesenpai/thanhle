#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char a[20];
    int x = 0;
    scanf("%s", &a);
    for (x = 1; x < strlen(a); x++)
    {
        if (a[x] == a[x - 1] + 1)
        {
            printf("%c", a[x - 1]);
        }

        {
            if (a[x - 1] != a[x] - 1 && a[x - 1] = a[x - 2] + 1)
            {
                printf("%c", a[x]);

                break;
            }
        }
    }
    return 0;
}
