#include <iostream>
#include <vector>

using namespace std;

void printGraph(const vector<vector<int>>& graph) {
    cout << "|0|A|B|C|D|E|\n";
    cout << "|-|-|-|-|-|-|\n";

    char label = 'A';   
    for (const vector<int>& row : graph) {
        cout << "|" << label << "|";
        for (int weight : row) {
            if (weight == -1) {
                cout << "-|";
            } else {
                cout << weight << "|";
            }
        }
        cout << "\n";
        label++;
    }
}

int main() {
    vector<vector<int>> graph = {
        {-1, 1, -1, 3, 10},
        {1, -1, 5, -1, -1},
        {-1, 5, -1, 2, -1},
        {3, -1, 2, -1, 6},
        {10, -1, -1, 6, -1}
    };

    printGraph(graph);

    return 0;
}
