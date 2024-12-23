// Given a positive integer N., The task is to find the value of Σi from 1 to N F(i) where function F(i) for the number i is defined as the sum of all divisors of i.

// Example 1:

// Input:
// N = 4
// Output:
// 15
// Explanation:
// F(1) = 1
// F(2) = 1 + 2 = 3
// F(3) = 1 + 3 = 4
// F(4) = 1 + 2 + 4 = 7
// ans = F(1) + F(2) + F(3) + F(4)
//     = 1 + 3 + 4 + 7
//     = 15
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumOfDivisors(long long N)
    {
        vector<long long> sum(N + 1, 0);
        for (long long i = 1; i <= N; ++i)
        {
            // The inner loop starts from j=i and increments j by i (i.e., it goes through all multiples of i)
            // For each multiple j, it adds i to sum[j] this means that every time j is found to be a multiple of i is a divisor of j so it contributes to the sum of divisors of j.
            for (long long j = i; j <= N; j += i)
            {
                sum[j] += i;
                //      For N = 6:
                //      When i = 1: sum[1], sum[2], sum[3], sum[4], sum[5], sum[6] will all have 1 added to them.
                //      When i = 2: sum[2], sum[4], sum[6] will have 2 added to them.
                //      When i = 3: sum[3], sum[6] will have 3 added to them.
                //      When i = 4: sum[4] will have 4 added to it.
                //      When i = 5: sum[5] will have 5 added to it.
                //      When i = 6: sum[6] will have 6 added to it.
            }
        }
        long long totalSum = 0;
        for (long long i = 1; i <= N; ++i)
        {
            // After completing this process, the `sum` vector will contain the total sum of divisors for each number up to N
            totalSum += sum[i];
        }

        return totalSum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        long long ans = ob.sumOfDivisors(N);
        cout << ans << endl;
    }
    return 0;
}
