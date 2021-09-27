




int int_sqrt(int n)
{
    if (n < 0)
        return -1;
    for (int i = 0; i <= n; i++)
    {
        if ((i * i) >= n )
        {
            return i;
        }
    }
    return 0;
}



