#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18+1
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const ll P=29;
const ll N=1e5+50;
const ll mod=1e9+7;

ordered_set mex;
vector<ll> adj[N];
unordered_map<ll,ll> cnt;
ll vis[N], val[N], res; 

void dfs(ll root){
    vis[root]=1;
    cnt[val[root]]++;
    mex.insert(val[root]);
    ll siz=mex.size();
    ll L=0, R=siz-1, currMex=0;
    while(L<=R){
    	ll mid=L+(R-L)/2;
    	ll m=*mex.find_by_order(mid);
    	if(m==mid){
    		currMex=m+1;
    		L=mid+1;
    	}
    	else{
    		R=mid-1;
    	}
    }
    res=max(res, currMex);
    for(auto child:adj[root]){
        if(vis[child]==0){
            dfs(child);
        }
    }
    cnt[val[root]]--;
    if(cnt[val[root]]==0){
    	mex.erase(mex.find_by_order(mex.order_of_key(val[root])));
    }
}

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
        ll node;
        cin>>node;
        for(ll i=1; i<=node; i++){
            cin>>val[i];
        }
        ll u, v;
        for(ll i=1; i<=(node-1); i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1);
        cout<<res<<"\n";
    }
    return 0;
}



