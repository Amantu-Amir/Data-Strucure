#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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
typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const ll P=29;
const ll N=3e5+50;
const ll mod=1e9+7;

vector<ll> bit(N);

void update(ll idx, ll val, ll n){
	while(idx<=n){
		bit[idx]+=val;
		idx+=(idx&-idx);
	}
}

ll query(ll idx){
	ll sum=0;
	while(idx>0){
		sum+=bit[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	cin>>t;
	for(ll T=1; T<=t; T++){
		ll n, q;
		cin>>n>>q;
		for(ll i=1; i<=n; i++){
			bit[i]=0;
		}
		ll idx;
		unordered_map<ll,ll> cnt;
		for(ll i=1; i<=n; i++){
			cin>>idx;
			cnt[idx]++;
			update(idx, 1, n);
		}
		while(q--){
			ll type;
			cin>>type;
			if(type==1){
				ll u, v;
				cin>>u>>v;
				if(u==v){
					continue;
				}
				cnt[v]+=cnt[u];
				update(u, -cnt[u], n);
				update(v, cnt[u], n);
				cnt[u]=0;
			}
			else if(type==2){
				ll u, x;
				cin>>u>>x;
				cnt[u]+=x;
				update(u, x, n);
			}
			else{
				ll k;
				cin>>k;
				ll L=1, R=n, ans=-1;
				while(L<=R){
					ll mid=L+(R-L)/2;
					ll get=query(mid);
					if(get>=k) ans=mid, R=mid-1;
					else L=mid+1;
				}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}




