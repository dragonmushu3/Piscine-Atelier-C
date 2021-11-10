#include <stdio.h>

int my_isspace(char c)
{
    return c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == 32;
}

int is_character(char c)
{
    return c != EOF && !my_isspace(c);
}

int count_words(const char *file_in)
{
    if (!file_in)
        return -1;

    FILE *to_parse = fopen(file_in, "r");
    if (!to_parse)
        return -1;

    char curr_char = fgetc(to_parse);
    int res = 0;
    while (curr_char != EOF)
    {
        while (my_isspace(curr_char))
        {
            curr_char = fgetc(to_parse);
        }
        if (curr_char != EOF)
            res++;
        while (is_character(curr_char))
        {
            curr_char = fgetc(to_parse);
        }
    }
    return res;
}
