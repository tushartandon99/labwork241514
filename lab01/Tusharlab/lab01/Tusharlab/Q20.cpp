#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, int n) {
    vector<int> visited(n, 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS Traversal starting from " << start << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

    
        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = 1;
                q.push(next);
            }
        }
    }

    cout << endl;
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // remove for directed graph
    }

    int start;
    cout << "Enter starting node for BFS: ";
    cin >> start;

    BFS(start, adj, n);

    return 0;
}
