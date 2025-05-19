#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll node, vector<vector<ll>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int main() {
    ll n = 5;
    vector<vector<ll>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0};
    adj[2] = {0, 3, 4};
    adj[3] = {2};
    adj[4] = {3};

    vector<bool> visitedDFS(n, false);
    cout << "DFS traversal: ";
    dfs(0, adj, visitedDFS);
    cout << endl;

    return 0;
}
