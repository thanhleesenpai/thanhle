#include <stdio.h>
#include <string.h>
int main()
{
    double c, b = 0;
    char a[11], s1[] = "096", s2[] = "097", s3[] = "098", s4[] = "086", s5[] = "032", s6[] = "033", s7[] = "034", s8[] = "035", s9[] = "036", s10[] = "037", s11[] = "038", s12[] = "039";
    char s21[] = "8496", s22[] = "8497", s23[] = "8498", s24[] = "8486", s25[] = "8432", s26[] = "8433", s27[] = "8434", s28[] = "8435", s29[] = "8436", s30[] = "8437", s31[] = "8438", s32[] = "8439";
    scanf("%s", a);
    if (strlen(a) == 10)
    {
        c = strncmp(a, s1, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s2, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s3, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s4, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s5, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s6, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s7, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s8, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s9, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s10, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s11, 3);
        if (c == 0)
            b = 1;
        c = strncmp(a, s12, 3);
        if (c == 0)
            b = 1;
    }
    if (strlen(a) == 11)
    {
        c = strncmp(a, s21, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s22, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s23, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s24, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s25, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s26, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s27, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s28, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s29, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s30, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s31, 4);
        if (c == 0)
            b = 1;
        c = strncmp(a, s32, 4);
        if (c == 0)
            b = 1;
    }
    printf("%.lf", b);
    return (0);
}
