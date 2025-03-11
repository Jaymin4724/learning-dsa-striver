#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// SC: O(1)
int getLongestSubarray(vector<int> &a, int k)
{
    int n = a.size(); // size of the array.

    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i; j < n; j++)
        {
            s += a[j];
            if (s == k)
                max_len = max(max_len, j - i + 1);
        }
    }
    return max_len;
}

int main()
{
    vector<int> a = {-1, 1, 1};
    int k = 1;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
