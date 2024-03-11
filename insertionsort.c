#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

// void bubleSort(int A[], int N)
// {
//     // index tu 1 den N
//     int swapped;
//     do
//     {
//         swapped = 0;
//         for (int i = 1; i < N; i++)
//         {
//             if (A[i] > A[i + 1])
//             {
//                 int tmp = A[i];
//                 A[i] = A[i + 1];
//                 A[i + 1] = tmp;
//                 swapped = 1;
//             }
//         }
//     } while (swapped == 1);
// }

void insertionsort(int A[], int N)
{
    // index tu 1 -> N
    for (int k = 2; k <= N; k++)
    {
        int last = A[k];
        int j = k;
        while (j > 1 && A[j - 1] >
                            last)
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = last;
    }
}

int main()
{
    time_t startTime = time(NULL);
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
    insertionsort(A, n);
    // bubleSort(A, n);
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
    time_t endTime = time(NULL);
    printf("\nThoi gian bat dau: %s", ctime(&startTime));
    printf("\nThoi gian ket thuc: %s", ctime(&endTime));
}