#include<bits/stdc++.h>
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
//------------------------------------------------------------------------------//


const ll p=29;
const ll N=1e5+50;
const ll mod=1e9+7;

vector<pair<ll,ll>>prefixMax(N*4);
vector<pair<ll,ll>>prefixMin(N*4);
vector<pair<ll,ll>>suffixMax(N*4);
vector<pair<ll,ll>>suffixMin(N*4);

vector<ll>prefixSum(N);
vector<ll>suffixSum(N);

void build(ll node, ll b, ll e){
	if(b==e){
		prefixMax[node]=prefixMin[node]={prefixSum[b],b};
		suffixMax[node]=suffixMin[node]={suffixSum[b],b};
		return;
	}
	ll mid=Mid(b,e);
	build(node*2,b,mid);
	build(node*2+1,mid+1,e);
	//Prefix Tree
	if(prefixMax[node*2].F>prefixMax[node*2+1].F){
		prefixMax[node]=prefixMax[node*2];
	}
	else{
		prefixMax[node]=prefixMax[node*2+1];
	}
	if(prefixMin[node*2].F<prefixMin[node*2+1].F){
		prefixMin[node]=prefixMin[node*2];
	}
	else{
		prefixMin[node]=prefixMin[node*2+1];
	}
	//Suffix Tree
	if(suffixMax[node*2].F>suffixMax[node*2+1].F){
		suffixMax[node]=suffixMax[node*2];
	}
	else{
		suffixMax[node]=suffixMax[node*2+1];
	}
	if(suffixMin[node*2].F<suffixMin[node*2+1].F){
		suffixMin[node]=suffixMin[node*2];
	}
	else{
		suffixMin[node]=suffixMin[node*2+1];
	}
}

pair<ll,ll> prefixQueryMax(ll node, ll b, ll e, ll L, ll R){
	if(b>R or e<L or b>e){
		return {-inf,0};
	}
	if(b>=L and e<=R){
		return prefixMax[node];
	}
	ll mid=Mid(b,e);
	pair<ll,ll> A=prefixQueryMax(node*2,b,mid,L,R);
	pair<ll,ll> B=prefixQueryMax(node*2+1,mid+1,e,L,R);
	if(A.F>B.F){return A;}
	else{return B;}
}

pair<ll,ll> prefixQueryMin(ll node, ll b, ll e, ll L, ll R){
	if(b>R or e<L or b>e){
		return {inf,0};
	}
	if(b>=L and e<=R){
		return prefixMin[node];
	}
	ll mid=Mid(b,e);
	pair<ll,ll> A=prefixQueryMin(node*2,b,mid,L,R);
	pair<ll,ll> B=prefixQueryMin(node*2+1,mid+1,e,L,R);
	if(A.F<B.F){return A;}
	else{return B;}
}

pair<ll,ll> suffixQueryMax(ll node, ll b, ll e, ll L, ll R){
	if(b>R or e<L or b>e){
		return {-inf,0};
	}
	if(b>=L and e<=R){
		return suffixMax[node];
	}
	ll mid=Mid(b,e);
	pair<ll,ll> A=suffixQueryMax(node*2,b,mid,L,R);
	pair<ll,ll> B=suffixQueryMax(node*2+1,mid+1,e,L,R);
	if(A.F>B.F){return A;}
	else{return B;}
}

pair<ll,ll> suffixQueryMin(ll node, ll b, ll e, ll L, ll R){
	if(b>R or e<L or b>e){
		return {inf,0};
	}
	if(b>=L and e<=R){
		return suffixMin[node];
	}
	ll mid=Mid(b,e);
	pair<ll,ll> A=suffixQueryMin(node*2,b,mid,L,R);
	pair<ll,ll> B=suffixQueryMin(node*2+1,mid+1,e,L,R);
	if(A.F<B.F){return A;}
	else{return B;}
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n; 
		cin>>n;
		vector<ll>v(n+5);
		for(ll i=1; i<=n; i++){
			cin>>v[i];
			prefixSum[i]=prefixSum[i-1]+v[i];
		}
		for(ll i=n; i>=1; i--){
			suffixSum[i]=suffixSum[i+1]+v[i];
		}
		build(1,1,n);
		ll q;
		cin>>q;
		while(q--){
			ll L,R;
			cin>>L>>R;
			pair<ll,ll> prefix_max=prefixQueryMax(1,1,n,L,R);
			pair<ll,ll> prefix_min=prefixQueryMin(1,1,n,L,R);
			pair<ll,ll> suffix_max=suffixQueryMax(1,1,n,L,R);
			pair<ll,ll> suffix_min=suffixQueryMin(1,1,n,L,R);
			ll dif=abs((prefix_max.F-prefixSum[L-1])-(suffix_min.F-suffixSum[R+1]));
			ll dif2=abs((prefix_min.F-prefixSum[L-1])-(suffix_max.F-suffixSum[R+1]));
			if(dif>dif2){
				cout<<prefix_max.S<<" "<<suffix_min.S<<"\n";
			}
			else{
				cout<<prefix_min.S<<" "<<suffix_max.S<<"\n";
			}
		}
		for(ll i=0; i<=n; i++){
			prefixSum[i]=suffixSum[i]=0;
		}
	}
	return 0;
}



