#include <stdio.h>
#include <stdlib.h>

size_t count_line_feed(const char *content)
{
    size_t nb_lines = 0;
    while (content && *content != '\0')
    {
        if (*content == '\n')
            nb_lines++;
        content++;
    }
    return nb_lines;
}

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    if (!file_in || !file_out || !content)
        return -1;

    FILE *f_in = fopen(file_in, "r");
    FILE *f_out = fopen(file_out, "w");

    if (!f_in || !f_out)
        return -1;

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
        i += count_line_feed(line_buffer);
    }

    fputs(content, f_out);

    while (getline(&line_buffer, &not_n, f_in) != -1)
    {
        fputs(line_buffer, f_out);
        i += count_line_feed(line_buffer);
    }

    size_t nb_lines = count_line_feed(content);
    if (nb_line == 0)
        nb_line++;

    free(line_buffer);
    fclose(f_in);
    fclose(f_out);
    return i + nb_lines;
}
