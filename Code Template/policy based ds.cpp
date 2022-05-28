#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>pds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pds; 
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> pds; 

//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

void solve(){
    pds T;
    vector<ll>v={1,3,3,5,7,10};
    for(ll i=0; i<v.size(); i++){
        T.insert(v[i]);
    }
    ll q;
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            //compute total occurrence of a
            ll a;
            cin>>a;
            ll lb=T.order_of_key(a);
            ll ub=T.order_of_key(a+1);
            //cout<<ub<<" "<<lb<<"\n";
            cout<<ub-lb<<"\n";
        }
        else{
            //set value val in index idx
            ll idx,val; 
            cin>>idx>>val;
            ll currIdx=T.order_of_key(v[idx-1]);    //find the index 
            T.erase(T.find_by_order(currIdx));      //go to that index and erase it
            T.insert(val);
            v[idx]=val;

            for(auto i:T){
                cout<<i<<" ";
            }cout<<"\n";

        }
    }
}

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
        solve();
    }
    return 0;
}



