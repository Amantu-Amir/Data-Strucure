#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define Mid(b,e) b+(e-b)/2
#define all(v) v.begin(),v.end()
#define inf 2147483647

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
const ll N=2e5+50;
const ll mod=1e9+7;

class Data{
public:
	ll sum,lazy;
}tree[N*3];
vector<ll>A(N);

void build(ll node, ll b, ll e){
	if(b==e){
		tree[node].sum=A[b];
		return;
	}
	ll mid=Mid(b,e);
	build(node*2,b,mid);
	build(node*2+1,mid+1,e);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%mod;
}


void propagate(ll node, ll b, ll e){
	tree[node].sum=(tree[node].sum+((e-b+1)*tree[node].lazy)%mod)%mod;
	if(b!=e){
		tree[node*2].lazy=(tree[node*2].lazy+tree[node].lazy)%mod;
		tree[node*2+1].lazy=(tree[node*2+1].lazy+tree[node].lazy)%mod;
	}
	tree[node].lazy=0;
}


ll query(ll node, ll b, ll e, ll L, ll R){
	if(tree[node].lazy>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return 0;
	}
	if(b>=L and e<=R){
		return tree[node].sum;
	}
	ll mid=Mid(b,e);
	ll q1=query(node*2,b,mid,L,R);
	ll q2=query(node*2+1,mid+1,e,L,R);
	return (q1+q2)%mod;
}

ll bin_pow(ll b,ll p){
	if(p==-1){			
		p=mod-2;
	}
	ll ret=1;
	while(p>0){
		if(p&1){
			ret=(ret*b)%mod;
		}
		p/=2;
		b=(b*b)%mod;
	}
	return ret;
}


void update(ll node, ll b, ll e, ll L, ll R, ll ssa, ll k){
	if(tree[node].lazy>0){
		propagate(node,b,e);
	}
	if(b>R or e<L or b>e){
		return;
	}
	if(b>=L and e<=R){
		ll tot_node=(R-L+1)+1;
		ll up=abs((1-bin_pow(tot_node,k)));
		ll down=abs(1-tot_node);
		ll tot=(up*bin_pow(down,-1))%mod;
		tree[node].lazy=(ssa*tot)%mod;
		propagate(node,b,e);
		return;
	}
	ll mid=Mid(b,e);
	update(node*2,b,mid,L,R,ssa,k);
	update(node*2+1,mid+1,e,L,R,ssa,k);
	tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%mod;
}


void put_down(ll node, ll b, ll e){
	if(tree[node].lazy>0){
		propagate(node,b,e);
	}
	if(b==e){
		A[b]=tree[node].sum;
		return;
	}
	ll mid=Mid(b,e);
	put_down(node*2,b,mid);
	put_down(node*2+1,mid+1,e);
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		for(ll i=1; i<=n; i++){
			cin>>A[i];
		}
		build(1,1,n);
		ll q; cin>>q;
		while(q--){
			ll L,R,k;
			cin>>L>>R>>k;
			ll ssa=query(1,1,n,L,R);
			update(1,1,n,L,R,ssa,k);
		}
		put_down(1,1,n);
		for(ll i=1; i<=n; i++){
			cout<<A[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

