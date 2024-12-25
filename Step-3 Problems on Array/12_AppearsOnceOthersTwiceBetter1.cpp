// Find the number that appears once, others appears twice
// Arr = [ 1, 1, 2, 3, 3, 4, 4]
// Answer ⇒ 2

#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(maxi)
int AppearsOnce(vector<int> &arr)
{
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
            return arr[i];
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
