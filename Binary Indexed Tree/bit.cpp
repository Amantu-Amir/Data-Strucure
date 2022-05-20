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
const ll N=2e6+50;
const ll mod=1e9+7;

ll n;
vector<ll>tree(N);

void update(ll idx,ll val){
	while(idx<=n){
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

ll query(ll idx){
	ll sum=0;
	while(idx>0){
		sum+=tree[idx];
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
		vector<ll>v(n+5);
		for(ll i=1; i<=n; i++){
			cin>>v[i];
			update(i,v[i]);
		}
		ll q; 
		cin>>q;
		while(q--){
			ll type;
			cin>>type;
			if(type==1){
				ll idx,val;
				cin>>idx>>val;
				update(idx,val);	//add val in index idx
			}
			else{
				ll L,R; 
				cin>>L>>R;
				ll ans=query(R)-query(L-1);
				cout<<ans<<"\n";
			}
			
		}
	}
	return 0;
}



