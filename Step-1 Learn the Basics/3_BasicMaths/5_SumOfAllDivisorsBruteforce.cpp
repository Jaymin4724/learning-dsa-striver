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
    long long Sum(long long N)
    {
        long long sum = 0;
        for (auto i = 1; i <= sqrt(N); i++)
        {
            if (N % i == 0)
            {
                sum += i;
                if (N / i != i)
                {
                    sum += (N / i);
                }
            }
        }
        return sum;
    }

    long long sumOfDivisors(long long N)
    {
        vector<long long> vec;
        long long temp = N;

        for (auto i = 1; i <= N; i++)
        {
            auto temp = Sum(i);
            vec.emplace_back(temp);
        }

        long long final = 0;
        for (auto j : vec)
        {
            final += j;
        }
        return final;
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