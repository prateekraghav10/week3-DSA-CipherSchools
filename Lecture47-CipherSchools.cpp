#include "bits/stdc++.h"
using namespace std;

//Topological Sort
vector<vector<int>> adj;
vector<int> indegree;
vector<int> sorted_nodes;

void topologicalSort() {
    for (int i = 0; i < adj.size(); i++) {
        if (indegree[i] == 0) {
            sorted_nodes.push_back(i);
        }
    }

    for (int node : sorted_nodes) {
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                sorted_nodes.push_back(neighbor);
            }
        }
    }
}

int main() {
    adj = {{1, 2}, {2, 3}, {3, 0}, {0, 1}};
    indegree.resize(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    topologicalSort();
    for (int node : sorted_nodes) {
        cout << node << " ";
    }
    cout<< endl;
    return 0;
}

/* Dijkstra algorithm */
//vector<vector<int>> adj;
//vector<int> dist;
//vector<bool> visited;
//
//void dijkstra(int src) {
//    dist[src] = 0;
//    visited[src] = true;
//    priority_queue<pair<int, int>> pq;
//    pq.push({0, src});
//
//    while (!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//
//        for (int neighbor : adj[u]) {
//            if (!visited[neighbor]) {
//                int w = dist[u] + 1;
//                if (w < dist[neighbor]) {
//                    dist[neighbor] = w;
//                    pq.push({w, neighbor});
//                }
//            }
//        }
//    }
//}
//
//int main() {
//    adj = {{1, 2}, {2, 3}, {3, 0}, {0, 1}};
//    dist.resize(adj.size(), INT_MAX);
//    visited.resize(adj.size(), false);
//    dijkstra(0);
//
//    for (int i = 0; i < dist.size(); i++) {
//        cout << dist[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}

