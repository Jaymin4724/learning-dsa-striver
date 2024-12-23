#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool swapping = false;
        for (int j = 0; j < size - i - 1; i++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapping = true;
            }
        }
        if (!swapping)
            break;
    }
}

int main()
{
    vector<int> arr = {33, 7, 25, 18, 19, 24, 23, 98, 45};
    bubble_sort(arr, arr.size());
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}