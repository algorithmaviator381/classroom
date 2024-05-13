#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
    int destination;
    int weight;
};

struct Vertex
{
    int index;
    int distance;
};

struct CompareDistance
{
    bool operator()(const Vertex &v1, const Vertex &v2)
    {
        return v1.distance > v2.distance;
    }
};

class Graph
{
private:
    int vertices;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int source, int destination, int weight)
    {
        Edge edge;
        edge.destination = destination;
        edge.weight = weight;
        adjacencyList[source].push_back(edge);
    }

    void dijkstra(int source)
    {
        vector<int> distance(vertices, INT_MAX);
        distance[source] = 0;

        priority_queue<Vertex, vector<Vertex>, CompareDistance> pq;
        pq.push({source, 0});

        while (!pq.empty())
        {
            int u = pq.top().index;
            pq.pop();

            for (const Edge &edge : adjacencyList[u])
            {
                int v = edge.destination;
                int w = edge.weight;

                if (distance[u] != INT_MAX && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                    pq.push({v, distance[v]});
                }
            }
        }

        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < vertices; ++i)
        {
            cout << "To vertex " << i << ": " << distance[i] << "\n";
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    g.dijkstra(0);

    return 0;
}
