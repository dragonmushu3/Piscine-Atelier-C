#include <stdlib.h>
#include <string.h>

int my_strlen(const char *s)
{
    int res = 0;
    while (*s != '\0')
    {
        res++;
        s++;
    }
    return res;
}

char *rle_encode(const char *s)
{
    if (!s)
        return NULL;
    if (my_strlen(s) == 0)
    {
        char *encoded = malloc(1);
        *encoded = '\0'; 
        return encoded;
    }

    char *encoded = malloc(sizeof(char) * 2 * strlen(s) + 1);
    if (!encoded)
        return NULL;
    size_t i = 0;
    char ref = s[0];
    int curr_count = 0;
    int encoded_index = 0;

    while (s[i] != '\0')
    {
        if (s[i] != ref || curr_count == 9)
        {
            /*write in encoded*/
            encoded[encoded_index] = curr_count + 48;
            encoded_index++;
            encoded[encoded_index] = ref;
            encoded_index++;
            /*reset count and ref */
            ref = s[i];
            curr_count = 1;
        }
        else
        {
            curr_count++;
        }
        i++;
    }

    if (curr_count > 0)
    {
        encoded[encoded_index] = curr_count + 48;
        encoded_index++;
        encoded[encoded_index] = ref;
    }

    encoded = realloc(encoded, encoded_index + 2);
    if (!encoded)
        return NULL;
    encoded[encoded_index + 1] = '\0';

    return encoded;
}

char *rle_decode(const char *s)
{
    if (!s)
        return NULL;
    if(my_strlen(s) == 0)
    {
        char *decoded = malloc(1);
        *decoded = '\0'; 
        return decoded;
    }

    int i = 0;
    int j = 0;
    char ref = s[1];
    int no_char = 0;
    char *decoded = NULL;

    while (s[i] != '\0')
    {
        no_char += s[i] - 48;
        decoded = realloc(decoded, no_char);
        ref = s[i + 1];
        while (j < no_char)
        {
            decoded[j] = ref;
            j++;
        }
        i += 2;
    }

    decoded = realloc(decoded, no_char + 1);
    decoded[no_char] = '\0';

    return decoded;
}
