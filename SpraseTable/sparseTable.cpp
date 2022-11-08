
class SparseTable
{
    public : 
    int MAXN = 1e5 ;
    int LOG = 0 ;
    vector<int> lg ;
    vector<vector<int>> st ; 

    SparseTable(vector<int> &vec)
    {
        MAXN = vec.size() ;
        LOG = log2_floor(MAXN) ;
        // if less than c++20  ... use compute log ...
        st = vector<vector<int>>(MAXN, vector<int>(LOG + 1));

        /* ------------------------------- base layer ------------------------------- */
        for (int i = 0; i < MAXN; i++) st[i][0] = vec[i];

        /* ------------------------------ pre computing ----------------------------- */
        for (int j = 1; j <= LOG; j++)
            for (int i = 0; i + (1 << j) <= MAXN; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(int L , int R)
    {
        int j = log2_floor(R - L + 1);
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }

    void computeLog()
    {
        lg = vector<int>(MAXN + 1) ;
        lg[1] = 0;
        for (int i = 2; i <= MAXN; i++)
            lg[i] = lg[i/2] + 1;
    }

    int log2_floor(unsigned long i) {
        // In c++ 20 
        // return std::bit_width(i) - 1;
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }

};
