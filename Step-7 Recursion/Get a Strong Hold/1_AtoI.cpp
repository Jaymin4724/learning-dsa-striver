class Solution
{
public:
    int helper(int idx, int acc, int sign, string s)
    {
        int n = s.size();
        // Base case
        // string traversed / curr index is not a digit
        if (idx == n || !isdigit(s[idx]))
            return acc * sign;

        int digit = s[idx] - '0';
        if (acc > (INT_MAX - digit) / 10)
        {
            if (sign == 1)
                return INT_MAX;
            if (sign == -1)
                return INT_MIN;
        }

        int newAcc = acc * 10 + digit;
        return helper(idx + 1, newAcc, sign, s);
    }
    int myAtoi(string s)
    {
        int sign = 1;
        int n = s.size();
        int i = 0;
        long acc = 0;

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

        return helper(i, acc, sign, s);
    }
};