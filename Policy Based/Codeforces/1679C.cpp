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
typedef tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>pds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pds; 
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> pds; 

//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

void solve(){
	ll n,q;
	cin>>n>>q;
	pds row,col;
	unordered_map<ll,ll>cntRow,cntCol;
	while(q--){
		ll type;
		cin>>type;
		if(type==1){
			ll x,y;
			cin>>x>>y;
			cntRow[x]++;
			cntCol[y]++;
			row.insert(x);
			col.insert(y);
		}
		else if(type==2){
			ll x,y;
			cin>>x>>y;
			cntRow[x]--;
			cntCol[y]--;
			if(cntRow[x]==0){
				row.erase(row.find_by_order(row.order_of_key(x)));
			}
			if(cntCol[y]==0){
				col.erase(col.find_by_order(col.order_of_key(y)));
			}
		}
		else{
			ll x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			ll R=row.order_of_key(x2+1)-row.order_of_key(x1);
			ll C=col.order_of_key(y2+1)-col.order_of_key(y1);
			yesNo(R==(x2-x1+1) or C==(y2-y1+1));
		}
	}
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		solve();
	}
	return 0;
}



