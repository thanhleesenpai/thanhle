#include <stdio.h>
int main()
{
    long a, tocdo[100], tocdomax = 0;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &tocdo[i]);
        if (tocdomax < tocdo[i])
        {
            tocdomax = tocdo[i];
        }
    }
    if (tocdomax < 119)
    {
        printf("0");
    }
    if (tocdomax >= 119 && tocdomax <= 153)
    {
        printf("1");
    }
    if (tocdomax >= 154 && tocdomax <= 177)
    {
        printf("2");
    }
    if (tocdomax >= 178 && tocdomax <= 209)
    {
        printf("3");
    }
    if (tocdomax >= 210 && tocdomax <= 249)
    {
        printf("4");
    }
    if (tocdomax >= 250)
    {
        printf("5");
    }
}