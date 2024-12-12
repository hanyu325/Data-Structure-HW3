// 1113568 Alice 2024.12.12
// question 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs_traversal(int V, vector<vector<int>>& adj) {
    vector<int> bfs_result;
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bfs_result.push_back(current);
        
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return bfs_result;
}

int main() {
    vector<vector<int>> adj = { {2, 3, 1}, {0}, {0, 4}, {0}, {2} };
    int V = adj.size();

    vector<int> result = bfs_traversal(V, adj);

    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
