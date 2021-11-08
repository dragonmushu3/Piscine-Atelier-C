unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int min = arr[start];
    unsigned i = start;
    unsigned min_index = start;
    while (i < size)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
        i++; 
    }
    return min_index;
}

void selection_sort(int arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        int temp = arr[i];
        unsigned min_index = array_min(arr, i, size);
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
