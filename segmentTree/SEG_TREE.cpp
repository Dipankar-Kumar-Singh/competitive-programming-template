#include<vector>


class segmentTree
{
    private:
    int N = 1e6 + 10;
    std::vector<int> seg , lazy , v ;
 
    int mergeOP(int &a, int &b) {
        return (a | b) ;
    }

    public:
    segmentTree(int n) 
    {
        N = n;
        v = std::vector<int>(n);
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
    }
 
    segmentTree(std::vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
        build(0, 0, N - 1);
    }
 
    void update(int l, int r, int value){
        update(0, 0, N - 1, l, r, value);
    }
 
    int query(int l, int r){
        return query(0, 0, N - 1, l, r);
    }
    
    private:
    void solvelazy(int n, int s, int e){
        if(lazy[n] == 0 ) return ;

        seg[n] = lazy[n] ;
        if (s != e)
        {
            lazy[n * 2 + 1] = lazy[n];
            lazy[n * 2 + 2] = lazy[n];
        }
        lazy[n] = 0;
    }
 
    void build(int n, int s, int e)
    {
        if (s == e)        {
            seg[n] = v[s];
            return;
        }
        int mid = (s + e) / 2;
        build(n * 2 + 1, s, mid);
        build(n * 2 + 2, mid + 1, e);
        if (s != e) {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }
 
    void update(int n, int s, int e, int l, int r, int value)
    {
        solvelazy(n, s, e);
 
        if (s > r or e < l){
            return;
        }
 
        if (s >= l and e <= r){
            lazy[n] = value;
            solvelazy(n, s, e);
            return;
        }
 
        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);
 
        if (s != e){
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }
 
    int query(int n, int s, int e, int l, int r)
    {
        solvelazy(n, s, e);
 
        if (s > r or e < l){
            return 0LL;
        }
        if (s >= l and e <= r){
            return seg[n];
        }
 
        int mid = (s + e) / 2;
        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);
        return mergeOP(left, right);
    }
};
 