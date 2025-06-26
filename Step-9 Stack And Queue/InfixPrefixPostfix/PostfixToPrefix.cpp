#include <bits/stdc++.h>
using namespace std;

// TC: O(N)
// SC: O(N)
string postfixToPrefix(string &s)
{
    stack<string> st;

    for (char i : s)
    {
        if (isalnum(i))
        {
            st.push(string(1, i));
        }
        else
        {
            string b = st.top();
            st.pop(); // right
            string a = st.top();
            st.pop(); // left
            string temp = string(1, i) + a + b;
            st.push(temp);
        }
    }

    return st.top();
}
