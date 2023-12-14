#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print_weighted_adj_list(const vector<vector<pair<int, int>>> &graph_list)
{
    for (int i = 1; i < graph_list.size(); ++i)
    {
        cout << "Node " << i << " is connected to: ";
        for (const auto &neighbor : graph_list[i])
        {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

void dijkstra_list(const vector<vector<pair<int, int>>> &graph_list, int start, vector<int> &distance, vector<int> &parent)
{
    int n = graph_list.size();
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
        {
            continue;
        }

        visited[u] = true;

        for (const auto &neighbor : graph_list[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!visited[v] && distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
}

int main()
{
    vector<vector<pair<int, int>>> graph_list = {
        {},
        {{2, 1}, {4, 3}, {5, 10}},
        {{1, 1}, {3, 5}},
        {{2, 5}, {4, 2}, {5, 1}},
        {{1, 3}, {3, 2}, {5, 6}},
        {{4, 6}, {1, 10}, {3, 1}}};

    // print_weighted_adj_list(graph_list);

    int start_node = 2;
    int end_node = 4;

    int n = graph_list.size();
    vector<int> distance(n);
    vector<int> parent(n, -1);

    // dijkstra_list(graph_list, start_node, distance, parent);

    cout << "Shortest distance from node " << start_node << " to " << end_node << ": " << distance[end_node] << endl;

    return 0;
}
