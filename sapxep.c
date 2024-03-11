#include <stdio.h>
#include <stdlib.h>

void generateAndWriteToFile(int n, int m, int M)
{
    FILE *file;
    file = fopen("arrn.txt", "w");
    if (file == NULL)
    {
        printf("Không thể mở file arrn.txt");
        exit(1);
    }
    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++)
    {
        int randomNumber = rand() % (M - m + 1) + m;
        fprintf(file, "%d ", randomNumber);
    }
    fclose(file);
}

int main()
{
    int n, m, M;
    printf("Nhap n, m, M: ");
    scanf("%d %d %d", &n, &m, &M);
    generateAndWriteToFile(n, m, M);

    printf("Da sinh va ghi vao file arrn.txt\n");

    return 0;
}
