#include <bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n)
{
    int temp = n;
    int sum = 0;
    int digitcount = (log10(n) + 1);
    while (temp != 0)
    {
        int digit = temp % 10;
        sum = sum + pow(digit, digitcount);
        temp = temp / 10;
    }
    return (sum == n);
}

int main()
{
    int num;
    cin >> num;
    int ans;
    ans = checkArmstrong(num);
    if (ans == 1)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}