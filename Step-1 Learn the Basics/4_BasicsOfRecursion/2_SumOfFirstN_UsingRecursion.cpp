#include <iostream>
using namespace std;

void SumParam(int i, int sum) // parameterized way
{
    if (i < 1)
    {
        cout << sum << " ";
        return;
    }
    SumParam(i - 1, sum + i);
}

int SumFunc(int n) // functional way
{
    if (n == 0)
    {
        return 0;
    }
    return n + SumFunc(n - 1);
}

int main()
{
    int n = 5;
    SumParam(n, 0);       // parameterized way
    int sum = SumFunc(n); // functional way
    cout << sum;
    return 0;
}
