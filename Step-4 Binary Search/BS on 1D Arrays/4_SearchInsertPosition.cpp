// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4

#include <bits/stdc++.h>
using namespace std;

int SearchInsertPosition(vector<int> &arr, int e)
{
    int low = 0;               // Initialize the lower bound of the search range
    int high = arr.size() - 1; // Initialize the upper bound of the search range

    // Perform binary search to find the index
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= e) // If the current element is greater or equal to the target
        {
            high = mid - 1; // Narrow the search range to the left half
        }
        else // Otherwise
        {
            low = mid + 1; // Narrow the search range to the right half
        }
    }
    return low + 1; // Return the 1-based index of the lower bound
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 12, 16, 18};
    sort(arr.begin(), arr.end()); // Ensure the array is sorted

    int x = 17;
    int lb = SearchInsertPosition(arr, x); // Find the lower bound for 17

    cout << "Lower bound of " << x << " is: " << lb << endl;
    return 0;
}