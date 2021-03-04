#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6;

ll v[N],tree[N*4];
void build(ll node,ll start,ll end){
	if(start==end){
		tree[node]=v[start];
		return;
	}
	ll mid=(start+end)/2;
	build(node*2,start,mid);
	build(node*2+1,mid+1,end);
	tree[node]=tree[node*2]^tree[node*2+1];
}

ll query(ll node,ll start,ll end,ll L,ll R){
	if(start>R or end<L or start>end){
		return 0;
	}
	if(start>=L and end<=R){
		return tree[node];
	}
	ll mid=(start+end)/2;
	ll q1=query(node*2,start,mid,L,R);
	ll q2=query(node*2+1,mid+1,end,L,R);
	ll ret=q1^q2;
	return ret;
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll n,q; cin>>n>>q;
	for(ll i=1; i<=n; i++){
		cin>>v[i];
	}
	build(1,1,n);
	ll l,r;
	while(q--){
		cin>>l>>r;
		ll res=query(1,1,n,l,r);
		cout<<res<<"\n";
	}
	return 0;
}

