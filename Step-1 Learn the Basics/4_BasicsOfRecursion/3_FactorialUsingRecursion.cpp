#include <iostream>
using namespace std;

int FactFunc(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * FactFunc(n - 1);
}

int main()
{
    int n = 5;
    int sum = FactFunc(n); // functional way
    cout << sum;
    return 0;
}
