#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define all(v) v.begin(),v.end()
#define mod 1000000007 
#define N 200010
#define inf LLONG_MAX
#define pb(x) push_back(x)


vector<int> graph[N];
vector<char> color;
vector<int> parent;
vector<int> visited;
int cycle_start, cycle_end;

bool dfs_directed(int v) 
{
    color[v] = 1;
    for (int u : graph[v]) 
    {
        if (color[u] == 0) 
        {
            parent[u] = v;
            if (dfs_directed(u))
                return true;	
        } 
        else if (color[u] == 1) 
        {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void find_cycle_directed(int n) 
{
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) 
    {
        if (color[v] == 0 && dfs_directed(v))
            break;
    }

    if (cycle_start == -1) 
    {
        cout << "Acyclic" << endl;
    } 
    else 
    {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}

bool dfs_undirected(int v, int par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (int u : graph[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs_undirected(u, parent[u]))
            return true;
    }
    return false;
}

void find_cycle_undirected(int n) {
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dfs_undirected(v, parent[v]))
            break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }
}


//Note : Always check for the following things
//1. Max value of N
//2. Mod value
//3. Test for your own case

signed main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            u--;v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        //checking for cycle 
        find_cycle_undirected(n);       
        
    }
}