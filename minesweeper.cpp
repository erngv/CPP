/*
 * The function minesweeper creates a Minesweeper game setup starting off with some arrangement
 * of mines. Recall that in the Minesweeper game we have a board with some mines and those cells
 * that do not contain a mine have a number in it that indicates the total number of mines in the
 * neighboring cells. Some arrangement examples are provided in the main function.
 */

#include <iostream>
#include <vector>
using namespace std;

bool NW(vector<vector<bool>> matrix, int i, int j)
{
    return (i - 1 >= 0 && j - 1 >= 0);
}

bool N(vector<vector<bool>> matrix, int i, int j)
{
    return (i - 1 >= 0);
}

bool NE(vector<vector<bool>> matrix, int i, int j)
{
    return (i - 1 >= 0 && j + 1 < matrix[0].size());
}

bool E(vector<vector<bool>> matrix, int i, int j)
{
    return (j + 1 < matrix[0].size());
}

bool SE(vector<vector<bool>> matrix, int i, int j)
{
    return (i + 1 < matrix.size() && j + 1 < matrix[0].size());
}

bool S(vector<vector<bool>> matrix, int i, int j)
{
    return (i + 1 < matrix.size());
}

bool SW(vector<vector<bool>> matrix, int i, int j)
{
    return (i + 1 < matrix.size() && j - 1 >= 0);
}

bool W(vector<vector<bool>> matrix, int i, int j)
{
    return (j - 1 >= 0);
}

vector<vector<int>> minesweeper(vector<vector<bool>> matrix)
{
    vector<vector<int>> answ(matrix.size(), vector<int>(matrix[0].size(), 0));
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (NW(matrix, i, j) && matrix[i - 1][j - 1]) answ[i][j]++;
            if ( N(matrix, i, j) && matrix[i - 1][j]    ) answ[i][j]++;
            if (NE(matrix, i, j) && matrix[i - 1][j + 1]) answ[i][j]++;
            if ( E(matrix, i, j) && matrix[i][j + 1]    ) answ[i][j]++;
            if (SE(matrix, i, j) && matrix[i + 1][j + 1]) answ[i][j]++;
            if ( S(matrix, i, j) && matrix[i + 1][j]    ) answ[i][j]++;
            if (SW(matrix, i, j) && matrix[i + 1][j - 1]) answ[i][j]++;
            if ( W(matrix, i, j) && matrix[i][j - 1]    ) answ[i][j]++;
        }
    }
    return answ;
}

int main()
{
    vector<vector<int>> answ;
    
    answ = minesweeper({{true, false, false},
                        {false, true, false},
                        {false, false, false}});
    for (vector<int> v : answ)
    {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
    cout << endl;
    
    answ = minesweeper({{true, true, true},
                        {true, true, true},
                        {true, true, true}});
    for (vector<int> v : answ)
    {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
    cout << endl;

    answ = minesweeper({{false, false, false},
                        {false, false, false}});
    for (vector<int> v : answ)
    {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
    cout << endl;

    answ = minesweeper({{true, false},
                        {true, false},
                        {false, true},
                        {false, false},
                        {false, false}});
    for (vector<int> v : answ)
    {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
}
