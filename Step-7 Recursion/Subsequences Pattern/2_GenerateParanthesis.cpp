#include <bits/stdc++.h>
using namespace std;

void helper(string s, int open, int close, vector<string> &answer)
{
    // Base Case
    if (open == 0 && close == 0)
    {
        answer.emplace_back(s);
        return;
    }
    if (close < open)
        return;

    // Try adding '(' if available
    if (open > 0)
        helper(s + "(", open - 1, close, answer);

    // Try adding ')' if available
    if (close > 0)
        helper(s + ")", open, close - 1, answer);
}

// TC : O(Cn)
// SC : O(n)
vector<string> generateParenthesis(int n)
{
    vector<string> answer;
    helper("", n, n, answer);
    return answer;
} 