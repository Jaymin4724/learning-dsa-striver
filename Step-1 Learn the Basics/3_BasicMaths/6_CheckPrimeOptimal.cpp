#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number, count = 0;
    cin >> number;
    if (number == 1)
    {
        cout << "no";
        return 0;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            count++;
        }
    }
    if (count > 0)
    {
        cout << "no";
    }
    else
    {
        cout << "yes";
    }
    return 0;
}