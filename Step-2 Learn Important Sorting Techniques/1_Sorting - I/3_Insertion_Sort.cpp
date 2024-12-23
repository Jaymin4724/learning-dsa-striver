#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> arr = {33, 7, 25, 18, 19, 24, 23, 98, 45};
    insertion_sort(arr, arr.size());
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}