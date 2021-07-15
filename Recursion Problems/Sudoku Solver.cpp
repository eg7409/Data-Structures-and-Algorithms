#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> v, int n, int i, int j, int num)
{

    for (int k = 0; k < n; k++)
    {
        if (v[i][k] == num || v[k][j] == num)
        {
            return false;
        }
    }

    int x = (i / 3) * 3;
    int y = (j / 3) * 3;

    for (int x1 = x; x1 < x + 3; x1++)
    {
        for (int y1 = y; y1 < y + 3; y1++)
        {
            if (v[x1][y1] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(vector<vector<int>> &v, int n, int i, int j)
{

    if (i == n)
    {
        return true;
    }

    if (j == n)
    {
        return sudoku(v, n, i + 1, 0);
    }

    if (v[i][j] != 0)
    {
        return sudoku(v, n, i, j + 1);
    }

    for (int num = 1; num <= n; num++)
    {
        if (isSafe(v, n, i, j, num))
        {
            v[i][j] = num;

            if (sudoku(v, n, i, j + 1))
            {
                return true;
            }
        }
    }

    v[i][j] = 0;
    return false;
}

vector<vector<int>> solveSudoku(vector<vector<int>> v)
{

    int n = 9;

    sudoku(v, n, 0, 0);
    return v;
}

int main()
{
   
    vector<vector<int>> v = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                             {6, 0, 0, 1, 9, 5, 0, 0, 0},
                             {0, 9, 8, 0, 0, 0, 0, 6, 0},
                             {8, 0, 0, 0, 6, 0, 0, 0, 3},
                             {4, 0, 0, 8, 0, 3, 0, 0, 1},
                             {7, 0, 0, 0, 2, 0, 0, 0, 6},
                             {0, 6, 0, 0, 0, 0, 2, 8, 0},
                             {0, 0, 0, 4, 1, 9, 0, 0, 5},
                             {0, 0, 0, 0, 8, 0, 0, 7, 9}};

                            

    v = solveSudoku(v);


    for(auto i : v){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }                      
    return 0;
}
