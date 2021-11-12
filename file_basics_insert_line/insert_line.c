#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char *str)
{
    size_t len;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

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
        if (getline(&line_buffer, &not_n, f_in) == -1)
        {
            fputs("\n", f_out);
            i++;
            continue;
        }
        fputs(line_buffer, f_out);
        i++;
    }

    fputs(content, f_out);
    if (*(content + my_strlen(content) - 1) == '\n')
        i++;

    while (getline(&line_buffer, &not_n, f_in) != -1)
    {
        fputs(line_buffer, f_out);
        i++;
    }

    free(line_buffer);
    fclose(f_in);
    fclose(f_out);
    return i;
}
