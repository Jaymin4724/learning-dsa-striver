#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(1)
int missingNumber(vector<int> &a, int N)
{
    int sumOfN = (N * (N + 1)) / 2;
    int sum = 0;
    for (auto i : a)
    {
        sum += i;
    }
    return (sumOfN - sum);
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
