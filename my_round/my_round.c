#include <stdio.h>
//tried to emulate "round 1/2 to nearest even number" for .5 cases
int my_round(float n)
{
    int lower_int = n;
    if (n >= 0)
    {
        float diff = n - lower_int;

        if (diff < 0.5)
        {
            return lower_int;
        }
        else if (diff == 0.5)
        {
            if ((lower_int % 2) == 0)
                return lower_int;
            else
                return lower_int + 1;
        }
        else
            return lower_int + 1;
    }
    else
    {
        float diff = -n + lower_int;
        if (diff < 0.5)
        {
            return lower_int;
        }
        else if (diff == 0.5)
        {
            if ((lower_int % 2) == 0)
                return lower_int;
            else
                return lower_int - 1;
        }
        else
            return lower_int - 1;
    }
}






/*
**int main(void)
**{
**    printf("%d\n",my_round(104.5));
**    return 0;
**}
*/
