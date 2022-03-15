void selectionSort(int A[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < size; ++j)
        {
            if(A[j] < A[min])
                min = j;
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    int max = A[size-1];
    int _2nd = A[size-2];
    int _3rd = A[size-3];
}
