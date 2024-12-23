#include <bits/stdc++.h>
using namespace std;
// my logic --> (problem) multiple times swapping !!
// void selection_sort(vector<int> &arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 swap(arr[i], arr[j]);
//             }
//         }
//     }
// }

// solution to my problem --> only one time swapping !!
// Efficient Code ✅
void selection_sort(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i; // min index
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    vector<int> arr = {33, 7, 25, 18, 19, 24, 23, 98, 45};
    selection_sort(arr, arr.size());
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}