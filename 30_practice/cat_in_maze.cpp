#include <bits/stdc++.h>
using namespace std;

// print possible paths
// 1 - you can move
// 0 - cant move
// Possible Directions - L,R,U,D
// any cell can come once in a path

// reach 0,0(S) to 2,(D)
int path[3][3]{};

void solve(int maze[3][3], int row, int col)
{
    if (row == 2 && col == 2)
    {
        path[row][col] = 1;
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << "\n";
        }
        cout<<"\n";
        return;
    }
    if (row >= 3 || col >= 3 || col < 0 || row < 0 || maze[row][col] == 0 || path[row][col] == 1)
    {
        return;
    }
    path[row][col] = 1;
    // up
    solve(maze, row - 1, col);
    // right
    solve(maze, row, col + 1);
    // left
    solve(maze, row, col - 1);
    // down
    solve(maze, row + 1, col);
    path[row][col] = 0;
}

int main()
{
    int maze[3][3] = {
        {1, 1, 0},
        {1, 1, 1},
        {1, 1, 1}};
    solve(maze, 0, 0);
}