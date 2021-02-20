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


ll rep[N+5];
void init(){
	for(ll i=1; i<=N; i++){
		rep[i]=i;
	}
}

ll find_rep(ll n){
	if(n==rep[n]){return n;}
	return rep[n]=find_rep(rep[n]);
}

void join_node(ll u,ll v){
	u=find_rep(u);
	v=find_rep(v);
	if(u!=v){
		rep[u]=v;
	}
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		init();
		ll node,edge;
		cin>>node>>edge;
		ll u,v;
		for(ll i=0; i<edge; i++){
			cin>>u>>v;
			join_node(u,v);
		}
		for(ll i=1; i<=node; i++){
			find_rep(i);
		}
		for(ll i=1; i<=node; i++){
      cout<<i<<" "<<rep[i]<<"\n";
    }
	}
	return 0;
}

