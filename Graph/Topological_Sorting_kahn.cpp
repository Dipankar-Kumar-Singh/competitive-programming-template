#include <bits/stdc++.h>
using namespace std;


#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()

const int N = 1e6 + 10 ;
vector<bool> vis(N) ;
vector<int> g[N] ;
vector<int> order ;
set<int> input ; 
map<int,int> par ;
int n = 0 ;
map<int,int> in ;

bool kahn (){

    priority_queue< int , vector<int> , greater<int>> pq ;
    for(int i = 1 ; i <= n ; i++ ){
        if(in[i]==0){pq.push(i);}
    }

    while (!pq.empty())
    {
        int x = pq.top() ;
        order.push_back(x) ;
        pq.pop() ;

        for(int i : g[x] ){
            in[i]--;
            if(in[i]==0) pq.push(i) ;
        }

    }

    return order.size() == n ;
    
}


int main()
{
    FAST 
    int m ; cin >> n >> m ;
    
    while (m--)
    {
        int x , y ; cin >> x >> y ;
        g[x].push_back(y) ; 
        input.insert(x) ; input.insert(y) ;
        in[y]++ ;
    }

    if(!kahn( )) {cout << "Sandro fails." ; exit(0) ;}
    for(auto &x : order) cout << x << " " ;

}

