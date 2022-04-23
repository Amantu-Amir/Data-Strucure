#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18;
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
const ll N=2e3+50;
const ll mod=1e9+7;

ll segment_size;
vector<ll>segment[N],v(N);
void preprocess(ll n){
	segment_size=sqrt(n);
	ll current_segment=-1;
	for(ll i=0; i<n; i++){
		if(i%segment_size==0){
			if(current_segment!=-1){
				sort(all(segment[current_segment]));
			}
			current_segment++;
		}
		segment[current_segment].pb(v[i]);
	}
}

ll query(ll L,ll R,ll val){
	ll res=0;
	while(L<R and L%segment_size!=0){
		if(v[L]<=val){res++;}
		L++;
	}
	while((L+segment_size)<=R){
		ll segment_no=L/segment_size;
		ll idx=upper_bound(all(segment[segment_no]),val)-segment[segment_no].begin();
		res+=idx; L+=segment_size;
	}
	while(L<=R){
		if(v[L]<=val){res++;}
		L++;
	}
	return res;
}

void update(ll idx,ll val){
	ll segment_no=idx/segment_size;
	ll index=lower_bound(all(segment[segment_no]),v[idx])-segment[segment_no].begin();
	segment[segment_no][index]=inf;
	segment[segment_no].pb(val);
	sort(all(segment[segment_no]));
	v[idx]=val;
}


int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n,q;
		cin>>n>>q;
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		preprocess(n);
		while(q--){
			char type;
			cin>>type;
			if(type=='C'){
				ll L,R,val;
				cin>>L>>R>>val;
				cout<<query(L-1,R-1,val)<<"\n";
			}
			else{
				ll idx,val;
				cin>>idx>>val;
				update(idx-1,val);
			}
		}
	}
	return 0;
}



