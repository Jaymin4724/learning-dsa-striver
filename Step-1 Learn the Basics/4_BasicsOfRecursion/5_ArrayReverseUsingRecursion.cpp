// Reverse an Array using Recursion
// This code and logic is written by me

#include <bits/stdc++.h>
using namespace std;

// BAD LOGIC
vector<int> reverse(vector<int> arr, int left, int right)
{
    if (left < right)
    {
        swap(arr[left], arr[right]);
        return reverse(arr, left + 1, right - 1);
    }
    return arr;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    for (auto i : arr)
    {
        cout << i << " ";
    }
    vector<int> reversed_arr = reverse(arr, 0, 4);
    cout << endl;
    for (auto i : reversed_arr)
    {
        cout << i << " ";
    }
}
