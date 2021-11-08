size_t my_strlen(const char *str)
{
    size_t res = 0;
    while (*str != '\0')
    {
        str++;
        res++;
    }
    return res;
}

int my_strcmp(const char *s1, const char *s2)
{
    size_t len1 = my_strlen(s1);
    size_t len2 = my_strlen(s2);
    if (len1 < len2)
        return -1;
    else if (len1 == len2)
    {
        for (size_t i = 0; i < len1; i++)
        {
            if (s1[i] != s2[i])
                return 1;
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
