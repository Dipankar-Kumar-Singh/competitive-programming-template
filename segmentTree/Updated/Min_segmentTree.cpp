#include<bits/stdc++.h>
using namespace std ;


class segmentTreeMIN
{
    public:
    int N = 0;
    int MAX_INF_LOCAL_TO_NULLYFY = numeric_limits<int>::max() ;
    vector<int> seg , v;

    segmentTreeMIN(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
        build(0, 0, N - 1);
    }

    int query(int l, int r) { return query(0, 0, N - 1, l, r); }

    private:
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
            seg[n] = min(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return MAX_INF_LOCAL_TO_NULLYFY;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        if (s != e)
        {
            seg[n] = min(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return min(query(n * 2 + 1, s, mid, l, r), query(n * 2 + 2, mid + 1, e, l, r));
    }
};