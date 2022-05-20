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

class query{
public:
	ll L,R,ID;
}Q[N];

const ll k=350;
ll ans;
vector<ll>v(N),res(N);
unordered_map<ll,ll>cnt;
unordered_map<ll,bool>mark;

bool cmp(query &a, query &b){
	ll block_a=a.L/k,block_b=b.L/k;
	if(block_a==block_b){return a.R<b.R;}
	return block_a<block_b;
}

void add(ll idx){
	cnt[v[idx]]++;
	if(cnt[v[idx]]==v[idx]){
		ans++; mark[v[idx]]=1;
	}
	if(cnt[v[idx]]!=v[idx] and mark[v[idx]]==1){
		ans--, mark[v[idx]]=0;
	}
}

void remove(ll idx){
	cnt[v[idx]]--;
	if(cnt[v[idx]]==v[idx]){
		ans++, mark[v[idx]]=1;
	}
	if(cnt[v[idx]]!=v[idx] and mark[v[idx]]==1){
		ans--, mark[v[idx]]=0;
	}
}

void solve(ll n, ll q){
	sort(Q,Q+q,cmp);
	ll currL=0,currR=-1;
	for(ll i=0; i<q; i++){
		while(currL>Q[i].L){
			add(--currL);
		}
		while(currR<Q[i].R){
			add(++currR);
		}
		while(currL<Q[i].L){
			remove(currL++);
		}
		while(currR>Q[i].R){
			remove(currR--);
		}
		res[Q[i].ID]=ans;
	}
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n,q; cin>>n>>q;
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		for(ll i=0; i<q; i++){
			cin>>Q[i].L>>Q[i].R;
			Q[i].L--, Q[i].R--;		//Makes 0-based from 1-based indexing
			Q[i].ID=i;
		}
		solve(n,q);
		for(ll i=0; i<q; i++){
			cout<<res[i]<<"\n";
		}
	}
	return 0;
}



