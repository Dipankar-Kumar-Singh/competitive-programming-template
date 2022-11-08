#include <bits/stdc++.h>
using namespace std ;

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> par;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    par[v][0] = p;
    for (int i = 1; i <= l; ++i)
        par[v][i] = par[par[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(par[u][i], v))
            u = par[u][i];
    }
    return par[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    par.assign(n, vector<int>(l + 1));
    dfs(root, root);
}


int main()
{

}