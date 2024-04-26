#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int> &arr)
{
    int n = arr.size();

    // for (int i = 1; i < n; i++)
    // {
    //     int element = arr[i];
    //     int j = i - 1;
    //     while (arr[j] > element && j >= 0)
    //     {
    //         swap(arr[j + 1], arr[j]);
    //         j--;
    //     }
    // }
    for (int i = 1; i < n; i++)
    {
        int element = arr[i];
        int j = i - 1;
        while (arr[j] > element && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = element;
    }
}

int main()
{
    vector<int> arr = {64, -25, 12, 22, 11};
    insertionsort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
}