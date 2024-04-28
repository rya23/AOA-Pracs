#include <bits\stdc++.h>
using namespace std;

int minimumdistance(vector<int> &distance, vector<bool> &sptset)
{
    int min = INT_MAX;
    int index;

    for (int i = 0; i < distance.size(); i++)
    {
        if (sptset[i] == false && distance[i] <= min)
        {
            min = distance[i];
            index = i;
        }
    }
    return index;
}

void prims(vector<vector<int>> &graph, int source)
{

    vector<int> distance(graph.size(), INT_MAX);
    vector<bool> sptset(graph.size(), false);

    distance[source] = 0;
    for (int i = 0; i < graph.size() - 1; i++)
    {
        int minimumgraph = minimumdistance(distance, sptset);
        sptset[minimumgraph] = true;

        for (int j = 0; j < graph.size(); j++)
        {
            if (!sptset[j] && graph[minimumgraph][j] && distance[minimumgraph] != INT_MAX && distance[minimumgraph] + graph[minimumgraph][j] < distance[j])
            {
                distance[j] = distance[minimumgraph] + graph[minimumgraph][j];
            }
        }
    }

    for (int i = 0; i < distance.size(); i++)
    {
        cout << "Shortest path from " << source << " to " << i << " is : " << distance[i] << endl;
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