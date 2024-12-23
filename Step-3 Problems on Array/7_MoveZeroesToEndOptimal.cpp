#include <bits/stdc++.h>
using namespace std;

// Optimal
// TC : O(n)
// SC : O(1)
void MoveZeroesToEnd(vector<int> &arr)
{
    // 2 pointers approach
    // pointer i Determines the correct position of the nonzero element
    // pointer j will traverse and finds the next nonzero element
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != 0)
        {
            arr[i] = arr[j];
            i++;
        }
    }
    while (i < arr.size())
    {
        arr[i] = 0;
        i++;
    }
}

int main()
{
    vector<int> arr = {1, 0, 0, 0, 2, 0, 3, 4, 0, 5, 6};
    cout << "Current Array : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    MoveZeroesToEnd(arr);
    cout << "\nMoving Zeroes to End: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
};