#include <stdio.h>
#include <math.h>
#include <string.h>
void dbc(int tuoi, long buocchan)
{
    if (tuoi < 60)
    {
        if (buocchan >= 10000)
        {
            printf("0");
        }
        else
        {
            long thieu;
            thieu = 10000 - buocchan;
            printf("%ld", thieu);
        }
    }
    else
    {
        if (buocchan >= 8000)
        {
            printf("0");
        }
        else
        {
            long thieu;
            thieu = 8000 - buocchan;
            printf("%ld", thieu);
        }
    }
}
int main()
{
    int tuoi;
    long buoc[100], buocchan = 0;
    scanf("%d", &tuoi);
    for (int i = 0;; i++)
    {
        scanf("%ld", &buoc[i]);
        if (buoc[i] == -1)
        {
            break;
        }
        buocchan = buocchan + buoc[i];
    }
    dbc(tuoi, buocchan);
    return 0;
}