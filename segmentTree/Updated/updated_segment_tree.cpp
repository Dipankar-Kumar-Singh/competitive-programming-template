#include<bits/stdc++.h>
using namespace std ;

class segmentTree
{
    //!  IMPORTANT :
    //TODO : CHANGE THE RETURN VALUE IN QUERY [ for {0,INF} seg out of range ] 

    public:
    int N = 0;
    vector<int> seg;
    vector<int> v;

    int mergeOP(int &a, int &b)
    {
        return a + b;

        // return min(a,b) ;
        // return max(a,b)  ;
        // return gcd(a, b);
        // return a ^ b ;
        // return a | b ;
        // return a & b ;
    }

    segmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    void update(int l, int r, int value)
    {
        update(0, 0, N - 1, l, r, value);
    }

    int query(int l, int r)
    {
        return query(0, 0, N - 1, l, r);
    }

    void build(int n, int s, int e)
    {
        if (s == e)
        {
            seg[n] = v[s];
            return;
        }

        int mid = (s + e) / 2;
        build(n * 2 + 1, s, mid);
        build(n * 2 + 2, mid + 1, e);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    void update(int n, int s, int e, int l, int r, int value)
    {
        if (s > r or e < l)
        {
            return;
        }
        if (s >= l and e <= r)
        {
            seg[n] += value;
            return;
        }

        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return 0;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);

        int ans = mergeOP(left, right);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return ans;
    }
};

class segmentTreeLazy
{
    //!  IMPORTANT :
    //TODO : CHANGE THE RETURN VALUE IN QUERY [ for {0,INF} seg out of range ] 

public:
    int N = 1e6 + 10;
    vector<int> seg , lazy , v ;

    int mergeOP(int &a, int &b)
    {
        return a + b;
        // return min(a,b) ;
        // return max(a,b)  ;
        // return gcd(a, b);
        // return a ^ b ;
        // return a | b ;
        // return a & b ;
    }

    segmentTreeLazy(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
        build(0, 0, N - 1);
    }

    void update(int l, int r, int value)
    {
        update(0, 0, N - 1, l, r, value);
    }

    int query(int l, int r)
    {
        return query(0, 0, N - 1, l, r);
    }

    void solvelazy(int n, int s, int e)
    {
        int rng = e - s + 1;
        //! for assignment or for MIN/MAX ... change this ... to seg[n] +=  lazy[n] ;
        // seg[n] +=  lazy[n] 

        // This is for Addition : 
        seg[n] += lazy[n] * rng;

        if (s != e)
        {
            lazy[n * 2 + 1] += lazy[n];
            lazy[n * 2 + 2] += lazy[n];
        }
        lazy[n] = 0;
    }

    void build(int n, int s, int e)
    {
        if (s == e)
        {
            seg[n] = v[s];
            return;
        }
        int mid = (s + e) / 2;
        build(n * 2 + 1, s, mid);
        build(n * 2 + 2, mid + 1, e);
        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }

    void update(int n, int s, int e, int l, int r, int value)
    {
        solvelazy(n, s, e);

        if (s > r or e < l)
        {
            return;
        }

        if (s >= l and e <= r)
        {
            // !! FOR MIN / MAX [ use += ] //
            // !! FOR ASSIGNMENT [ use = ] //

            lazy[n] += value;
            solvelazy(n, s, e);
            return;
        }

        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);

        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        solvelazy(n, s, e);
        if (s > r or e < l)
        {
            //! Change Return Type to Counter [ to Nullify effect and Preserve Ans ] 
            //* FOR [ + ,GCD ]  ==> 0 , for MIN ==> INF , for MAX = -INF , 
            //*==> ex ==> for AND --> Give it ==> "111111" all Ones
            
            return 0;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }

        int mid = (s + e) / 2;

        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }

        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);
        return mergeOP(left, right);
    }
};


class segmentTree_MergeSortTree {
public :
    int N = 5e5;
    vector<vector<int>> seg;
    vector<int> v;

    segmentTree_MergeSortTree(vector<int> &vec)
    {
        v = vec;
        N = v.size();
        seg = vector<vector<int>>(4 * N);
        build(0, 0, N - 1);
    }

    void build(int n, int s, int e)
    {
        if (s == e)
        {
            seg[n].push_back(v[s]);
            return;
        }
        
        int mid = (s + e) / 2;
        build(2 * n + 1, s, mid);
        build(2 * n + 2, mid + 1, e);

        merge(
                begin(seg[2 * n + 1]), end(seg[2 * n + 1]),
                begin(seg[2 * n + 2]), end(seg[2 * n + 2]),
                back_inserter(seg[n])
             );
    } 

    int query_equalto(int l, int r, int val)
    {
        return query_equalto(0, 0, N - 1, l, r, val);
    }

    int query_equalto(int n, int s, int e, int l, int r, int val)
    {
        if (e < l or s > r)
        {
            return 0;
        }

        if (l <= s and e <= r)
        {
            auto [ps, pe] = equal_range(begin(seg[n]), end(seg[n]), val);
            return pe - ps;
        }

        int mid = (s + e) / 2;

        return(
                query_equalto(2 * n + 1, s, mid, l, r, val) +
                query_equalto(2 * n + 2, mid + 1, e, l, r, val)
              );
    }

    int query_greaterthan(int l, int r, int val)
    {
        return query_greaterthan(0, 0, N - 1, l, r, val);
    }

    int query_greaterthan(int n, int s, int e, int l, int r, int val)
    {
        if (e < l or s > r)
        {
            return 0;
        }

        if (l <= s and e <= r)
        {
            int id = upper_bound(begin(seg[n]), end(seg[n]), val) - seg[n].begin();
            return (seg[n].size() - id);
        }

        int mid = (s + e) / 2;

        return(
                query_greaterthan(2 * n + 1, s, mid, l, r, val) +
                query_greaterthan(2 * n + 2, mid + 1, e, l, r, val)
              );
    }

    int query_lessthan(int l, int r, int val)
    {
        return query_lessthan(0, 0, N - 1, l, r, val);
    }

    int query_lessthan(int n, int s, int e, int l, int r, int val)
    {
        if (e < l or s > r)
        {
            return 0;
        }

        if (l <= s and e <= r)
        {
            int id = lower_bound(begin(seg[n]), end(seg[n]), val) - seg[n].begin();
            return id;
        }

        int mid = (s + e) / 2;
        return (
                query_lessthan(2 * n + 1, s, mid, l, r, val) +
                query_lessthan(2 * n + 2, mid + 1, e, l, r, val)
               );
    }

    int count_inversion_using_segment_tree()
    {
        int inversion = 0;
        for (int i = 1; i < N; i++)
        {
            inversion += (query_greaterthan(0, 0, N - 1, 0, i - 1, v[i]));
        }
        return inversion;
    }
};