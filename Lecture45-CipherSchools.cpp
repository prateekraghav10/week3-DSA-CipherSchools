#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool detectCycle(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (visited[neighbor] && neighbor != node) {
            return true;
        }
        if (!visited[neighbor]) {
            if (detectCycle(neighbor)) {
                return true;
            }
        }
    }
    return false;
}

bool detectCycleUndirected(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (visited[neighbor] && neighbor != node) {
            return true;
        }
        if (!visited[neighbor]) {
            detectCycleUndirected(neighbor);
        }
    }
    return false;
}

int main() {
    adj = {{1, 2}, {2, 3}, {3, 0}, {0, 1}};
    visited.resize(adj.size(), false);
    if (detectCycle(0)) {
        cout << "The directed graph has a cycle." << endl;
    } else {
        cout << "The directed graph does not have a cycle." << endl;
    }
    adj = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    visited.resize(adj.size(), false);
    if (detectCycleUndirected(0)) {
        cout <<"The undirected graph has a cycle." << endl;
    } else {
        cout <<"The undirected graph does not have a cycle." << endl;
    }
    return 0;
}
