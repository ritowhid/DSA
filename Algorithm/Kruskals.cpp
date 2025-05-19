//Kruskal 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Edge;
typedef tuple<ll, ll, ll> WeightedEdge;

class DSU {
private:
    vector<ll> parent, rank;
public:
    DSU(ll n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    ll find(ll x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(ll x, ll y) {
        ll xr = find(x);
        ll yr = find(y);
        if (xr == yr) return false;

        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
        return true;
    }
};

int main() {
    ll n = 5;
    vector<WeightedEdge> edges = {
        {1, 0, 1}, {3, 0, 2}, {4, 1, 2}, {2, 1, 3}, {5, 2, 3}, {7, 3, 4}
    };
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll totalWeight = 0;
    vector<WeightedEdge> mst;
    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            totalWeight += w;
            mst.push_back({ w, u, v });
        }
    }
    cout << "Edges in MST:\n";
    for (auto [w, u, v] : mst) {
        cout << u << " - " << v << " (weight " << w << ")\n";
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}