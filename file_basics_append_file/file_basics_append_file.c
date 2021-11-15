#include <stdio.h>
#include <stdlib.h>

int append_file(const char *file_in, const char *content)
{
    if (!file_in || !content)
        return -1;

    FILE *f_in = fopen(file_in, "w");

    if (!f_in)
        return -1;

    fprintf(f_in, "%s", content);

    fclose(f_in);
    return 0;
}
