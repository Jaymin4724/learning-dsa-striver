// Find the number that appears once, others appears twice
// Arr = [ 1, 1, 2, 3, 3, 4, 4]
// Answer ⇒ 2

#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(1)
int AppearsOnce(vector<int> &arr)
{
    int XOR = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        XOR = XOR ^ arr[i];
    }
    return XOR;
}

int main()
{
    vector<int> a = {1, 1, 2, 3, 3, 4, 4};
    int ans = AppearsOnce(a);
    cout << ans << " Appears Once." << endl;
    return 0;
}
