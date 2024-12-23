#include <bits/stdc++.h>
using namespace std;

// BruteForce
// TC : O(n) + O(n) = O(2n) => O(n)
// SC : O(n)
void MoveZeroesToEnd(vector<int> &arr)
{
    vector<int> nonzero;
    for (auto i : arr)
    {
        if (i != 0)
        {
            nonzero.emplace_back(i);
        }
    }
    int n = nonzero.size() - 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (n < 0)
        {
            arr[i] = 0;
        }
        else
        {
            arr[i] = nonzero[i];
            n--;
        }
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