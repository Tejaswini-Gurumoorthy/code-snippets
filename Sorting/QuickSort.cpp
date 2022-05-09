#include <bits/stdc++.h>
using namespace std;

void swapit(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int start, int end)
{
    // cout<<"I came here to partition"<<endl;
    int pivot = a[start];
    // int piv_pos=start;
    int s = start, e = end;
    while (s < e)
    {
        while (s <= pivot)
        {
            s++;
        }
        while (e > pivot)
        {
            e--;
        }
        if (s < e)
        {
            swapit(&a[s], &a[e]);
        }
    }
    swapit(&a[start], &a[e]);
    return e;
}
void quicksort(int a[], int start, int end)
{
    // cout<<"Came to quicksort"<<endl;
    if (start < end)
    {
        int loc = partition(a, start, end);
        quicksort(a, start, loc - 1);
        quicksort(a, loc + 1, end);
    }
}
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements : " << endl;
    cin >> n;
    int a[n];
    cout << "Enter elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    cout << "sorted array : " << endl;
    printarray(a, n);
}
