#include <bits/stdc++.h>
using namespace std;

//? Iterative Approach (BruteForce) --> NOT AT ALL EFFICIENT (INEFFICIENT FOR LARGE n)
//* Time Complexity: O(10^n * n) where n is the number of digits in the number
//* Space Complexity: O(n) for storing the digits of the number
//* This approach is not efficient for large values of n, as it checks every number in the range from 10^(n-1) to 10^n - 1.
//* It counts the numbers that have even digits at even indices and prime digits at odd indices.
int countGoodNumbers(long long n)
{
    long long lb = (n == 1) ? 0 : pow(10, n - 1);
    long long ub = pow(10, n) - 1;
    vector<int> prime = {2, 3, 5, 7};
    int count = 0;
    const int MOD = 1e9 + 7;

    for (long long i = lb; i <= ub; i++)
    {
        vector<int> digits;
        long long temp = i;
        // Used do while loop so that it won't skip the number 0
        do
        {
            digits.emplace_back(temp % 10);
            temp /= 10;
        } while (temp != 0);

        reverse(digits.begin(), digits.end());

        bool flag = true;
        for (int j = 0; j < digits.size(); j++)
        {
            if (j % 2 == 0)
            {
                // even index must have even digit
                if (digits[j] % 2 != 0)
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                // odd index must have prime digit
                if (find(prime.begin(), prime.end(), digits[j]) == prime.end()) // Not found → returns prime.end() , found → returns iterator to the found element
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
            count++;
    }

    return count % MOD;
}