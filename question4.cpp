// 1113568 Alice 2024.12.12
// question 4

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> pii;

int find_mst_weight(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    vector<bool> visited(V, false);

    pq.push(make_pair(0, 0));
    int mst_weight = 0;

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int weight = top.first;
        int current = top.second;

        if (visited[current]) continue;

        visited[current] = true;
        mst_weight += weight;

        for (auto &neighbor : adj[current]) {
            int next_vertex = neighbor.first;
            int edge_weight = neighbor.second;

            if (!visited[next_vertex]) {
                pq.push(make_pair(edge_weight, next_vertex));
            }
        }
    }

    return mst_weight;
}

int main() {
    int V = 3, E = 3;

    vector<vector<pii>> adj(V);

    adj[0].push_back(make_pair(1, 3));
    adj[1].push_back(make_pair(0, 3));
    adj[1].push_back(make_pair(2, 4));
    adj[2].push_back(make_pair(1, 4));
    adj[0].push_back(make_pair(2, 2));
    adj[2].push_back(make_pair(0, 2));

    int result = find_mst_weight(V, adj);

    cout << "Sum of weights in MST: " << result << endl;

    return 0;
}
