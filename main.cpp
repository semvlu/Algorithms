void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = A[p+i];
    for (int i = 0; i < n2; ++i)
        M[i] = A[q+1-i];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if(L[i] <= M[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = M[j];
            j++;
        }
        k++;
    }
    while (j < n2)
    {
        A[k] = M[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}