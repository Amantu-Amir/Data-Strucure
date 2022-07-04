#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 2147483647
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
const ll N=5e6+50;
const ll mod=1e9+7;

ll rep[N];

ll Find(ll r){
    if(rep[r]==r){
        return r;
    }
    return rep[r]=Find(rep[r]);
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	//https://www.hackerrank.com/contests/intra-department-coding-contest-csebu-2022-1/challenges/help-to-arrange-the-contest

	ll t=1;
	for(ll T=1; T<=t; T++){
        ll n;
        cin>>n;
        vector<ll>v(n+1);
        for(ll i=1; i<=n; i++){
            cin>>v[i];
        }
        for(ll i=1; i<=n; i++){
            rep[i]=i;
        }
        ll q;
        cin>>q;
        while(q--){
            ll type;
            cin>>type;
            if(type==1){
                ll idx,val;
                cin>>idx>>val;
                while(val>0){
                    idx=Find(idx);
                    ll Min=min(v[idx], val);
                    val-=Min;
                    v[idx]-=Min;
                    if(idx==n){
                        break;
                    }
                    if(v[idx]==0){
                        rep[idx]=Find(idx+1);
                        idx=rep[idx];
                    }
                }
            }
            else{
                ll idx;
                cin>>idx;
                cout<<v[idx]<<"\n";
            }
        }
	}
	return 0;
}








