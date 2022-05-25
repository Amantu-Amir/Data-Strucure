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
const ll N=1e5+50;
const ll mod=1e9+7;

ll table[22][N],logs[N];
void build(vector<ll>&v,ll n){
	logs[1]=0;
	for(ll i=2; i<=n; i++){
		logs[i]=logs[i/2]+1;
	}
	for(ll i=0; i<=logs[n]; i++){
		ll currLen=1<<i;
		for(ll j=0; (j+currLen)<=n; j++){
			if(currLen==1){
				table[i][j]=v[j];
			}
			else{
				table[i][j]=max(table[i-1][j], table[i-1][j+currLen/2]);
			}
		}
	}
}

ll getMax(ll L,ll R){
	ll p=logs[R-L+1];
	ll pLen=1<<p;
	return max(table[p][L], table[p][R-pLen+1]);
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n,q;
		cin>>n>>q;
		vector<ll>v(n);
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		build(v,n);
		ll res=0;
		while(q--){
			ll A,B,curr;
			cin>>A>>B;
			if(A==B){
				res++;
				continue;
			}
			A--, B-=2;		//R-=2 becasue 1 for 0-base index and another for ignore the B city;
			curr=v[A];
			if(A>B){swap(A,B);}
			if(A==B){
				res++;
				continue;
			}
			if(curr>=getMax(A,B)){
				res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}



