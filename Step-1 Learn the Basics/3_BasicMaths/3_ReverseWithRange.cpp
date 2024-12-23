// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        int MIN = -2147483648;
        int MAX = 2147483647;
        while (x != 0)
        {
            int digit = x % 10;
            if (
                ((rev > MAX / 10) || (rev == MAX / 10 && digit > 7)) ||
                ((rev < MIN / 10) || (rev == MIN / 10 && digit < -8)))
            {
                return 0;
            }
            rev = (rev * 10) + digit;
            x = x / 10;
        }
        return rev;
    }
};
int main()
{
    Solution s1;
    int num;
    cin >> num;
    int rev;
    rev = s1.reverse(num);
    cout << rev;
    return 0;
}