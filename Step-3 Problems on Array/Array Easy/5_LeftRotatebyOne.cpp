#include <bits/stdc++.h>
using namespace std;

// optimal approach : O(n)  
void leftRotatebyOne(vector<int> &arr)
{
    int temp = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = temp;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << "Current Array : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    leftRotatebyOne(arr);
    cout << "Left Rotated Array by one : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
};