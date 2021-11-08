int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet || *alphabet == '\0')
        return 1;

    if (*str == '\0')
        return 0;

    const char *ptr = str;
    while (*alphabet != '\0')
    {
        int not_in = 1;
        while (*ptr != '\0')
        {
            if (*ptr == *alphabet)
                not_in = 0;
            ptr++;
        }
        if (not_in)
            return 0;
        alphabet++;
        ptr = str;
    }
    return 1;
}
