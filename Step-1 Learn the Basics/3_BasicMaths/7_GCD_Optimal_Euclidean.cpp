#include <bits/stdc++.h>
using namespace std;

// TC Explaination:
// O(log(min(a, b))) because the size of the numbers reduces by at least half in each step.
// How? 
// In each step, we are replacing the larger number with the remainder of the division of the larger number by the smaller number.
// This means that the size of the numbers is halved in each step, leading to a logarithmic time complexity.
// For example, if we have two numbers a and b, the first step will reduce the size of the larger number to at most a/2 or b/2.
// This halving continues until one of the numbers becomes zero, at which point the other number is the GCD.

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        // here we are using the property that gcd(a, b) = gcd(b, a % b) , where b is the smaller number
        (a > b) ? a = a % b : b = b % a;
    }
    return (a == 0) ? b : a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = gcd(a, b);
    cout << ans;
    return 0;
}