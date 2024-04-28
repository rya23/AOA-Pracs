#include <bits\stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = partition(arr, low, high);
        quicksort(arr, low, mid);
        quicksort(arr, mid + 1, high);
    }
    else
        return;
}

int main()
{
    vector<int> arr = {64, -25, 12, 22, 11};
    quicksort(arr, 0, arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
}