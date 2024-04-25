#include <bits/stdc++.h>
using namespace std;

void binarysearch(vector<int> &list, int number)
{

    int high = list.size() - 1;
    int low = 0;
    int mid;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (list[mid] == number)
        {
            cout << "Number found at index : " << mid;
            return;
        }

        else if (list[mid] < number)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Number not found";
}

int main()
{
    vector<int> list = {1, 2, 3, 4, 6, 7, 8};
    int number = 1;
    binarysearch(list, number);
}