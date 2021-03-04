#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prnt(a) cout<<a
#define sp cout<<" "
#define nl cout<<"\n"
#define in1(a) cin>>a
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c;
#define inf 2147483647
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}

//------------------------------------------------------------------------------//
const int N=2e5+50;
const int mod=1e9+7;

class Data{
public:
	ll sum,prefix;
};

ll res,currPrefix;
vector<ll>v;
vector<Data>tree(N*3);

void build(ll node, ll start, ll end){
	if(start==end){
		tree[node].sum=v[start-1];
		tree[node].prefix=v[start-1];
		return;
	}
	ll mid=(start+end)/2;
	build(node*2,start,mid);
	build(node*2+1,mid+1,end);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
	tree[node].prefix=max(tree[node*2+1].prefix+tree[node*2].sum,tree[node*2].prefix);
	//cout<<node<<" "<<tree[node].prefix<<" "<<tree[node].sum<<"\n";
}

void update(ll node, ll start, ll end, ll idx, ll val){
	if(start==end){
		tree[node].sum=val;
		tree[node].prefix=val;
		return;
	}
	ll mid=(start+end)/2;
	if(idx<=mid){
		update(node*2,start,mid,idx,val);
	}
	else{
		update(node*2+1,mid+1,end,idx,val);
	}
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
	tree[node].prefix=max(tree[node*2+1].prefix+tree[node*2].sum,tree[node*2].prefix);
	//cout<<node<<" "<<tree[node].prefix<<" "<<tree[node].sum<<"\n";
}


pair<ll,ll> query(ll node, ll start, ll end, ll L, ll R){
	if(start>R or end<L or start>end){
		return {0,0};
	}
	if(start>=L and end<=R){
		return {tree[node].sum,tree[node].prefix};
	}
	ll mid=(start+end)/2;
	pair<ll,ll> q1=query(node*2,start,mid,L,R);
	pair<ll,ll> q2=query(node*2+1,mid+1,end,L,R);
	//cout<<node<<" "<<q1.F+q2.F<<" "<<max(q1.S,max(q1.F+q2.S, q1.F+q2.F))<<"\n";
	res=max(res,max(q1.F+q2.S, q1.F+q2.F));
	return {q1.F+q2.F, max(q1.S,max(q1.F+q2.S, q1.F+q2.F))};
}

int main(){

	//freopen("/root/Desktop/output.txt", "w", stdout);
	//freopen("/root/Desktop/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n,q; cin>>n>>q;
		v.resize(n);
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		build(1,1,n);
		ll op,a,b;
		while(q--){
			cin>>op>>a>>b;
			if(op==1){
				update(1,1,n,a,b);
			}
			else{
				pair<ll,ll> res=query(1,1,n,a,b);
				cout<<max(0LL,max(res.F,res.S))<<"\n";
			}
		}
	}
	return 0;
}

