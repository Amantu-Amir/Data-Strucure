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

const ll p=29;
const ll N=2e5+50;
const ll mod=1e9+7;

class info{
public:
	ll val,taken;
};

ll curr_val;
vector<info>tree(N*3);

void update(ll node, ll b, ll e, ll v, ll idx){
	if(b==e){
		tree[node].val=v;
		return;
	}
	ll mid=(b+e)/2;
	if(idx<=mid){
		update(node*2,b,mid,v,idx);
	}
	else{
		update(node*2+1,mid+1,e,v,idx);
	}
	tree[node].taken=tree[node*2].taken+tree[node*2+1].taken;
}

void query(ll node, ll b, ll e, ll idx){
	if(b==e){
		tree[node].taken=1;
		curr_val=tree[node].val;
		return;
	}
	ll mid=(b+e)/2;
	ll tot=(mid-b+1)-tree[node*2].taken;
	if(idx<=tot){
		query(node*2,b,mid,idx);
	}
	else{
		query(node*2+1,mid+1,e,idx-tot);
	}
	tree[node].taken=tree[node*2].taken+tree[node*2+1].taken;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n,q,aa; cin>>n>>q;
		for(ll i=1; i<=n; i++){
			cin>>aa;
			update(1,1,N,aa,i);
		}
		char type; ll cnt=0;
		cout<<"Case "<<T<<":\n";
		while(q--){
			cin>>type;
			if(type=='a'){
				ll v; cin>>v; n++;
				update(1,1,N,v,n);
			}
			else{
				ll idx; cin>>idx;
				if(idx>(n-cnt)){
					cout<<"none\n"; continue;
				}
				query(1,1,N,idx);
				cout<<curr_val<<"\n";
				cnt++;
			}
		}
		for(ll i=0; i<(N*3-5); i++){
			tree[i].taken=0;
		}
	}
	return 0;
}

