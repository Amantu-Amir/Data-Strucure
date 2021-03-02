#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

struct ordered_multiset{ 					// multiset supporting duplicating values in set
    int len = 0;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    unordered_map<int,int> mp; 				// hash = 96814
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>T;

    ordered_multiset(){
    	len = 0;
    	T.clear();
    	mp.clear();
    }

    inline void insert(int x){
        len++;
        x += MAXVAL;
        int c = mp[x]++;
        T.insert((x*ADD) + c);
    }

    inline void erase(int x){
        x += MAXVAL;
        int c = mp[x];
        if(c>0){
            c--, mp[x]--, len--;
            T.erase((x*ADD) + c); 
        } 
    }

    inline int kth(int k){        			// 1-based index,  returns the
        if(k<1 || k>len){return -1;}     	// K'th element in the treap,
        auto it = T.find_by_order(--k); 	// -1 if none exists
        return ((*it)/ADD) - MAXVAL; 
    } 

    inline int lower_bound(int x){      	// Count of value <x in treap
        x += MAXVAL;
        int c = mp[x];
        return (T.order_of_key((x*ADD)+c));
    }

    inline int upper_bound(int x){      	// Count of value <=x in treap
        x += MAXVAL;
        int c = mp[x];
        return (T.order_of_key((x*ADD)+c));
    }

    inline int size(){
    	return len;			 				// Number of elements in treap
    }  
};

int main(){
	int n; cin>>n;
    ordered_multiset s;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        s.insert(v[i]);
    }
    int q; cin>>q;
    while(q--){
    	int op; cin>>op;
    	if(op==1){
    		int idx,val;
    		cin>>idx>>val;
    		s.erase(v[idx-1]);
    		s.insert(val);
    	}
    	else{
    		int val;
    		cin>>val;
    		int res=s.lower_bound(val);	
    		cout<<res<<"\n";
    	}
    }
    return 0;
}



