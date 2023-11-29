#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// #define INFINITY 9999
// #define max 5

// void dijkstra(int G[max][max], int n, int startnode);

void printGraph(const vector<vector<int>> &graph)
{

    cout << "Adjency Matrix\n\n";

    cout << "|0|A|B|C|D|E|\n";
    cout << "|-|-|-|-|-|-|\n";

    char label = 'A';
    for (const vector<int> &row : graph)
    {
        cout << "|" << label << "|";
        for (int weight : row)
        {
            if (weight == -1)
            {
                cout << "--";
            }
            else
            {
                cout << weight << "|";
            }
        }
        cout << "\n";
        label++;
    }
}

void print_weighted_adj_list(vector<vector<int>> graph)
{
    int nodes = graph.size() - 1;

    for (const vector<int> &row : graph)
    {
        for (int node : row)
        {
                cout << node << ", ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> graph_matrix = {
        {0, 1, 0, 3, 10},
        {1, 0, 5, 0, 0},
        {0, 5, 0, 2, 1},
        {3, 0, 2, 0, 6},
        {10, 0, 0, 6, 0}};

    vector<vector<int>> graph_list = {
        {},
        {(2, 1), (4, 3), (5, 10)},
        {(1, 1), (3, 5)},
        {(2, 5), (4, 2), (5, 1)},
        {(1, 3), (3, 2), (5, 6)},
        {(4, 6), (1, 10), (3, 1)}    
    };

    vector<vector<int>> graph_list_unweighted = {
        {},
        {(2), (4), (5)},
        {(1), (3)},
        {(2), (4), (5)},
        {(1), (3), (5)},
        {(4), (1), (3)}    
    };

    // cout<<graph_list.size();

    // print_weighted_adj_list(graph_list);
}
