#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<ll, null_type,less_equal<ll>, 
rb_tree_tag,tree_order_statistics_node_update>pds;	//takes duplicates value;

//tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pds;

void solve(){
    pds T;
    ll n,q; cin>>n>>q;
    vector<ll>v(n+1);
    for(ll i=1; i<=n; i++){
    	cin>>v[i];
    	T.insert(v[i]);
    }
    while(q--){
        char x; ll y,z; 
        cin>>x>>y>>z;
        if (x=='?'){
            cout<<(T.order_of_key(z+1) - T.order_of_key(y))<<"\n";
        }
        else{
            T.erase(T.find_by_order(T.order_of_key(v[y])));
            v[y] = z;
            T.insert(z);
        }
    }
}    


 /*
        order_of_key(n) : Find the position of n;
        find_by_order(idx) : Find the value of this position
 */

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}