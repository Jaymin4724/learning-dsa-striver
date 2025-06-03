// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
#include <bits/stdc++.h>
using namespace std;

void mark_rows(vector<vector<int>> &matrix, int row, int colSize)
{
    for (int col = 0; col < colSize; col++)
    {
        if (matrix[row][col] != 0)
        {
            matrix[row][col] = INT_MAX;
        }
    }
}
void mark_cols(vector<vector<int>> &matrix, int col, int rowSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        if (matrix[row][col] != 0)
        {
            matrix[row][col] = INT_MAX;
        }
    }
}

// BrueForce Approach
// TC : O(n^3)
// SC : O(1)
void setZeroesBruteForce(vector<vector<int>> &matrix)
{
    int rowSize = matrix.size();
    int colSize;
    for (int row = 0; row < rowSize; row++)
    {
        colSize = matrix[row].size();
        for (int col = 0; col < colSize; col++)
        {
            if (matrix[row][col] == 0)
            {
                mark_rows(matrix, row, colSize);
                mark_cols(matrix, col, rowSize);
            }
        }
    }
    for (int row = 0; row < rowSize; row++)
    {
        colSize = matrix[row].size();
        for (int col = 0; col < colSize; col++)
        {
            if (matrix[row][col] == INT_MAX)
            {
                matrix[row][col] = 0;
            }
        }
    }
}

// TC: O(n^2)
// SC: O(m+n)
void setZeroesBetter(vector<vector<int>> &matrix)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    vector<bool> zeroRows(rowSize, false);
    vector<bool> zeroCols(colSize, false);

    // First pass: identify rows and columns that need to be zeroed
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            if (matrix[row][col] == 0)
            {
                zeroRows[row] = true;
                zeroCols[col] = true;
            }
        }
    }

    // Second pass: set rows to zero
    for (int row = 0; row < rowSize; row++)
    {
        if (zeroRows[row])
        {
            for (int col = 0; col < colSize; col++)
            {
                matrix[row][col] = 0;
            }
        }
    }

    // Third pass: set columns to zero
    for (int col = 0; col < colSize; col++)
    {
        if (zeroCols[col])
        {
            for (int row = 0; row < rowSize; row++)
            {
                matrix[row][col] = 0;
            }
        }
    }
}

// TC : O(n^2)
// SC : O(1)
void setZeroesOptimal(vector<vector<int>> &matrix)
{
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    bool col0 = false;

    // First pass: mark zeros in first row and column
    for (int row = 0; row < rowSize; row++)
    {
        if (matrix[row][0] == 0)
            col0 = true;
        for (int col = 1; col < colSize; col++)
        {
            if (matrix[row][col] == 0)
            {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    // Second pass: set matrix cells to zero using markers
    for (int row = 1; row < rowSize; row++)
    {
        for (int col = 1; col < colSize; col++)
        {
            if (matrix[row][0] == 0 || matrix[0][col] == 0)
            {
                matrix[row][col] = 0;
            }
        }
    }

    // Handle first row
    if (matrix[0][0] == 0)
    {
        for (int col = 0; col < colSize; col++)
        {
            matrix[0][col] = 0;
        }
    }

    // Handle first column
    if (col0)
    {
        for (int row = 0; row < rowSize; row++)
        {
            matrix[row][0] = 0;
        }
    }
}
