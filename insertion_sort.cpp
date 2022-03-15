void insertionSort(int A[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = A[i];
        int j = i - 1;
        while(key < A[j] && j >= 0)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    int max = A[size-1];
    int _2nd = A[size-2];
    int _3rd = A[size-3];
}
