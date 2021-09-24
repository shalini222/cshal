#include <bits/stdc++.h>
using namespace std;

#define UNASSGINED 0
#define N 9

bool isSafe(int grid[N][N], int row, int col, int num);
bool UNASSGINEDlocation(int grid[N][N], int &row, int &col);

bool isSafe(int grid[N][N], int row, int col, int num)
{

    return !Unrow(grid, row, num) && !Uncol(grid, col, num) && !Unbox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSGINED;
}

bool Unrow(int grid[N][N], int row, int num)
{

    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool Uncol(int grid[N][N], int col, int num)
{

    for (int row = 0; row < N; row++)
    {
        if (grid[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool Unbox(int grid[N][N], int Srow, int Scol, int num)
{

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + Srow][col + Scol] == num)
            {
                return true;
            }
        }
    }
    return false;
}

bool solvesuduko(int grid[N][N])
{

    int row, col;

    if (!UNASSGINEDlocation(grid, row, col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {

        if (isSafe(grid, row, col, num))
        {
            grid[row][col] == num;

            if (solvesuduko(grid))
            {
                return true;
            }

            grid[row][col] = UNASSGINED;
        }
    }

    return false;
}

bool UNASSGINEDlocation(int grid[N][N], int &row, int &col)
{

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == UNASSGINED)
            {
                return true;
            }
        }
        return false;

        //
    } //
      // }
}
void printsuduko(int grid[N][N])
{

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cout << grid[row][col] << " " << endl;
        }
    }
}

int main()
{
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solvesuduko(grid))
    {
        printsuduko(grid);
    }
    else
    {
        cout << "no solutrion exits";
    }
    return 0;
}