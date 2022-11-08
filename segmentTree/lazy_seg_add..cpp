
int const N = 1e6 + 10;
vector<int> seg(4 * N, 0);
vector<int> lazy(4 * N, 0);
vector<int> v(N);

void pass(int n)
{
    seg[n] = seg[n * 2 + 1] + seg[n * 2 + 2];
}

void solvelazy(int n, int s, int e)
{
    int rng = e - s + 1;
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
        pass(n);
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
        lazy[n] += value;
        solvelazy(n, s, e);
        return;
    }
    int mid = (s + e) / 2;
    update(n * 2 + 1, s, mid, l, r, value);
    update(n * 2 + 2, mid + 1, e, l, r, value);
    if (s != e)
    {
        pass(n);
    }
}

int query(int n, int s, int e, int l, int r)
{
    solvelazy(n, s, e);
    if (s > r or e < l)
    {
        return 0;
    }
    if (s >= l and e <= r)
    {
        return seg[n];
    }
    int mid = (s + e) / 2;
    int ans = query(n * 2 + 1, s, mid, l, r) + query(n * 2 + 2, mid + 1, e, l, r);
    if (s != e)
    {
        pass(n);
    }
    return ans;
}