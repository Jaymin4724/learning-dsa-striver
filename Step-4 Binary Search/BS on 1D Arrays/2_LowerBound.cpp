#include <bits/stdc++.h>
using namespace std;

// Function to find the lower bound of an element
// Lower bound: the first element >= the given value
int LowerBound(vector<int> arr, int e)
{
    int low = 0;               // Initialize the lower bound of the search range
    int high = arr.size() - 1; // Initialize the upper bound of the search range

    // Perform binary search to find the lower bound
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate the middle index safely

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
    // Example: Find the lower bound of an element in a sorted array
    vector<int> arr = {3, 5, 8, 9, 12, 16, 18};
    sort(arr.begin(), arr.end()); // Ensure the array is sorted

    int x = 17;
    int lb = LowerBound(arr, x); // Find the lower bound for 17

    cout << "Lower bound of " << x << " is: " << lb << endl;
    return 0;
}
