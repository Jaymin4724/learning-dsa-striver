#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N)
string postfixToInfix(string &s)
{
    stack<string> st;
    for (auto i : s)
    {
        // Operand
        if (isalnum(i))
        {
            st.push(string(1,i));
        }
        // Operator
        else
        {
            string b = st.top(); // right operand
            st.pop();
            string a = st.top(); // left operand
            st.pop();
            string temp = "(" + a + i + b + ")";
            st.push(temp);
        }
    }
    return st.top();
}
