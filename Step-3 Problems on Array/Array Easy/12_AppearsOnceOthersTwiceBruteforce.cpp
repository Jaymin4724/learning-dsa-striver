// Find the number that appears once, others appears twice
// Arr = [ 1, 1, 2, 3, 3, 4, 4]
// Answer ⇒ 2

#include <bits/stdc++.h>
using namespace std;

// TC : O(n^2)
// SC : O(1)
int AppearsOnce(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int cnt = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] == num)
                cnt++;
        }

        if (cnt == 1)
            return num;
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
