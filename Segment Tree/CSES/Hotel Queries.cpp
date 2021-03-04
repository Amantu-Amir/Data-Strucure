#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5;

vector<ll>v;
vector<ll>tree(N*4);
void build(ll node, ll start, ll end){
	if(start==end){
		tree[node]=v[start-1];
		return;
	}
	ll mid=(start+end)/2;
	build(node*2,start,mid);
	build(node*2+1,mid+1,end);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}

void query(ll node, ll start, ll end, ll val){
	if(start==end){
		tree[node]-=val;
		cout<<start<<" ";
		return;
	}
	ll mid=(start+end)/2;
	if(tree[node*2]>=val){
		query(node*2,start,mid,val);
	}
	else{
		query(node*2+1,mid+1,end,val);
	}
	tree[node]=max(tree[node*2],tree[node*2+1]);
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll h,g,a; cin>>h>>g;
	v.resize(h);
	for(ll i=0; i<h; i++){
		cin>>v[i];
	}
	build(1,1,h);
	for(ll i=0; i<g; i++){
		cin>>a;
		if(tree[1]<a){cout<<"0 ";}
		else{query(1,1,h,a);}
	}
	return 0;
}

