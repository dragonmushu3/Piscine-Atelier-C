#include "insert_line.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
        return 1;
    return insert_line(argv[1], argv[2], argv[3], atoi(argv[4]));
}
