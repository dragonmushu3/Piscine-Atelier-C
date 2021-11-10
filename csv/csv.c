#define _DEFAULT_SOURCE
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
        exit(1);

    FILE *csv = fopen(argv[1], "r");
    if (!csv)
        err(1, "%s", argv[1]);

    size_t n = 0;

    char *line_ptr = NULL;
    char *token = NULL;
    while (getline(&line_ptr, &n, csv) != -1)
    {
        char *saveptr;
        token = strtok_r(line_ptr, ",", &saveptr);
        if (!token)
        {
            printf("%d", 0);
            continue;
        }

        int max = atoi(token);
        while (token)
        {
            int token_value = atoi(token);
            if (token_value > max)
                max = token_value;
            token = strtok_r(NULL, ",", &saveptr);
        }
        printf("%d\n", max);
    }

    free(token);
    free(line_ptr);
    fclose(csv);
    return 0;
}
