#include <bits/stdc++.h>
using namespace std;

bool selectionsort(vector<int> &arr)
{

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minimum])
            {
                minimum = j;
            }
            swap(arr[minimum], arr[i]);
        }
    }
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionsort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
}