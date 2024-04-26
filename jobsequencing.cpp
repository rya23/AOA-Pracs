#include <bits\stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}
int jobsequencing(vector<Job> &arr, int n)
{
    int maxprofit = 0;
    int jobs = 0;
    sort(arr.begin(), arr.end(), compare);

    int maxi = arr[0].deadline;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i].deadline);
    }
    vector<int> slot(maxi + 1, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                jobs++;
                maxprofit += arr[i].profit;
                break;
            }
        }
    }

    for (int i = 0; i < slot.size(); i++)
    {
        cout << slot[i] << "\t";
    }
    cout << endl;
    return maxprofit;
}

int main()
{
    vector<Job> arr = {{1, 5, 100}, {2, 3, 10}, {3, 3, 13}, {4, 4, 15}, {5, 3, 12}, {6, 2, 9}, {7, 7, 105}};
    cout << jobsequencing(arr, arr.size());
}