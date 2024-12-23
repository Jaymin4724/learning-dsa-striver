#include <iostream>
using namespace std;

void count1ToN(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";
    count1ToN(i + 1, n);
}

void countNTo1(int i)
{
    if (i < 1)
        return;
    cout << i << " ";
    countNTo1(i - 1);
}

void count1ToNBacktracking(int i)
{
    if (i < 1)
        return;
    count1ToNBacktracking(i - 1);
    cout << i << " ";
}

void countNTo1Backtracking(int i, int n)
{
    if (i > n)
        return;
    countNTo1Backtracking(i + 1, n);
    cout << i << " ";
}

void printName(int n)
{
    if (n == 0)
        return;
    cout << "jaymin ";
    printName(n - 1);
}

int main()
{
    int n = 5;
    count1ToN(1, n);
    cout << endl;
    countNTo1(n);
    cout << endl;
    count1ToNBacktracking(n);
    cout << endl;
    countNTo1Backtracking(1, n);
    cout << endl;
    printName(n);
    return 0;
}
