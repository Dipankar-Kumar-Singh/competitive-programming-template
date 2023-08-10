#include<bits/stdc++.h>
using namespace std ;

int main(){

    int n; cin >> n ;
    vector<int> v(n) ;

    // preprocessing ... 
    int len = (int) sqrt(n + 0.0) + 1 ;
    
    vector<int> data ;
    for(int i = 0 ; i < n ; i++){
        data[ i / len ] += v[i] ;
    }

    for(;;){
        int l , r; 
        cin >> l >> r ; 

        int ans = 0 ;
        int cl = l / len ; 
        int cr = r / len ;

        if( cl == cr ) {
            for(int i = l ; i <= r ; i++){
                ans += v[i] ; 
            }
        }

        int l , r ; 
        cin >> l >> r ;

        int cl = l / len ; 
        int cr = r / len ;

        if( cl == cr ) {
            for(int i = l ; i <= r ; i++){
                ans += v[i] ;
            }
        }

        else {

            // before .. 
            for(int i = l ; i < (cl + 1) * len ; i++) 
                ans += v[i] ;

            // blocks 

            for(int i = cl + 1 ; i <= cr - 1 ; i++)
                ans += data[i] ;

            // after ...
            for(int i = cr*len ;  i <= r ; i++) 
                ans += v[i] ;
        }
        

    }
    
}