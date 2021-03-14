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

ll curr=1;
ll water;
bool vis[N];
vector<ll>G[N];
ll start[N],finish[N];

class Data{
public:
	ll drop,lazy;
};
vector<Data>tree(N*3);

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


void propagate(ll node, ll b, ll e){
	if(b!=e){
		ll mid=(b+e)/2;
		ll left=mid-b+1;
		ll right=e-(mid+1)+1;
		ll bame_lagbe=left-(tree[node*2].drop+tree[node*2].lazy);
		if(bame_lagbe>=tree[node].lazy){
			tree[node*2].lazy+=tree[node].lazy;
		}
		else{
			tree[node*2].lazy+=bame_lagbe;
			ll dane_lagbe=right-(tree[node*2+1].drop+tree[node*2+1].lazy);
			tree[node*2+1].lazy+=min(dane_lagbe,tree[node].lazy-bame_lagbe);
		}
		ll tot=(e-b+1)-tree[node].drop;
		tree[node].drop+=min(tot,tree[node].lazy);
	}
	else{
		tree[node].drop=1;
	}
	tree[node].lazy=0;
}


void update(ll node, ll b, ll e, ll L, ll R){
	if(tree[node].lazy>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return;
	}
	if(b>=L and e<=R){
		ll lagbe=(e-b+1)-tree[node].drop;
		if(lagbe>=water){
			tree[node].lazy=water;
			water=0;
		}
		else{
			tree[node].lazy=lagbe;
			water-=lagbe;
		}
		if(tree[node].lazy>0){
			propagate(node,b,e);
		}
		return;
	}
	ll mid=(b+e)/2;
	update(node*2,b,mid,L,R);
	update(node*2+1,mid+1,e,L,R);
	tree[node].drop=(tree[node*2].drop+tree[node*2+1].drop);
	//cout<<node<<" "<<tree[node].drop<<"\n";
}


ll query(ll node, ll b, ll e, ll L, ll R){
	if(tree[node].lazy>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return 0;
	}
	if(b>=L and e<=R){
		return tree[node].drop;
	}
	ll mid=(b+e)/2;
	ll q1=query(node*2,b,mid,L,R);
	ll q2=query(node*2+1,mid+1,e,L,R);
	return q1+q2;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		curr=1;
		for(ll i=0; i<(N*3)-5; i++){
			tree[i].drop=tree[i].lazy=0;
		}
		for(ll i=0; i<(N-5); i++){
			G[i].clear();
			vis[i]=0;
		}
		ll node; cin>>node;
		ll u,v;
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
		ll type;
		cout<<"Case "<<T<<":\n";
		while(Q--){
			cin>>type;
			if(type==1){
				ll ver; cin>>ver>>water;
				update(1,1,node,start[ver],finish[ver]);
			}
			else{
				ll ver; cin>>ver;
				ll res=query(1,1,node,start[ver],finish[ver]);
				ll tot=finish[ver]-start[ver]+1;
				if(res==tot){
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

