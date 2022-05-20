#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
//typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pbds; 
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>pbds; 

//------------------------------------------------------------------------------//


const ll P=29;
const ll N=2e6+50;
const ll mod=1e9+7;

//1 4 2 8 1
//1 2 3 4 5 6 7 8 9 10
//2 1 0 1 0 0 0 1 0 0

ll n;
vector<ll>Tree(N);
void update(ll idx,ll val){
	while(idx<=n){
		Tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

ll getSum(ll idx){
	ll sum=0;
	while(idx>0){
		sum+=Tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		cin>>n;
		vector<ll>v(n);			//If the values of the array will be too large (10^9) then mapping these values
		ll cntInv=0,R=0;
		for(ll i=0; i<n; i++){
			cin>>v[i];
			R=max(R,v[i]);
			ll A=getSum(R),B=getSum(v[i]);
			cntInv+=(A-B);
			update(v[i],1);
		}
		cout<<cntInv<<"\n";
	}
	return 0;
}



