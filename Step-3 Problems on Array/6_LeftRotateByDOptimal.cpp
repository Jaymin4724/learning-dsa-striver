#include <bits/stdc++.h>
using namespace std;

// TC : O(d) + O(n-d) + O(n) => O(2n) => O(n)
// SC : O(1)
void leftRotatebyD(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n; // Handle cases where d > n

    // Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);
    // Reverse the remaining elements
    reverse(arr.begin() + d, arr.end());
    // Reverse the entire array
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << "Current Array : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    leftRotatebyD(arr, 3);
    cout << "Left Rotated Array by 3 elements : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
};