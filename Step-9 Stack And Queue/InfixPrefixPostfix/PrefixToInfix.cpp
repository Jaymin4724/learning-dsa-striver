#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N)
string prefixToInfix(string &s)
{
    stack<string> st;

    for (int i = s.size() - 1; i >= 0; --i)
    {
        char ch = s[i];

        // Operand
        if (isalnum(ch))
        {
            st.push(string(1, ch)); // convert char to string
        }
        // Operator
        else
        {
            string a = st.top(); // left
            st.pop();
            string b = st.top(); // right
            st.pop();
            string temp = "(" + a + ch + b + ")";
            st.push(temp);
        }
    }

    return st.top();
}
