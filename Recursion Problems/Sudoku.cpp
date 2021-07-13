#include <bits/stdc++.h>
using namespace std;

//Sudoku Solver

bool check(int mat[][9], int i, int j, int num)
{

    for (int k = 0; k < 9; k++)
    {
        if (mat[k][j] == num || mat[i][k] == num)
        {
            return false;
        }
    }

    int start = (i / 3) * 3;
    int end = (j / 3) * 3;

    for (int x = start; x < start + 3; x++)
    {
        for (int y = end; y < end + 3; y++)
        {
            if (mat[x][y] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku(int mat[][9], int i, int j)
{
    if (i == 9)
    {
        for (int ind = 0; ind < 9; ind++)
        {
            for (int in = 0; in < 9; in++)
            {
                cout << mat[ind][in] << " ";
            }
            cout << endl;
        }
        return true;
    }

    if (j == 9)
    {
        return sudoku(mat, i + 1, 0);
    }

    if (mat[i][j] != 0)
    {
        return sudoku(mat, i, j + 1);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (check(mat, i, j, num))
        {
            mat[i][j] = num;

            bool subProblem = sudoku(mat, i, j + 1);
            if (subProblem)
            {
                return true;
            }
        }
    }

    mat[i][j] = 0;
    return false;
}

int main()
{

    int mat[][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!sudoku(mat, 0, 0))
    {
        cout << "No Solution" << endl;
    }
    return 0;
}
