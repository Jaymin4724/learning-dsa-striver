// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
// A substring is a contiguous sequence of characters within a string.

#include <bits/stdc++.h>
using namespace std;

// let's reduce the space complexity of the previous solution
// TC : O(n^2)
// SC : O(1)
// The number of substrings can be n*(n+1)/2 which is almost n^2
// we are not storing the substrings in the vector
// we are directly checking the odd number and updating the max_odd_value and largest_odd

string largestOddNumber(string s)
{
    string largest_odd = "";
    long long max_odd_value = -1;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        string sub = "";
        for (int j = i; j < n; j++)
        {
            sub += s[j];
            if ((sub.back() - '0') % 2 == 1)
            {
                long long num = stoll(sub);
                if (num > max_odd_value)
                {
                    max_odd_value = num;
                    largest_odd = sub;
                }
            }
        }
    }

    return largest_odd;
}

int main()
{
    cout << largestOddNumber("52") << endl;
    cout << largestOddNumber("4206") << endl;
    cout << largestOddNumber("35427") << endl;
    return 0;
}
