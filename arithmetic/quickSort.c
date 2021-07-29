#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//快速排序
void quickSort(int *arr, int begin, int end)
{
    if (begin > end)
        return;

    int key = arr[begin];
    int i = begin;
    int j = end;
    while (i != j)
    {
        while (arr[j] >= key && j > i)
        {
            j--;
        }
        while (arr[i] <= key && j > i)
        {
            i++;
        }

        swap(&arr[i], &arr[j]);
        // int k = 0;
        // for (k = 0; k < N; k++)
        // {
        //     printf("%d ", arr[k]);
        // }
        // puts("");
    }
    arr[begin] = arr[i];
    arr[i] = key;

    // int k = 0;
    // for (k = 0; k < N; k++)
    // {
    //     printf("%d ", arr[k]);
    // }
    // puts("\n----------------------------");

    quickSort(arr, begin, i - 1);
    quickSort(arr, i + 1, end);
}

void test()
{
    int arr[N] = {0};
    srand(time(NULL));
    int i = 0;
    for (i = 0; i < N; i++)
    {
        arr[i] = rand() % 10;
    }
    puts("-----------before sort------------");

    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("\n-------------------------------");
    quickSort(arr, 0, N - 1);
    puts("-----------after sort------------");

    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("\n-------------------------------");
}

int main()
{
    test();

    return 0;
}