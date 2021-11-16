#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "heap_sort.h"

void Test_1(void)
{
    srand(time(NULL));
    int correct = 1;

    int passed_tests = 0;
    while (correct)
    {
        int size = rand();
        if (size > 100)
            size = 100;
        int *arr = malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand();
        }
        heap_sort(arr, size);

        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                correct = 0;
                break;
            }
        }

        if (!correct)
        {
            printf("Found bad sort. Check bad_sort file.\n");
            FILE *out = fopen("bad_sort", "w+");
            for (int i = 0; i < size; i++)
            {
                fprintf(out, "%d ", arr[i]);
            }
            fprintf(out, "\n Test %d failed.\n", passed_tests + 1);
            free(arr);
            fclose(out);
        }
        else
        {
            // printf("#############################################\n");
            // for (int i = 0; i < size; i++)
            //{
            //    printf("%d ", arr[i]);
            //}
            // printf("\n\n");
            passed_tests++;
            // printf("Passed %d tests.\n\n", passed_tests);
            // printf("#############################################\n");
            free(arr);
        }
    }
}

void Test_2(void)
{
    int arr[1] = { 5 };
    heapify(arr, 1);
    for (int i = 0; i < 1; i++)
    {
        printf("%d ", arr[i]);
    }
    heap_sort(arr, 1);
    puts("");
    for (int i = 0; i < 1; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    // Test_1();
    Test_2();
    return 0;
}
