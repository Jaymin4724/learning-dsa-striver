#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(1)
int MaxConsecutiveOnes(vector<int> &a)
{
    int maxi = 0;
    int count = 0;
    for (auto i : a)
    {
        if (i == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxi;
}

int main()
{
    vector<int> a = {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};
    int ans = MaxConsecutiveOnes(a);
    cout << "Max Consecutive Ones : " << ans << endl;
    return 0;
}
