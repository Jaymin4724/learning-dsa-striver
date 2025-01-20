#include <bits/stdc++.h>
using namespace std;

// Function to find the upper bound of an element
// Upper bound: the first element > the given value
int UpperBound(vector<int> arr, int e)
{
    int low = 0;               // Initialize the lower bound of the search range
    int high = arr.size() - 1; // Initialize the upper bound of the search range

    // Perform binary search to find the upper bound
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Calculate the middle index safely

        if (arr[mid] > e) // If the current element is greater than the target
        {
            high = mid - 1; // Narrow the search range to the left half
        }
        else // Otherwise
        {
            low = mid + 1; // Narrow the search range to the right half
        }
    }
    return low + 1; // Return the 1-based index of the upper bound
}

int main()
{
    // Example: Find the upper bound of an element in a sorted array
    vector<int> arr = {3, 5, 8, 9, 12, 16, 18};
    sort(arr.begin(), arr.end()); // Ensure the array is sorted

    int x = 17;
    int ub = UpperBound(arr, x); // Find the upper bound for 17

    cout << "Upper bound of " << x << " is: " << ub << endl;
    return 0;
}
