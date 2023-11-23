#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void print_weighted_adj_list(const vector<vector<pair<int, int>>>& graph_list) {
    for (int i = 1; i < graph_list.size(); ++i) {
        cout << "Node " << i << " is connected to: ";
        for (const auto& neighbor : graph_list[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

void dijkstra_matrix(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);

    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] > 0 && distance[v] > distance[u] + graph[u][v]) {
                distance[v] = distance[u] + graph[u][v];
                pq.push({distance[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << " using matrix:\n";
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << ": " << distance[i] << endl;
    }
}

int main() {
    vector<vector<int>> graph_matrix = {
        {0, 1, 0, 3, 10},
        {1, 0, 5, 0, 0},
        {0, 5, 0, 2, 1},
        {3, 0, 2, 0, 6},
        {10, 0, 0, 6, 0}
        };

    vector<vector<pair<int, int>>> graph_list = {
        {},
        {{2, 1}, {4, 3}, {5, 10}},
        {{1, 1}, {3, 5}},
        {{2, 5}, {4, 2}, {5, 1}},
        {{1, 3}, {3, 2}, {5, 6}},
        {{4, 6}, {1, 10}, {3, 1}}};

    dijkstra_matrix(graph_matrix, 0);

    return 0;
}
