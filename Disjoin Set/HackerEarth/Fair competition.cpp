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

ll rep[N];
void init(ll n){
	for(ll i=1; i<=n; i++){
		rep[i]=i;
	}
}


ll find_rep(ll r){
	if(rep[r]==r){return r;}
	return rep[r]=find_rep(rep[r]);
}

void join_node(ll u, ll v){
	u=find_rep(u);
	v=find_rep(v);
	if(u!=v){
		rep[v]=u;
	}
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n,m; 
		cin>>n>>m;
		init(n);
		ll u,v;
		for(ll i=1; i<=m; i++){
			cin>>u>>v;
			join_node(u,v);
		}
		set<ll>comp;
		unordered_map<ll,ll>comp_size;
		for(ll i=1; i<=n; i++){
			ll par=find_rep(i);
			comp.insert(par);
			comp_size[par]++;
		}
		ll res=0;
		for(auto it:comp){
			n-=comp_size[it];
			res+=(n*comp_size[it])*2;
		}
		cout<<res<<"\n";
	}
	return 0;
}

