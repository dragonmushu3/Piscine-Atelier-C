#include <stdio.h>
#include <stdlib.h>

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    if (!file_in || !file_out || !content)
        return 1;
    FILE *f_in = fopen(file_in, "r");
    FILE *f_out = fopen(file_out, "w");

    char *line_buffer = NULL;
    size_t not_n = 0;

    size_t i = 0;
    while (i < n)
    {
        if (getline(f_in, &line_buffer, &not_n) == -1)
        {
            fputs("\n", f_out);
            i++;
            continue;
        }
        fputs(line_buffer, f_out);
        i++;
    }
    fputs(content, f_out);

    while (getline(f_in, &line_buffer, &not_n) == -1)
    {
        fputs(line_buffer, f_out);
    }

    free(line_buffer);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
