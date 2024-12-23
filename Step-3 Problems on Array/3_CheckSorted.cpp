#include <bits/stdc++.h>
using namespace std;

// bruteforce approach : Use two for loops(O(n^2))
// optimal/linear approach : (O(n))
bool isSorted(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> arr = {21, 42, 33, 94, 25, 16, 80};
    // sort(arr.begin(), arr.end());
    int ans = isSorted(arr);
    cout << ans;
};