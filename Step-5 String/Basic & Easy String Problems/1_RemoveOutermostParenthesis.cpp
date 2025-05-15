// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: o(1)
string removeOuterParentheses(string s)
{
    //? the main logic is to keep track of count of open and close parenthesis
    //? if count is 0 then it is outermost parenthesis
    //? if count is > 0 then it is inner parenthesis so that we will add it to result

    string result;
    int count = 0;
    for (auto i : s)
    {
        if (i == '(')
        {
            // outermost starting parenthesis will have count = 0 always so we will skip that
            if (count > 0)
                result += i;
            // here count is incremented because we are opening the parenthesis whether it is outermost or innermost
            count++;
        }
        else
        {
            // here count is decremented because we are closing the parenthesis whether it is outermost or innermost
            count--;
            // outermost ending parenthesis will have count = 0 always so we will skip that
            if (count > 0)
                result += i;
        }
        // we are checking condition before count++ and after count-- so that we can skip the outermost parenthesis
        //* we are checking the condition before count++ so that we can skip the outermost starting parenthesis
        //* and we are checking the condition after count-- so that we can skip the outermost ending parenthesis
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << removeOuterParentheses(s) << endl;
    return 0;
}
