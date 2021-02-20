#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6;

ll n,logn[N];
vector<ll>v;
ll table[22][N];

void build_sparse_table(){
	logn[1]=0;
	for(ll i=2; i<=n; i++){
		logn[i]=logn[i/2]+1;
	}
	for(ll i=0; i<=logn[n]; i++){
		ll curr_len=(1<<i); //2^i
		for(ll j=0; (j+curr_len)<=n; j++){
			if(curr_len==1){
				table[i][j]=v[j];	//table[i][j],i=2^i elements,j=start pont
			}
			else{
				table[i][j]=min(table[i-1][j], table[i-1][j+(curr_len/2)]);
			}
		}
	}
}

ll get_min(ll L,ll R){
	ll p=logn[R-L+1];
	ll len=1<<p;	//2^p
	return min(table[p][L], table[p][R-len+1]);
}

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	while(t--){
		cin>>n;
		v.resize(n);		
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		build_sparse_table();
		ll q,L,R; cin>>q;
		while(q--){
			cin>>L>>R; L--,R--;
			ll res=get_min(L,R);
			cout<<res<<"\n";
		}
	}

	return 0;
}

