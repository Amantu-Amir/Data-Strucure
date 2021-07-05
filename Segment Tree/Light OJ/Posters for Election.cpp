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
const ll N=3e5+50;
const ll mod=1e9+7;

set<ll>st;
vector<ll>tree(N*3);

void propagate(ll node, ll b, ll e){
	if(b!=e){
		tree[node*2]=tree[node*2+1]=tree[node];
		tree[node]=0;
	}
}

void update(ll node, ll b, ll e, ll L, ll R, ll idx){
	if(tree[node]>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return;
	}
	if(b>=L and e<=R){
		tree[node]=idx;
		propagate(node,b,e);
		return;
	}
	ll mid=(b+e)/2;
	update(node*2,b,mid,L,R,idx);
	update(node*2+1,mid+1,e,L,R,idx);
}

void query(ll node, ll b, ll e){
	if(tree[node]>0){
		propagate(node,b,e);
	}
	if(b==e){
		if(tree[node]>0){
			st.insert(tree[node]);
		}
		return;
	}
	ll mid=(b+e)/2;
	query(node*2,b,mid);
	query(node*2+1,mid+1,e);
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n,l,r; cin>>n;
		ll nn=n*2,idx=1;
		for(ll i=0; i<n; i++){
			cin>>l>>r;
			update(1,1,nn,l,r,idx);
			idx++;
		}
		query(1,1,nn);
		cout<<"Case "<<T<<": "<<st.size()<<"\n";
		st.clear();
		for(ll i=0; i<(N*3-5); i++){
			tree[i]=0;
		}
	}
	return 0;
}

