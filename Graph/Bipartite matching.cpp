#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define all(v) v.begin(),v.end()
#define mod 1000000000 
#define N 200010
#define inf 10000000000
#define NIL 0
#define INF INT_MAX
class BGraph
{
    int m, n;
    list<int> *adj;
    int *pair_u, *pair_v, *dist;

	public:
    BGraph(int m, int n); 
    void addEdge(int u, int v);
    void deleteEdge(int u);
    bool bfs();
    bool dfs(int u);
    int hopcroftKarpAlgorithm();
};
int BGraph::hopcroftKarpAlgorithm()
{
    pair_u = new int[m + 1];
    pair_v = new int[n + 1];
    dist = new int[m + 1];
    for (int u = 0; u <= m; u++)
        pair_u[u] = NIL;
    for (int v = 0; v <= n; v++)
        pair_v[v] = NIL;
    int result = 0;
    while (bfs())
    {
        for (int u = 1; u <= m; u++)
            if (pair_u[u] == NIL && dfs(u))
                result++;
    }
    return result;
}
bool BGraph::bfs()
{
    queue<int> q;
    for (int u = 1; u <= m; u++)
    {
        if (pair_u[u] == NIL)
        {
            dist[u] = 0;
            q.push(u);
        }
    	else
            dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dist[u] < dist[NIL])
        {
            list<int>::iterator it;
            for (it = adj[u].begin(); it != adj[u].end(); ++it)
            {
                int v = *it;
                if (dist[pair_v[v]] == INF)
                {
                    dist[pair_v[v]] = dist[u] + 1;
                    q.push(pair_v[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool BGraph::dfs(int u)
{
    if (u != NIL)
    {
        std::list<int>::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            int v = *it;
            if (dist[pair_v[v]] == dist[u] + 1)
            {
                if (dfs(pair_v[v]) == true)
                {
                    pair_v[v] = u;
                    pair_u[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
BGraph::BGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new std::list<int>[m + 1];
}
void BGraph::addEdge(int u, int v) //adding edge from left to right 
{
    adj[u].push_back(v);
}
void BGraph::deleteEdge(int u)
{
	adj[u].clear();
}
//edges should be gives in order of their respective list 
//like 1st on left side with 3rd on right side is (1,3) 

signed main()
{
    //add edge from indexing 1
    //0th edge is taken as dummy vertex
    int v1,v2;
    cin>>v1;
    v2=v1;
    BGraph g(v1, v2); 
    int u,v;
    for(int i=0;i<v1+1;i++)
    {
    	cin>>u>>v;
    	g.addEdge(u,v);
    }
    int ans=g.hopcroftKarpAlgorithm();
    cout<<ans;
}