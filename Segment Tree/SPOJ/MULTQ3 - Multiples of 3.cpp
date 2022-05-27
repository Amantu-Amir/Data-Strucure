#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/Tree_policy.hpp>
// using namespace __gnu_pbds;
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
//typedef Tree<ll, null_type,less_equal<ll>, rb_Tree_tag,Tree_order_statistics_node_update>pbds;
//typedef Tree<ll, null_type, less<ll>, rb_Tree_tag, Tree_order_statistics_node_update>pbds; 
//typedef Tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_Tree_tag, Tree_order_statistics_node_update>pbds; 

//------------------------------------------------------------------------------//


const ll P=29;
const ll N=1e5+50;
const ll mod=1e9+7;

ll lazy[N*4],x=3;		
ll Tree[N*4][3];

void build(ll node, ll b, ll e){
	//cout<<node<<" "<<b<<" "<<e<<"\n";
	if(b==e){
		Tree[node][0]=1;
		return;
	}
	ll mid=b+(e-b)/2;
	build(node*2,b,mid);
	build(node*2+1,mid+1,e);
	for(ll i=0; i<x; i++){
		Tree[node][i]=Tree[node*2][i]+Tree[node*2+1][i];
	}
}

void propagate(ll node, ll b, ll e){
	vector<ll>temp(x,0);
	for(ll i=0; i<x; i++){
		temp[(i+lazy[node])%x]+=Tree[node][i];
	}
	for(ll i=0; i<x; i++){
		Tree[node][i]=temp[i];
	}
	if(b!=e){
		lazy[node*2]=(lazy[node*2]+lazy[node])%x;
		lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%x;
	}
	lazy[node]=0;
}

void update(ll node, ll b, ll e, ll L, ll R){
	//cout<<node<<" "<<b<<" "<<e<<"\n";
	if(lazy[node]>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return;
	}
	if(b>=L and e<=R){
		lazy[node]+=1;
		propagate(node,b,e);
		return;
	}
	ll mid=b+(e-b)/2;
	update(node*2,b,mid,L,R);
	update(node*2+1,mid+1,e,L,R);
	for(ll i=0; i<x; i++){
		Tree[node][i]=Tree[node*2][i]+Tree[node*2+1][i];
	}
}

ll query(ll node,ll b,ll e,ll L,ll R){
	if(lazy[node]>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return 0;
	}
	if(b>=L and e<=R){
		return Tree[node][0];
	}
	ll mid=b+(e-b)/2;
	return query(node*2,b,mid,L,R)+query(node*2+1,mid+1,e,L,R);
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n,q;
		cin>>n>>q;
		build(1,1,n);
		while(q--){
			ll type;
			cin>>type;
			if(type==0){
				ll L,R; 
				cin>>L>>R;
				update(1,1,n,L+1,R+1);
			}
			else{
				ll L,R; 
				cin>>L>>R;
				ll ans=query(1,1,n,L+1,R+1);
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}



