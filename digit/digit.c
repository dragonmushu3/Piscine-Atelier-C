#include <stdio.h>
#include <stddef.h>





unsigned int digit(int n, int k)
{
    unsigned int res = 1;
    for (int i = 1; i <= k; i++)
        res *= 10;
    printf("%u\n",res);
    unsigned int billi_bob = n % res;
    unsigned int baby = n % (res / 10);
    unsigned int damn = billi_bob - baby;
    return (damn / res);
}




int main(void)
{
    printf("%u\n",digit(568,1));
    return 0;
}
