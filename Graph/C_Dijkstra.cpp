#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int const N = 1e5 + 100 ;
vector<pair<int, int>> g[N];

void dijkstra(int start , int end)
{
    vector<int> dis(N,LONG_LONG_MAX) , vis(N);
    vector<int> p(N) ;
    multiset< pair< int , int >> s ; 

    s.insert({0,start}) ;
    dis[start] = 0 ;

    while(s.size())
    {
        auto curr = *s.begin() ;
        s.erase(s.begin()) ;

        auto [d_node , node ] = curr ;

        if(vis[node]) continue;
        vis[node] = 1 ;

        for(auto [child, wt] : g[node])
        {
            if(wt + dis[node] < dis[child]) 
            {
                dis[child]  = wt + dis[node] ; 
                p[child] = node ;
                s.insert({dis[child] , child}) ;
            }
        }
    }

    if(dis[end]==LONG_LONG_MAX) {cout << -1 ; return ; }

    vector<int> path ; 
    int curr = end ;
    while (1)
    {
        path.push_back(curr) ;
        if(curr == start ) break ;
        curr = p[curr] ;
    }

    reverse(all(path)) ; 
    for(auto &x : path) cout <<  x << " " ;
}

signed main()
{   FAST  

    int n , m ; cin >> n >> m ;
    for(int query = 1 ; query <= m ; query++)
    {
        int x , y , w ; cin >> x >> y >> w ; 
        g[x].push_back({y,w}) ;
        g[y].push_back({x,w}) ;
    }
    
    dijkstra(1,n) ;    
}