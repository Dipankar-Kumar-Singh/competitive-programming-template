function<void(int)> HLD_REORDER = [&](int _root)->void{
    vector<vector<int>> &adj = g ; 

    vector<int> siz , dep,  parent ; 
    parent = siz = dep = vector<int>(g.size() + 1);

    parent[_root] = -1 ;

    function<void(int)> dfs_hld = [&](int u) -> void
    {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        siz[u] = 1;
        for (auto &v : adj[u])
        {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs_hld(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    };

    dfs_hld(_root) ;
} ; 