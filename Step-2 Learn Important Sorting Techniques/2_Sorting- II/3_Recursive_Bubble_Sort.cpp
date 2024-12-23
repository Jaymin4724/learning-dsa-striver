#include <iostream>
#include <vector>
using namespace std;

void recursiveBubbleSort(vector<int> &arr, int n)
{
    // Base case: If the array has one or zero elements, it's already sorted
    if (n <= 1)
    {
        return;
    }

    // Perform one pass of bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            // Swap the elements
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursively call the bubble sort on the smaller array
    recursiveBubbleSort(arr, n - 1);
}

int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    recursiveBubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
