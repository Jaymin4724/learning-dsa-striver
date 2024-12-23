#include <iostream>
#include <vector>
using namespace std;

void recursiveInsertionSort(vector<int> &arr, int n)
{
    // Base case: If the array has one or zero elements, it's already sorted
    if (n <= 1)
    {
        return;
    }

    // Sort the first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Insert the nth element into the sorted portion
    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();

    recursiveInsertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
