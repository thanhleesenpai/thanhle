#include <stdio.h>
#include <stdlib.h>

// void selectionsort(int A[], int N)
// {
//     for (int i = 1; i <= N; i++)
//     {
//         int min = i;
//         for (int j = i + 1; j <= N; j++)
//         {
//             if (A[min] > A[j])
//                 min = j;
//         }
//         int tmp = A[min];
//         A[min] = A[i];
//         A[i] = tmp;
//     }
// }

//

void bubleSort(int A[], int N)
{
    // index tu 1 den N
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 1; i < N; i++)
        {
            if (A[i] > A[i + 1])
            {
                int tmp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
}

int main()
{
    int n, *A;
    FILE *file;
    file = fopen("arrn.txt", "r");
    if (file == NULL)
    {
        printf("Không thể mở file arrn.txt");
        exit(1);
    }
    fscanf(file, "%d\n", &n);
    A = (int *)malloc(n * sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        fscanf(file, "%d ", &A[i]);
    }
    // selectionsort(A, n);
    // insertionsort(A, n);
    bubleSort(A, n);
    fclose(file);
    // file = fopen("arrn.txt", "w");
    // fprintf(file, "%d\n", n);

    // for (int i = 1; i <= n; ++i)
    // {
    //     fprintf(file, "%d ", A[i]);
    // }
    // fclose(file);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", A[i]);
    }
}
