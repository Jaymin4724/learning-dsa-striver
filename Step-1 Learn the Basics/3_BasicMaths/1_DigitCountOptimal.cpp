#include <bits/stdc++.h>
using namespace std;
int main()
{
    int number, count;
    cin >> number;
    count = (int)(log10(number) + 1);
    cout << count;
    return 0;
}