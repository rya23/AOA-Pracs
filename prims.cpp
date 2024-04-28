#include <bits\stdc++.h>
using namespace std;

int mindistance(vector<int> &key, vector<bool> &mstset)
{

    int minimum = INT_MAX;
    int minindex;
    for (int i = 0; i < key.size(); i++)
    {
        if (!mstset[i] && key[i] < minimum)
        {
            minimum = key[i];
            minindex = i;
        }
    }
    return minindex;
}

void prims(vector<vector<int>> &graph, int source)
{
    vector<int> parent(graph.size(), -1);
    vector<int> key(graph.size(), INT_MAX);
    vector<bool> mstset(graph.size(), false);

    key[source] = 0;
    for (int i = 0; i < graph.size() - 1; i++)
    {
        int mindist = mindistance(key, mstset);
        mstset[mindist] = true;
        for (int j = 0; j < graph.size(); j++)
        {
            if (!mstset[j] && graph[mindist][j] && graph[mindist][j] < key[j])
            {
                key[j] = graph[mindist][j];
                parent[j] = mindist;
            }
        }
    }
    for (int i = 1; i < parent.size(); i++)
    {
        cout << i << " - " << parent[i] << " = " << key[i] << endl;
    }
}

int main()
{
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                 {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                 {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                 {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                 {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                 {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                 {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                 {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                 {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    prims(graph, 0);
}