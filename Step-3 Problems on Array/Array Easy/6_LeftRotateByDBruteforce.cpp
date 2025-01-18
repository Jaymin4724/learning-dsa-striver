#include <bits/stdc++.h>
using namespace std;

// Bruteforce approach : o(d) + o(n-d) + o(d) => o(2d+n-d) = o(n+d) ==> o(n)
// sc : extra space required o(d)
void leftRotatebyD(vector<int> &arr, int d)
{
    int n = arr.size();
    d = d % n;

    vector<int> temp;
    for (int i = 0; i < d; i++)
    {
        temp.emplace_back(arr[i]);
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    int j = 0;
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[j++];
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << "Current Array : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    leftRotatebyD(arr, 3);
    cout << "Left Rotated Array by 3 elements : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
};