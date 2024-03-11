#include <stdio.h>

void docso(int so)
{
    char donvi[100] = {"", "thap", "nhi thap", "tam thap", "tu thap", "ngu thap", "luc thap", "that thap", "bat thap", "cuu thap"};
    char chuc[100] = {"", "nhat", "nhi", "tam", "tu", "ngu", "that", "luc", "bat", "cuu"};
    if (so >= 0)
    {
        int hangchuc = so / 10;
        int hangdonvi = so % 10;
        if (hangchuc == 0)
        {
            printf("%s", donvi[hangdonvi]);
        }
        else
        {
            printf("%s %s", chuc[hangchuc], donvi[hangdonvi]);
        }
    }
}

int main()
{
    int so;
    scanf("%d", &so);
    docso(so);

    return 0;
}
