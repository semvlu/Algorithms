int partition(int A[], int lo, int hi)
{
    int pivot = A[hi];
    int i = lo - 1;
    for (int j = lo; j < hi; ++j)
    {
        if (A[j] <= pivot)
        {
            i++;
            int temp1 = A[i];
            A[i] = A[j];
            A[j] = temp1;
        }
    }
    int temp2 = A[i+1];
    A[i+1] = A[hi];
    A[hi] = temp2;
    return (i+1);
}
void quickSort(int A[], int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(A, lo, hi);
        quickSort(A, lo, pi - 1);
        quickSort(A, pi + 1, hi);
    }
}