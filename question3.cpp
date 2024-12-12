// 1113568 Alice 2024.12.12
// question 3

#include <iostream>
#include <vector>
using namespace std;

void dfs_util(int vertex, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dfs_result) {
    visited[vertex] = true;
    dfs_result.push_back(vertex);

    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            dfs_util(neighbor, adj, visited, dfs_result);
        }
    }
}

vector<int> dfs_traversal(int V, vector<vector<int>>& adj) {
    vector<int> dfs_result;
    vector<bool> visited(V, false);

    dfs_util(0, adj, visited, dfs_result);

    return dfs_result;
}

int main() {
    vector<vector<int>> adj = { {1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2} };
    int V = adj.size();

    vector<int> result = dfs_traversal(V, adj);

    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
