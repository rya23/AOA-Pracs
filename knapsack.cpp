#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> profit, int maximumweight, int size)
{
    vector<vector<int>> table(size, vector<int>(maximumweight + 1, 0));

    for (int i = weight[0]; i < maximumweight + 1; i++)
    {
        table[0][i] = profit[0];
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < maximumweight + 1; j++)
        {
            if (weight[i] <= j)
                table[i][j] = max(table[i - 1][j], table[i - 1][j - weight[i]] + profit[i]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < maximumweight + 1; j++)
        {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
    return table[size - 1][maximumweight];
}

int main()
{
    vector<int> profit = {12, 10, 20, 15};
    vector<int> weight = {2, 1, 3, 2};
    int size = profit.size();
    int maximumweight = 5;

    cout << "hello\n"
         << knapsack(weight, profit, maximumweight, size);
}
