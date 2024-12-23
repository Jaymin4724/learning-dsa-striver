#include <bits/stdc++.h>
using namespace std;

void print1()
{
    // *****
    // *****
    // *****
    // *****
    // *****
    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 1; cols <= 5; cols++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print2()
{
    // *
    // **
    // ***
    // ****
    // *****
    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 1; cols <= rows; cols++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print3()
{
    // 1
    // 12
    // 123
    // 1234
    // 12345
    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 1; cols <= rows; cols++)
        {
            cout << cols;
        }
        cout << endl;
    }
}
void print4()
{
    // 1
    // 22
    // 333
    // 4444
    // 55555
    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 1; cols <= rows; cols++)
        {
            cout << rows;
        }
        cout << endl;
    }
}
void print5()
{
    // *****
    // ****
    // ***
    // **
    // *
    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 5; cols >= rows; cols--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void print6()
{
    // 12345
    // 1234
    // 123
    // 12
    // 1
    int rows, cols;
    for (rows = 5; rows >= 1; rows--)
    {
        for (cols = 1; cols <= rows; cols++)
        {
            cout << cols;
        }
        cout << endl;
    }
}
void print7()
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 1; cols <= rows + 4; cols++)
        {
            if (cols >= (6 - rows))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print8()
{
    //     *********
    //      *******
    //       *****
    //        ***
    //         *

    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 9; cols >= rows; cols--)
        {
            if (cols <= 10 - rows)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print9()
{
    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *
    int rows, cols;
    for (rows = 1; rows <= 10; rows++)
    {
        for (cols = 1; cols <= 9; cols++)
        {
            if (rows >= 1 && rows <= 5)
            {
                if (cols <= rows + 4 && cols >= 6 - rows)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }

            else if (rows > 5 && rows <= 10)
            {
                if (cols <= 10 - (rows - 5) && cols >= rows - 5)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
void print10()
{
    // *
    // **
    // ***
    // ****
    // *****
    // ****
    // ***
    // **
    // *
    int rows, cols;
    for (rows = 1; rows <= 9; rows++)
    {
        for (cols = 1; cols <= 5; cols++)
        {
            if (rows >= 1 && rows <= 5)
            {
                if (cols <= rows)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else if (rows > 5 && rows <= 9)
            {
                if (cols <= 10 - rows)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
void print11()
{
    // 1
    // 01
    // 101
    // 0101
    // 10101
    int rows, cols;

    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 1; cols <= rows; cols++)
        {
            if (rows % 2 == 0) // even row
            {
                if (cols % 2 == 0) // even column
                {
                    cout << "1";
                }
                else // odd column
                {
                    cout << "0";
                }
            }
            else // odd row
            {
                if (cols % 2 == 0) // even column
                {
                    cout << "0";
                }
                else // odd column
                {
                    cout << "1";
                }
            }
        }
        cout << endl;
    }
}
void print12()
{
    // 1      1
    // 12    21
    // 123  321
    // 12344321
    int rows, cols;
    int count = 0; // to print
    for (rows = 1; rows <= 4; rows++)
    {
        for (cols = 1; cols <= 8; cols++)
        {
            if (cols <= rows)
            {
                count++;
                cout << count;
            }
            else if (cols >= 9 - rows)
            {
                cout << count;
                count--;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print13()
{
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
    int rows, cols, count = 0;
    for (rows = 1; rows <= 5; rows++)
    {
        for (cols = 1; cols <= rows; cols++)
        {
            count++;
            cout << count << " ";
        }
        cout << endl;
    }
}
void print14()
{

    // A
    // AB
    // ABC
    // ABCD
    // ABCDE

    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        char num = 65;
        for (cols = 1; cols <= rows; cols++)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }
}
void print15()
{
    // ABCDE
    // ABCD
    // ABC
    // AB
    // A
    int rows, cols;
    for (rows = 1; rows <= 5; rows++)
    {
        char num = 65;
        for (cols = 5; cols >= rows; cols--)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }
}
void print16()
{
    // A
    // BB
    // CCC
    // DDDD
    // EEEEE

    char num = 65;
    for (int rows = 1; rows <= 5; rows++)
    {
        for (int cols = 1; cols <= rows; cols++)
        {
            cout << num;
        }
        num++;
        cout << endl;
    }
}
void print17()
{
    //    A
    //   ABA
    //  ABCBA
    // ABCDCBA
    for (int rows = 1; rows <= 4; rows++)
    {
        char num = 65;
        for (int cols = 1; cols <= rows + 3; cols++)
        {
            if (cols >= 5 - rows)
            {
                cout << num;
                if (cols < 4)
                {
                    num++;
                }
                else
                {
                    num--;
                }
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void print18()
{
    // E
    // DE
    // CDE
    // BCDE
    // ABCDE
    char num = 69;
    for (int rows = 1; rows <= 5; rows++)
    {
        char temp = num;
        for (int cols = 1; cols <= rows; cols++)
        {
            cout << temp;
            temp++;
        }
        num--;
        cout << endl;
    }
}
void print19()
{
    //     **********
    //     ****  ****
    //     ***    ***
    //     **      **
    //     *        *
    //     *        *
    //     **      **
    //     ***    ***
    //     ****  ****
    //     **********
    for (int rows = 1; rows <= 10; rows++)
    {
        for (int cols = 1; cols <= 10; cols++)
        {
            if (rows >= 1 && rows <= 5)
            {
                if (cols <= rows + 4 && cols >= 7 - rows)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
            }
            else if (rows >= 6 && rows <= 10)
            {
                if (cols <= 15 - rows && cols > rows - 5)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
            }
        }
        cout << endl;
    }
}
void print20()
{
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    for (int rows = 1; rows <= 9; rows++)
    {
        for (int cols = 1; cols <= 10; cols++)
        {
            if (rows >= 1 && rows <= 5)
            {
                if (cols <= rows || cols >= 11 - rows)
                {

                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            else if (rows >= 6 && rows <= 9)
            {
                if (cols <= 10 - rows || cols >= rows + 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}
void print21()
{
    // ****
    // *  *
    // *  *
    // ****
    for (int rows = 1; rows <= 4; rows++)
    {
        for (int cols = 1; cols <= 4; cols++)
        {
            if (rows > 1 && rows < 4)
            {
                if (cols > 1 && cols < 4)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
void print22()
{
    // 4444444
    // 4333334
    // 4322234
    // 4321234
    // 4322234
    // 4333334
    // 4444444
    int count, rows, cols;
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            // Calculate the value to print based on the distance from the edges
            int value = 4 - min({i, j, 6 - i, 6 - j});
            cout << value;
        }
        cout << endl; // Move to the next line after each row
    }
}

int main()
{
    cout << "Pattern-1" << endl;
    cout << "------------------------------------------" << endl;
    print1();
    cout << endl;

    cout << "Pattern-2" << endl;
    cout << "------------------------------------------" << endl;
    print2();
    cout << endl;

    cout << "Pattern-3" << endl;
    cout << "------------------------------------------" << endl;
    print3();
    cout << endl;

    cout << "Pattern-4" << endl;
    cout << "------------------------------------------" << endl;
    print4();
    cout << endl;

    cout << "Pattern-5" << endl;
    cout << "------------------------------------------" << endl;
    print5();
    cout << endl;

    cout << "Pattern-6" << endl;
    cout << "------------------------------------------" << endl;
    print6();
    cout << endl;

    cout << "Pattern-7" << endl;
    cout << "------------------------------------------" << endl;
    print7();
    cout << endl;

    cout << "Pattern-8" << endl;
    cout << "------------------------------------------" << endl;
    print8();
    cout << endl;

    cout << "Pattern-9" << endl;
    cout << "------------------------------------------" << endl;
    print9();
    cout << endl;

    cout << "Pattern-10" << endl;
    cout << "------------------------------------------" << endl;
    print10();
    cout << endl;

    cout << "Pattern-11" << endl;
    cout << "------------------------------------------" << endl;
    print11();
    cout << endl;

    cout << "Pattern-12" << endl;
    cout << "------------------------------------------" << endl;
    print12();
    cout << endl;

    cout << "Pattern-13" << endl;
    cout << "------------------------------------------" << endl;
    print13();
    cout << endl;

    cout << "Pattern-14" << endl;
    cout << "------------------------------------------" << endl;
    print14();
    cout << endl;

    cout << "Pattern-15" << endl;
    cout << "------------------------------------------" << endl;
    print15();
    cout << endl;

    cout << "Pattern-16" << endl;
    cout << "------------------------------------------" << endl;
    print16();
    cout << endl;

    cout << "Pattern-17" << endl;
    cout << "------------------------------------------" << endl;
    print17();
    cout << endl;

    cout << "Pattern-18" << endl;
    cout << "------------------------------------------" << endl;
    print18();
    cout << endl;

    cout << "Pattern-19" << endl;
    cout << "------------------------------------------" << endl;
    print19();
    cout << endl;

    cout << "Pattern-20" << endl;
    cout << "------------------------------------------" << endl;
    print20();
    cout << endl;

    cout << "Pattern-21" << endl;
    cout << "------------------------------------------" << endl;
    print21();
    cout << endl;

    cout << "Pattern-22" << endl;
    cout << "------------------------------------------" << endl;
    print22();
    cout << endl;

    return 0;
}