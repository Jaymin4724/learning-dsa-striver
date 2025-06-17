#include <bits/stdc++.h>
using namespace std;

// String to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-2^31, 2^31 - 1], then round the integer to remain in the range. Specifically, integers less than -2^31 should be rounded to -2^31, and integers greater than 2^31 - 1 should be rounded to 2^31 - 1.
// Return the integer as the final result.

int myAtoi(string s)
{
    int i = 0, n = s.size(), sign = 1;
    int ans = 0;

    // Whitespace
    while (i < n && s[i] == ' ')
        i++;

    // Signedness
    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    // Conversion
    while (i < n && isdigit(s[i]))
    {
        int digit = s[i] - '0';

        // Pre-check for 32-bit overflow
        if (ans > (INT_MAX - digit) / 10)
            return sign == 1 ? INT_MAX : INT_MIN;

        ans = ans * 10 + digit;
        i++;
    }

    return ans * sign;
}
