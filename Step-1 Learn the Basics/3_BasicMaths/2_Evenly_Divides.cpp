// Count the number of digits in NUMBER which evenly divide NUMBER.
// Return an integer, total number of digits of NUMBER which divides NUMBER evenly.
// Note :- Evenly divides means whether NUMBER is divisible by a digit i.e. leaves a remainder 0 when divided.

// Examples :
// Input: NUMBER = 12
// Output: 2
// Explanation: 1, 2 when both divide 12 leaves remainder 0.

// Input: NUMBER = 2446
// Output: 1
// Explanation: Here among 2, 4, 6 only 2 divides 2446 evenly while 4 and 6 do not.

// Input: NUMBER = 23
// Output: 0
// Explanation: 2 and 3, none of them divide 23 evenly.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1<= n <=105

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evenlyDivides(int N)
    {
        int count = 0;
        int number;
        number = N;
        while (number > 0)
        {
            int digit = number % 10; // last digit of variable=>number || examples : 7789 => 9 , 778 => 8, 77 => 7, 7 => 7
            number = number / 10;    // number 7789 / 10 => 778 / 10 => 77 / 10 => 7 / 10 => 0 (INTEGER)
            if (digit != 0 && N % digit == 0)
            {
                count++;
            }
        }
        return count;
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
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0;
}