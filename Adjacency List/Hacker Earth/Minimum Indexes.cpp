#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define inf 2147483647

//---------------------------------------------------------------------------//

//knight moves
//ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
//ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
//ll dx[]={1,-1,0,0};
//ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
bool isDigit(char ch){if(ch>=48 && ch<=57) return true; else return false;}
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//
const ll N=2e5+50;
const ll mod=1e9+7;


ll digit_sum(ll n){
	ll ds=0;
	while(n>0){
		ds+=n%10;
		n/=10;
	}
	return ds;
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n,q; cin>>n>>q;
		vector<ll>v(n+1);
		vector<ll>G[100];
		for(ll i=1; i<=n; i++){
			cin>>v[i];
			ll ds=digit_sum(v[i]);
			G[ds].pb(i);
		}
		ll idx;
		while(q--){
			cin>>idx;
			ll ok=0, res=inf;
			ll ds=digit_sum(v[idx]);
			for(ll i=ds-1; i>=1; i--){
				ll siz=G[i].size();
				if(siz==0){continue;}
				ll lb=lower_bound(all(G[i]),idx)-G[i].begin();
				for(ll j=lb; j<siz; j++){
					if(v[G[i][j]]>v[idx]){
						ok=1; 
						if(res>G[i][j]){
							res=G[i][j];
						}
						break;
					}
				}
			}
			if(ok==0){
				cout<<"-1\n";
			}
			else{
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}

