#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        a > b ? a = a % b : b = b % a;
    }
    return a == 0 ? b : a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int lcm = (a * b) / gcd(a, b);
    cout << gcd(a, b) << endl;
    cout << lcm;
}