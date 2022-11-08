#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, MAXK = 20;
vector<int> g[MAXN]; // Graph
int timer; // Counter
// Time of entering, Time of leaving, Binary lifting table
int tin[MAXN], tout[MAXN], par[MAXN][MAXK];

void dfs(int u, int p) {
    tin[u] = timer++;

    for (int j = 1; j < MAXK; j++) {
        // 2^x = 2^(x - 1) + 2^(x - 1)
        int lift = par[u][j - 1];
        par[u][j] = par[lift][j - 1];    
    }

    for (const auto &v : g[u]) {
        if (v == p) continue;

        // 2^0 (direct) parent of the node we are about to visit is the current node
        par[v][0] = u;
        dfs(v, u);
    }

    tout[u] = timer - 1;
}

// Is u an ancestor of v?
bool isAnc(int u, int v) {
    // Time of entering u has to be less than time of entering v
    // Time of leaving u has to be greater than time of leaving v
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// Finds the LCA
int query(int u, int v) {
    // Check if u is an ancestor of v or if v is an ancestor of u
    if (isAnc(u, v)) return u;
    if (isAnc(v, u)) return v;

    for (int j = MAXK - 1; j >= 0; j--) {
        int lift = par[u][j];
        
        if (!isAnc(lift, v)) {
            u = lift;
        }
    }

    // The direct parent of u is the LCA
    return par[u][0];
}

int main() {
    int N; // Number of vertices in the graph
    cin >> N;

    // Input edges
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // Convert to 0 based indexing

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1); // Tree is rooted at node 0

    int Q; // Number of queries
    cin >> Q;

    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        cout << query(u, v) + 1 << "\n";
    }
}