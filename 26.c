#include <stdio.h>
#include <math.h>
int main()
{
    long long int a, b, c, d, e, f, g, h, i;
    scanf("%lld", &a);
    b = a / 1000000000000;
    c = a % 1000000000000;
    d = c / 1000000000;
    e = c % 1000000000;
    f = e / 1000000;
    g = e % 1000000;
    h = g / 1000;
    i = g % 1000;
    if (b > 0)
    {
        printf("%lld,%03lld,%03lld,%03lld,%03lld", b, d, f, h, i);
    }
    else
    {
        if (d > 0)
        {
            printf("%lld,%03lld,%03lld,%03lld", d, f, h, i);
        }
        else
        {
            if (f > 0)
            {
                printf("%lld,%03lld,%03lld", f, h, i);
            }
            else
            {
                if (h > 0)
                {
                    printf("%lld,%03lld", h, i);
                }
                else
                {
                    printf("%lld", i);
                }
            }
        }
    }
    return 0;
}