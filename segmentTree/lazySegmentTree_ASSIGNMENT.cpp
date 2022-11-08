
// Range assignment ..

int const N = 1e5 + 10;     // 🌻🌺 CHANGE N --> Acording to Question 
vector < int > seg (4*N) ;   //
vector < int > lazy (4*N) ;
vector < int > v ;          //🌷🥀 RESIZE THIS VEC ...clear it before next test case ... then build
 
void solvelazy(int n , int s , int e)
{
    if(lazy[n] == 0 ) return ;
    seg[n] = lazy[n] ; 
    if(s!=e)
    {
        lazy[2*n+1]  = lazy[n] ; 
        lazy[2*n+2] =  lazy[n] ;
    }
    lazy[n] = 0  ;
}

void build(int n, int s, int e)
{
    if(s==e)
    {
        seg[n] = v[s] ;
        return ;
    }

    int mid = (s+e)/2 ;
    build(2*n+1,s,mid) ;
    build(2*n+2,mid+1,e) ;
    seg[n] = seg[2*n+1] + seg[2*n+2] ;
}

void update(int n, int s, int e, int l, int r, int val)
{
    // RANGE update --> ASSIGNMENT .....[ l , r] --> new value --> val

    solvelazy(n,s,e) ;
 
    if(s>r or r<l) return ;
    if (s >= l and e <= r)
    {
        lazy[n] = val ; 
        solvelazy(n,s,e) ;
        return ;
    }

    int mid = (s+e)/2 ;
 
    if(l<=mid) 
        update(n*2 + 1, s, mid, l, r, val);
    if(r>mid) 
        update(n*2 + 2, mid + 1, e, l, r, val);
}
 
int query(int n , int s , int e , int id)
{
    solvelazy(n,s,e) ;
 
    if(s==e and s==id) 
    {
        solvelazy(n,s,e) ;
        return seg[n] ;
    }
 
    int mid = (s+e)/2  ;
    
    solvelazy(2*n+1,s,mid) ;
    solvelazy(2*n+2,mid+1,e) ;
    
    if(id<=mid) return query(2 * n + 1, s, mid, id);
    return query(2 * n + 2, mid + 1, e, id);
} 