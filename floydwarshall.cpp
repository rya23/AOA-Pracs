#include <bits/stdc++.h>
using namespace std;

#define INF 99999

void warshal(vector<vector<int>> &graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if ((graph[i][j] >= (graph[i][k] + graph[k][j])) && graph[i][k] != INF && graph[k][j] != INF)
                {
                    graph[i][j] = (graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter no of edges : ";
    cin >> n;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
        vector<int> tem;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cout << "Path from : " << i << " to " << j << " :";
            cin >> temp;
            if (temp == -1)
                tem.push_back(INF);
            else
                tem.push_back(temp);
        }
        graph.push_back(tem);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
    // vector<vector<int>> graph = {{0, 5, INF, 10},
    //                              {INF, 0, 3, INF},
    //                              {INF, INF, 0, 1},
    //                              {INF, INF, INF, 0}};
    // int n = graph.size();
    warshal(graph);
}