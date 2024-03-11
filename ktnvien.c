#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c, d, e, f, g = 8;
    scanf("%d:%d %d:%d", &a, &b, &c, &d);
    e = a * 60 + b;
    f = c * 60 + d;
    if (e >= 495)
    {
        g -= 4;
    }
    if (f < 1035)
    {
        g -= 4;
    }
    if (e > 810)
    {
        g = 0;
    }
    printf("%d", g);
    return 0;
}
