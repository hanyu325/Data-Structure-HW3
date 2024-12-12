// 1113568 Alice 2024.12.12
// question 1

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> create_adjacency_list(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj_list(V);

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    return adj_list;
}

int main() {
    int V, E;
    int tmp1, tmp2;
    cout << "Please input the number of nodes (V) and edges (E): ";
    while (cin >> V >> E) {
        vector<pair<int, int>> edges(E);

        for (int i = 0; i < E; i++) {
            cin >> tmp1 >> tmp2;
            edges[i] = pair<int, int>(tmp1, tmp2);
        }


        vector<vector<int>> result = create_adjacency_list(V, edges);

        for (int i = 0; i < result.size(); ++i) {
            cout << i << ": ";
            for (int neighbor : result[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
