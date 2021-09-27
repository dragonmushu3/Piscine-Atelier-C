#include <stddef.h>





int top_of_the_hill(int tab[], size_t len)
{
    size_t i = 1;
    int res = 0;
    while(i < len && tab[i] >= tab[i-1])
    {
        if (tab[i] > tab[i-1])
            res = i;
        i++;
    }
    while (i < len && tab[i] <= tab[i-1])
    {
        i++;
    }
    size_t billy = i - 1;
    size_t bob = len - 1;
    if (!(bob == billy))
        return -1;
    if (res == 0)
        return -1;
    return res;
}







/*
**int main(void)
**{
**    int arr1[] = {0, 2, 3, 2, 4, 5, 4, 3, 7, 1};
**    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 7, 2, 1, 0, 0};
**    int arr3[] = {0,0,0,0,0};
**    printf("%d\n",top_of_the_hill(arr1,10));
**    printf("%d\n",top_of_the_hill(arr2,12));
**    printf("%d\n",top_of_the_hill(arr3,5));
**    return 0;
**}
*/
