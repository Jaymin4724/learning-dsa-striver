// Better code , CHATGPT
// there is a better way to reverse an array using recursion that avoids repeatedly creating new vectors in each recursive call. Instead of returning a new vector in every call, you can modify the original vector in-place. Here's an improved version of your code:

#include <bits/stdc++.h>
using namespace std;

// Function to reverse the array in place
void reverse(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    // Swap elements at 'left' and 'right' indices
    swap(arr[left], arr[right]);

    // Recursive call
    reverse(arr, left + 1, right - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    // Print the original array
    cout << "Original array: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    // Reverse the array
    reverse(arr, 0, arr.size() - 1);

    // Print the reversed array
    cout << "Reversed array: ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
