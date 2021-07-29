#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

void swap(int a, int b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

void quickSort(int *arr, int begin, int end)
{
    if (begin > end)
        return;

    int key = arr[begin];
    int i = begin;
    int j = end;
    while (i != j)
    {
        while (j > key && j > i)
        {
            j--;
        }
        while (i < key && j > i)
        {
            i++;
        }
        swap(arr[i], arr[j]);
    }
    arr[begin] = arr[i];
    arr[i] = key;

    int k = 0;
    for (k = 0; k < N; i++)
    {
        printf("%d ", arr[k]);
    }
    puts("");

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
    quickSort(arr, 0, N - 1);
}

int main()
{
    test();

    return 0;
}