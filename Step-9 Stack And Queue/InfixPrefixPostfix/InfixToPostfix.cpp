#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N)
string infixToPostfix(string &s)
{
    string ans = "";
    unordered_map<char, int> priority = {
        {'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
    stack<char> st;

    for (char i : s)
    {
        // 1. Operand
        if (isalnum(i))
        {
            ans += i;
        }
        // 2. Opening Bracket
        else if (i == '(')
        {
            st.push(i);
        }
        // 4. Closing Bracket
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
        // 3. Operator
        else
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

    return ans;
}
