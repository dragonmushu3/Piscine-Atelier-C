#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3 || !argv[2])
        return 1;
    else
    {
        for (int i = 0; i < *argv[2] - 48; i++)
        {
            puts(argv[1]);
        }
        return 0;
    }
}
