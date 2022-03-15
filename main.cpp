void bubbleSort(int A[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if(A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

    }
}