#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c, d;
    scanf("%d", &a);
    b = a / 100;
    c = (a % 100) / 10;
    d = a - 100 * b - 10 * c;
    if (b == 0)
        printf("");
    else if (b == 1)
        printf("mot tram ");
    else if (b == 2)
        printf("hai tram ");
    else if (b == 3)
        printf("ba tram ");
    else if (b == 4)
        printf("bon tram ");
    else if (b == 5)
        printf("nam tram ");
    else if (b == 6)
        printf("sau tram ");
    else if (b == 7)
        printf("bay tram ");
    else if (b == 8)
        printf("tam tram ");
    else if (b == 9)
        printf("chin tram ");
    else
        printf("ERROR");
    if (c == 0 && b == 0)
        printf("");
    else if (c == 0 && d != 0 && b != 0)
        printf("le ");
    else if (c == 1)
        printf("muoi ");
    else if (c == 2)
        printf("hai muoi ");
    else if (c == 3)
        printf("ba muoi ");
    else if (c == 4)
        printf("bon muoi ");
    else if (c == 5)
        printf("nam muoi ");
    else if (c == 6)
        printf("sau muoi ");
    else if (c == 7)
        printf("bay muoi ");
    else if (c == 8)
        printf("tam muoi ");
    else if (c == 9)
        printf("chin muoi ");
    else
        printf("ERROR");
    if (d == 0)
        printf("");
    else if (d == 1)
        printf("mot");
    else if (d == 2)
        printf("hai");
    else if (d == 3)
        printf("ba");
    else if (d == 4)
        printf("bon");
    else if (d == 5)
        printf("nam");
    else if (d == 6)
        printf("sau");
    else if (d == 7)
        printf("bay");
    else if (d == 8)
        printf("tam");
    else if (d == 9)
        printf("chin");
    else
        printf("ERROR");
    return 0;
}