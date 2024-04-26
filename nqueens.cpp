#include <bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>> &board, int row, int column)
{

    for (int i = 0; i < column; i++)
    {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = column; i < board.size() && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

bool nqueen(vector<vector<int>> &board, int column)
{

    if (column >= board.size())
        return true;
    for (int i = 0; i < board.size(); i++)
    {
        if (issafe(board, i, column))
        {
            board[i][column] = 1;
            if (nqueen(board, column + 1))
                return true;
            board[i][column] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter size of Board : ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (nqueen(board, 0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
}