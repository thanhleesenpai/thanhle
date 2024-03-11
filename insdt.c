#include <stdio.h>
#include <string.h>

int main()
{
    char a[15], b[15];
    scanf("%s", a);
    if (strlen(a) == 10)
        printf("%c%c%c%c-%c%c%c-%c%c%c", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
    if (strlen(a) == 11)
        printf("%d%c%c%c-%c%c%c-%c%c%c", 0, a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], a[10]);
    printf("%d", strlen(a));
    return 0;
}