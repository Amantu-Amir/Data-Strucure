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

ll rep[N],ok[N];
vector<ll>G[N];
void init(){
	for(ll i=0; i<=(N-5); i++){
		G[i].clear();
		rep[i]=i; ok[i]=0;
	}
}

ll find_rep(ll r){
	if(r==rep[r]){return r;}
	return rep[r]=find_rep(rep[r]);
}

void join_node(ll u, ll v){
	u=find_rep(u);
	v=find_rep(v);
	if(u!=v){
		ll temp,par;
		if(G[v].size()<=G[u].size()){
			rep[v]=u;
			temp=v; par=u;
		}
		else{
			rep[u]=v;
			temp=u; par=v;
		}
		ok[par]=0;
		rep[temp]=par;
		for(auto aa:G[temp]){
			G[par].pb(aa);
		}
		G[temp].clear();
	}
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		init();
		ll n,Q; cin>>n>>Q;
		cout<<"Case "<<T<<":\n";
		while(Q--){
			ll type; cin>>type;
			if(type==0){
				ll u,v; cin>>u>>v;
				join_node(u,v);
			}
			else if(type==1){
				ll u,tt; cin>>u>>tt;
				u=find_rep(u);
				G[u].pb(tt);
				ok[u]=0;
			}
			else{
				ll u,l,r; 
				cin>>u>>l>>r;
				u=find_rep(u);
				if(ok[u]==0){
					sort(all(G[u]));
					ok[u]=1;
				}
				ll res=upper_bound(all(G[u]),r)-lower_bound(all(G[u]),l);
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}

