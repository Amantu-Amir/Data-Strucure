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

class Data{
public:
	ll sum,lazy;
};

vector<Data>tree(N*3);

void propagate(ll b, ll e, ll node){
	tree[node].sum=(e-b+1)*tree[node].lazy;
	if(b!=e){
		tree[node*2].lazy=tree[node].lazy;
		tree[node*2+1].lazy=tree[node].lazy;
	}
	tree[node].lazy=-1;
}

void update(ll node, ll b, ll e, ll L, ll R, ll v){
	if(tree[node].lazy>=0){
		propagate(b,e,node);
	}
	if(b>R or e<L or b>e){
		return;
	}
	if(b>=L and e<=R){
		tree[node].lazy=v;
		propagate(b,e,node);
		return;
	}
	ll mid=(b+e)/2;
	update(node*2,b,mid,L,R,v);
	update(node*2+1,mid+1,e,L,R,v);
	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
}

ll query(ll node, ll b, ll e, ll L, ll R){
	if(tree[node].lazy>=0){
		propagate(b,e,node);
	}
	if(b>R or e<L or b>e){
		return 0;
	}
	if(b>=L and e<=R){
		return tree[node].sum;
	}
	ll mid=(b+e)/2;
	return query(node*2,b,mid,L,R)+query(node*2+1,mid+1,e,L,R);
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		for(ll i=0; i<(N*3-5); i++){
			tree[i].sum=0,tree[i].lazy=-1;
		}
		ll n,q; cin>>n>>q;
		cout<<"Case "<<T<<":\n";
		while(q--){
			ll type,l,r,v;
			cin>>type;
			if(type==1){
				cin>>l>>r>>v;
				update(1,1,n,l+1,r+1,v);
			}
			else{
				cin>>l>>r;
				ll get_sum=query(1,1,n,l+1,r+1);
				ll tot=r-l+1;
				if(get_sum%tot==0){
					cout<<get_sum/tot<<"\n";
				}
				else{
					ll g=__gcd(get_sum,tot);
					cout<<get_sum/g<<"/"<<tot/g<<"\n";
				}
			}
		}
	}
	return 0;
}

