#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number, count = 0;
    cin >> number;
    while (number != 0)
    {
        number = number / 10;
        count++;
    }
    cout << count;
    return 0;
}