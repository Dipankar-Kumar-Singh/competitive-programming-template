#include<bits/stdc++.h>
using namespace std ;


class prefixSum{

    public :
    std::vector<int> p ;
    int n ; 

    prefixSum(vector<int> &v)
    {
        n = v.size() ;
        p = vector<int>(n+1) ;
        partial_sum(begin(v),end(v),p.begin()+1) ;
    }
    
    int query(int l , int r)
    {
        ++l , ++r ;
        return p[r] - p[l-1] ;
    }
} ;
