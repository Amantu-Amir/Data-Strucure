#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e6;

int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	while(t--){
		ll n,m; cin>>n>>m;
		string s[n+5];
		for(ll i=0; i<n; i++){
			cin>>s[i];
		}
		ll dp[n+5][n+5];
		for(ll i=0; i<=n; i++){
			dp[0][i]=0;
			dp[i][0]=0;
		}
		ll cnt=0;
		for(ll i=1; i<=n; i++){
			for(ll j=1; j<=n; j++){
				cnt=0;
				if(s[i-1][j-1]=='*'){
					cnt=1;
				}
				dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+cnt;
			}
		}
		ll x1,y1,x2,y2;
		while(m--){
			cin>>x1>>y1>>x2>>y2;
			ll ans=dp[x2][y2];
			ans-=dp[x1-1][y2];
			ans-=dp[x2][y1-1];
			ans+=dp[x1-1][y1-1];
			cout<<ans<<"\n";
		}
	}

	return 0;
}



