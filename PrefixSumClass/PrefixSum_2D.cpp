#include<bits/stdc++.h>

class PrefixSum2D{

    public :
    int N = 0 ;
    std::vector<std::vector<int>> tree_pref , forest ;

    PrefixSum2D(std::vector<std::vector<int>> &v)
    {
        N = v.size() ;
        tree_pref = forest = std::vector<std::vector<int>>(N + 1 , std::vector<int>(N+1)) ;

        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                forest[i + 1][j + 1] = (v[i][j]);
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                tree_pref[i][j] =   forest[i][j] 
                                    + tree_pref[i - 1][j] 
                                    + tree_pref[i][j - 1] 
                                    - tree_pref[i - 1][j - 1];
            }
        }
    }

    int query(int from_row, int to_row, int from_col, int to_col)
    {
        return tree_pref[to_row][to_col]
                - tree_pref[from_row - 1][to_col]
                - tree_pref[to_row][from_col - 1]
                + tree_pref[from_row - 1][from_col - 1] ;
    }
};
