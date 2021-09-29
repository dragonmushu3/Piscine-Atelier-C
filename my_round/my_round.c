int my_round(float n)
{
    int lower_int = n;
    if (n >= 0)
    {
        float diff = n - lower_int;

        if (diff < 0.5)
        {
            return lower_int;
        }
        else if (diff == 0.5)
        {
            if ((lower_int % 2) == 0)
                return lower_int;
            else
                return lower_int + 1;
        }
        else
            return lower_int + 1;
    }
    else
    {
        float diff = -n + lower_int;
        if (diff < 0.5)
        {
            return lower_int;
        }
        else if (diff == 0.5)
        {
            if ((lower_int % 2) == 0)
                return lower_int;
            else
                return lower_int - 1;
        }
        else
            return lower_int - 1;
    }
}
