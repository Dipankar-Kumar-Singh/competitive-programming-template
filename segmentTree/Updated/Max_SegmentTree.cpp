#include<bits/stdc++.h>
using namespace std ;

class segmentTreeMAX
{
    public:
    int N = 0;
    int INF_LOCAL_TO_NULLYFY = numeric_limits<int>::min() ;
    vector<int> seg , v;

    segmentTreeMAX(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    int query(int l, int r) { return query(0, 0, N - 1, l, r); }

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
            seg[n] = max(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return INF_LOCAL_TO_NULLYFY;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        if (s != e)
        {
            seg[n] = max(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return max(query(n * 2 + 1, s, mid, l, r), query(n * 2 + 2, mid + 1, e, l, r));
    }
};