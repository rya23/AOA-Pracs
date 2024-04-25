#include <bits/stdc++.h>
using namespace std;

void subsetsum(vector<int> &set, vector<int> &subset, int sum, int index, int n)
{

    if (sum == 0)
    {
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << "\t";
        }
        cout << endl;
        return;
    }
    if (index == n)
    {
        return;
    }
    subsetsum(set, subset, sum, index + 1, n);
    if (set[index] <= sum)
    {
        subset.push_back(set[index]);
        subsetsum(set, subset, sum - set[index], index + 1, n);
        subset.pop_back();
    }
}

int main()
{

    vector<int> set = {5, 7, 10, 12, 15, 18, 20};
    int sum = 35;
    int n = set.size();
    vector<int> subset;
    subsetsum(set, subset, sum, 0, n);
}