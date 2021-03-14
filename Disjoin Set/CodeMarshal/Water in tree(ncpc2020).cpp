#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prln(a) cout<<a<<"\n"
#define nl cout<<"\n"
#define P(a) cout<<a
#define PP(a,b) cout<<a<<" "<<b
#define PPP(a,b,c) cout<<a<<" "<<b<<" "<<c
#define inf 2147483647

//---------------------------------------------------------------------------//

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
const ll N=1e5+50;
const ll mod=1e9+7;


bool vis[N];
vector<ll>G[N];
ll curr=1,rep[N];
ll start[N],finish[N];

void dfs(ll root){
	vis[root]=1;
	start[root]=curr;
	for(auto child:G[root]){
		if(vis[child]==0){
			dfs(child);
		}
	}
	finish[root]=curr++;
}

void init(){
	for(ll i=0; i<(N-5); i++){
		rep[i]=i;
	}
}

ll find_rep(ll r){
	if(r==rep[r]){return r;}
	return rep[r]=find_rep(rep[r]);
}

void solve(ll L, ll R, ll water){
	while(L<=R and water>0){
		if(L==find_rep(L)){
			//cout<<rep[L]<<" "<<L+1<<"\n";
			rep[L]=L+1;
			water--;L++;
		}
		else{
			L=rep[L];
		}
	}
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		init(); curr=1;
		for(ll i=0; i<(N-5); i++){
			vis[i]=0; G[i].clear();
		}
		ll node,u,v; cin>>node;
		for(ll i=0; i<(node-1); i++){
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
		}
		for(ll i=1; i<=node; i++){
			sort(all(G[i]));
		}
		dfs(1);
		ll Q; cin>>Q;
		cout<<"Case "<<T<<":\n";
		while(Q--){
			ll type; cin>>type;
			if(type==1){
				ll u,water; cin>>u>>water;
				ll L=start[u],R=finish[u];
				solve(L,R,water);
			}
			else{
				ll u; cin>>u;
				if(rep[finish[u]]!=finish[u]){
					cout<<"1\n";
				}
				else{
					cout<<"0\n";
				}
			}
		}
	}
	return 0;
}

