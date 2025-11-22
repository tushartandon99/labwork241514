#include <iostream>
using namespace std;

int main() {
    int nodes, edges, u, v;
    int directed;

    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Is the graph directed? (1 = Yes, 0 = No): ";
    cin >> directed;

    int adj[nodes][nodes];

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            adj[i][j] = 0;
        }
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;

        adj[u][v] = 1;   // mark edge in matrix

        if (!directed)
            adj[v][u] = 1; // if undirected graph
    }

  
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
