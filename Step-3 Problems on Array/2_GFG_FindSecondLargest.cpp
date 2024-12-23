// Input: arr[] = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.

// Input: arr[] = [10, 5, 10]
// Output: 5
// Explanation: The largest element of the array is 10 and the second largest element is 5.

// Input: arr[] = [10, 10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 and the second largest element does not exist.

#include <bits/stdc++.h>
using namespace std;

// bruteforce approach : sort an array , access the second last element (O(nlogn))
// optimal approach : (O(n))
int getSecondLargest(vector<int> &arr)
{
    if (arr.size() < 2)
        return -1; // Not enough elements for a second largest

    int largest = INT_MIN;
    int sec_largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            sec_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > sec_largest && arr[i] != largest)
        {
            sec_largest = arr[i];
        }
    }

    if (sec_largest == INT_MIN)
    {
        return -1; // No valid second largest element
    }
    else
    {
        return sec_largest;
    }
}

int main()
{
    vector<int> arr = {21, 42, 33, 94, 25, 16, 80};
    int ans = getSecondLargest(arr);
    cout << ans;
};