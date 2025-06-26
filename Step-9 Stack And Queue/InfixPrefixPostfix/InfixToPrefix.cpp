#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N)
string infixToPrefix(string &s)
{
    string ans = "";
    unordered_map<char, int> priority = {
        {'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    stack<char> st;

    // Step 1: Reverse the string
    reverse(s.begin(), s.end());

    // Step 2: Swap brackets
    for (char &ch : s)
    {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    // Step 3: Infix to Postfix
    for (char i : s)
    {
        if (isalnum(i)) // operand
            ans += i;
        else if (i == '(')
            st.push(i);
        else if (i == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // pop '('
        }
        else // operator
        {
            while (!st.empty() && st.top() != '(' &&
                   priority[st.top()] >= priority[i])
            {
                ans += st.top();
                st.pop();
            }
            st.push(i);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // Step 4: Reverse result
    reverse(ans.begin(), ans.end());
    return ans;
}
