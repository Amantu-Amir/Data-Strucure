#include<bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;

ll v[N];
class temp{
public:
	ll val;
	ll lazy;
};

temp tree[N*4];

void build(ll node, ll start, ll end){
	if(start==end){
		tree[node].val=v[start];
		return;
	}
	ll mid=(start+end)/2;
	build(node*2, start, mid);
	build(node*2+1, mid+1, end);
}

void propagation(ll node, ll start, ll end){
	if(start!=end){
		tree[node*2].lazy+=tree[node].lazy;
		tree[node*2+1].lazy+=tree[node].lazy;
	}
	else{
		tree[node].val+=tree[node].lazy;
	}
	tree[node].lazy=0;
}

ll query(ll node, ll start, ll end, ll idx){
	if(tree[node].lazy>0){
		propagation(node, start, end);
	}
	if(start==end){
		return tree[node].val;
	}
	ll mid=(start+end)/2;
	if(idx<=mid){
		return query(node*2, start, mid, idx);
	}
	else{
		return query(node*2+1, mid+1, end, idx);
	}
}

void update(ll node, ll start, ll end, ll L, ll R, ll val){
	if(start>R or end<L or start>end){
		return;
	}
	if(start>=L and end<=R){
		tree[node].lazy+=val;
		return;
	}
	ll mid=(start+end)/2;
	update(node*2, start, mid, L, R, val);
	update(node*2+1, mid+1, end, L, R, val);
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
	ll type,idx,val,l,r;
	while(q--){
		cin>>type;
		if(type==2){	//query
			cin>>idx;
			ll res=query(1,1,n,idx);
			cout<<res<<"\n";
		}
		else{		   //update
			cin>>l>>r>>val;
			update(1,1,n,l,r,val);
		}
	}
	return 0;
}



