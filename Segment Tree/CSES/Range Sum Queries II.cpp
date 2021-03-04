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
	tree[node]=tree[node*2]+tree[node*2+1];
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
	return q1+q2;
}

void update(ll node,ll start,ll end,ll idx,ll val){
	if(start==end and idx==start){
		tree[node]=val;
		return;
	}
	ll mid=(start+end)/2;
	if(idx<=mid){
		update(node*2,start,mid,idx,val);
	}
	else{
		update(node*2+1,mid+1,end,idx,val);
	}
	tree[node]=tree[node*2]+tree[node*2+1];
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
			cin>>l>>r;
			ll res=query(1,1,n,l,r);
			cout<<res<<"\n";
		}
		else{		   //update
			cin>>idx>>val;
			update(1,1,n,idx,val);
		}
	}
	return 0;
}

