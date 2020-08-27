#include <bits/stdc++.h>
using namespace std;

int board[11][11]{};

bool isPossible(int n, int row, int col)
{
    // col
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    // diag right
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    // diag left
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void solver(int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (isPossible(n, row, j))
        {
            board[row][j] = 1;
            solver(n, row + 1);
            board[row][j] = 0;
        }
    }
    return;
}

void nqueens(int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n\n";
    solver(n, 0);
}

int main()
{
    nqueens(4);
}