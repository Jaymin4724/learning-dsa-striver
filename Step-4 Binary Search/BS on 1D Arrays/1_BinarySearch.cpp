#include <bits/stdc++.h>
using namespace std;

// Function to perform binary search in a sorted array
int BinarySearch(vector<int> arr, int e)
{
    int low = 0;               // Initialize the lower bound of the search range
    int high = arr.size() - 1; // Initialize the upper bound of the search range

    // Perform binary search within the range [low, high]
    while (low <= high)
    {
        // Calculate the middle index to prevent integer overflow
        int mid = low + (high - low) / 2;

        if (arr[mid] == e) // If the element at 'mid' matches the target
        {
            return mid + 1; // Return the 1-based index of the element
        }
        if (arr[mid] > e) // If the target is smaller than the middle element
        {
            high = mid - 1; // Narrow the search range to the left half
        }
        else // If the target is greater than the middle element
        {
            low = mid + 1; // Narrow the search range to the right half
        }
    }
    return -1; // Return -1 if the target element is not found
}

int main()
{
    // Example: Perform binary search on a sorted array
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 18};
    sort(arr.begin(), arr.end()); // Ensure the array is sorted before searching

    int position = BinarySearch(arr, 6); // Search for the element 6
    if (position != -1)
    {
        cout << "6 found at POSITION: " << position << endl;
    }
    else
    {
        cout << "6 not found in the array." << endl;
    }

    return 0;
}
