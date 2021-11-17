#include <stdio.h>

int partition(int *tab, int left, int right)
{
    int element_piv = tab[left];
    int i = left - 1;
    int j = right;

    while (1)
    {
        do
        {
            i++;
        } while (tab[i] < element_piv);

        do
        {
            j--;
        } while (tab[j] > element_piv);

        if (j <= i)
        {
            return i + (left == i);
        }
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

void quicksort_sub(int *tab, int left, int right)
{
    if (right - left > 1)
    {
        int p = partition(tab, left, right);
        quicksort_sub(tab, left, p);
        quicksort_sub(tab, p, right);
    }
}

void quicksort(int *tab, int len)
{
    if (!tab || len == 0 || len == 1)
        return;
    quicksort_sub(tab, 0, len);
}
