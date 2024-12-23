#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int gcd = 1;
    int min = a > b ? b : a;
    for (int i = 1; i <= min; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = gcd(a, b);
    cout << ans;
    return 0;
}