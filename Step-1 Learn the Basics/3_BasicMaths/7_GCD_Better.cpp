#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int min = a > b ? a : b;
    for (int i = min; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = gcd(a, b);
    cout << ans;
    return 0;
}