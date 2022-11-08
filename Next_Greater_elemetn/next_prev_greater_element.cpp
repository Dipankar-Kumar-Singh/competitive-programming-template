#include<bits/stdc++.h>
using namespace std ;

vector<int> nextGreater_indexs(vector<int>& arr, int n) {
    stack<int> s;	
        vector<int> result(n, n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = i;	
            s.pop();
        }
        s.push(i);
    }
        return result;
}
 
vector<int> prevGreater_indexs(vector<int>& arr, int n) {
    stack<int> s;	
        vector<int> result(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = i;	
            s.pop();
        }
        s.push(i);
    }
        return result;
}

vector<int> nextGreater(vector<int>& arr, int n) {
    stack<int> s;	
        vector<int> result(n, n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i];	
            s.pop();
        }
        s.push(i);
    }
        return result;
}
 
vector<int> prevGreater(vector<int>& arr, int n) {
    stack<int> s;	
        vector<int> result(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i];	
            s.pop();
        }
        s.push(i);
    }
        return result;
}

void printNGE(vector<int> arr, int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " -- "
             << next << endl;
    }
}

int main()
{
    // vector<int> arr = {1,2,11,1,1,1,0,2,5,67,7,734,34,0,193} ;
    vector<int> arr = {1,34,0,1953} ;
    int n = arr.size() ;
    vector<int> ng = nextGreater(arr, n); 
    vector<int> pg = prevGreater(arr, n); 

    // nextGreater --> for finding next greater element ..
    // nextGreater_index --> for finding next greater element's index

    // NOTE -> NEXt GREATER ELEMENT ... AT LAST POS sTORE DUMMY VLAUE [size of index ==> n] ;
    // so it is out responsiblity not to acces that ... 

    

    for(int i = 0 ; i < n; i++)
    {
        cout << arr[i] << " -- " <<  ng[i] << " \n" ;
        // cout << arr[ngindex[i]] << " " ;
    }

    
    cout << endl << endl ;
    printNGE(arr,n) ;

    


}