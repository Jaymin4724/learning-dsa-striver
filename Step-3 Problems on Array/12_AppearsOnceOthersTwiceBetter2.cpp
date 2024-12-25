// Find the number that appears once, others appears twice
// Arr = [ 1, 1, 2, 3, 3, 4, 4]
// Answer ⇒ 2

#include <bits/stdc++.h>
using namespace std;

// TC : O(N*logM)
// SC : O(M)
// M means sizeof Maps
int AppearsOnce(vector<int> &arr)
{
    int n = arr.size();

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second == 1)
            return it.first;
    }

    return -1;
}

int main()
{
    vector<int> a = {1, 1, 2, 3, 3, 4, 4};
    int ans = AppearsOnce(a);
    cout << ans << " Appears Once." << endl;
    return 0;
}
