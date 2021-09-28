#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selsort()
{

    int n;
    printf("enter no. of elements you want to enter: ");
    scanf("%d", &n);

    int a[n];

    printf("enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

void bublsort()
{
    int n;
    printf("enter no. of elements you want to enter: ");
    scanf("%d", &n);

    int a[n];

    printf("enter elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int swap = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap++;
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }

        if (swap == 0)
        {
            break;
        }
    }
}

int main()
{
    clock_t start, end;
    long int t;
    start = clock();

    //selection sort
    selsort();
    end = clock();
    t = end - start;
    printf("Total elapsed time for selection sort : %f\n", (double)t / (double)CLOCKS_PER_SEC);

    start = clock();
    //bubble sort
    bublsort();

    end = clock();

    t = end - start;
    printf("Total elapsed time for bubble sort : %f\n", (double)t / (double)CLOCKS_PER_SEC);

    return (0);
}