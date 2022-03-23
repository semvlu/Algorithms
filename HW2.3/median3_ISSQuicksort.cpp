#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sys/time.h>
using namespace std;
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int A[], int p, int r)
{
    int size = r - p + 1;
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
}

int hoareParti(int a[], int p, int r)
{
    int x = a[p];
    int i = p - 1;
    int j = r + 1;
    while (true)
    {
        while(a[j] > x)
            j -= 1;
        while(a[i] < x)
            i += 1;

        if (i < j)
            swap(a[i], a[j]);
        else
            return j;
    }
}

int parti(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r - 1; ++j)
    {
        if (a[j] <= x)
        {
            i += 1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return (i + 1);
}

int median3Parti(int a[], int p, int r)
{
    if (r - p + 1 >= 3)
    {
        int q = (p + r) / 2;
        if (a[p] > a[q])
            swap(a[p], a[q]);
        if(a[p] > a[r])
            swap(a[p], a[r]);
        if(a[q] > a[r])
            swap(a[q], a[r]);
        swap(a[q], a[r]);
    }
    return parti(a, p, r);
}

void median3Quick(int a[], int p, int r)
{
    if (p < r)
    {
        int q = median3Parti(a, p, q - 1);
        median3Quick(a, p, q - 1);
        median3Quick(a, q + 1, r);
    }
}

void issQuickSort(int a[], int p, int r, int m)
{
    if (r - p + 1 >= m)
    {
        int q = median3Parti(a, p, r);
        issQuickSort(a, p, q - 1, m);
        issQuickSort(a, q + 1, r, m);
    }
    else if (p < r)
        insertionSort(a, p, r);
}

int main()
{
    for (int i = 5; i <= 100; ++i) // Trials of array size 5 ~ 100
    {
        int* a = new int[i];
        srand(time(NULL));
        for (int j = 0; j < i; ++j)
            a[j] = rand() % 10000;

        /*cout << "Original: ";
        for (int i = 0; i < SIZE; ++i)
            cout << a[i] << " ";
        cout << endl;*/

        struct timeval start, end;
        // start timer.
        gettimeofday(&start, NULL);
        ios_base::sync_with_stdio(false);

        issQuickSort(a, 0, i - 1, i + 1); 
        // if m = i, the whole array will not be sorted properly

        // stop timer.
        gettimeofday(&end, NULL);

        /*for (int i = 0; i < SIZE; ++i)
            cout << a[i] << " ";
        cout << endl;*/

        // Calculating total time
        double time_taken;
        time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
        cout << fixed << time_taken << setprecision(6) << " ";
    }
}
