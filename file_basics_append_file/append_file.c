#include <err.h>
#include <stdio.h>
#include <stdlib.h>

int append_file(const char *file_in, const char *content)
{
    if (!file_in || !content)
        return -1;

    FILE *f_in = fopen(file_in, "a");

    if (!f_in)
        return -1;

    if (fseek(f_in, 0, SEEK_END) == -1)
        return -1;

    fprintf(f_in, "%s", content);

    fclose(f_in);
    return 0;
}
