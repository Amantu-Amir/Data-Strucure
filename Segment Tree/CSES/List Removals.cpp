#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5;

ll res;
vector<ll>v;
vector<pair<ll,ll>>tree(N*4);

void build(ll node, ll start, ll end){
	if(start==end){
		tree[node].F=1;
		tree[node].S=v[start-1];
		return;
	}
	ll mid=(start+end)/2;
	build(node*2,start,mid);
	build(node*2+1,mid+1,end);
	tree[node].F=tree[node*2].F+tree[node*2+1].F;
}

void query(ll node, ll start, ll end, ll idx){	
	if(start==end){
		res=tree[node].S;
		tree[node].F=0;
		return;
	}
	ll mid=(start+end)/2;
	if(tree[node*2].F>=idx){
		query(node*2,start,mid,idx);
	}
	else{
		idx-=tree[node*2].F;
		query(node*2+1,mid+1,end,idx);
	}
	tree[node].F=tree[node*2].F+tree[node*2+1].F;
	//cout<<node<<" "<<tree[node].F<<"\n";
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	while(t--){
		ll n,idx; cin>>n;
		v.resize(n);
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		build(1,1,n);
		for(ll i=0; i<n; i++){
			cin>>idx;
			query(1,1,n,idx);
			cout<<res<<"\n";
		}
	}

	return 0;
}

