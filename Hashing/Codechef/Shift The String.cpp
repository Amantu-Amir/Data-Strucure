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
const ll N=2e6+50;
const ll mod=1e9+7;

vector<ll>p_pow(N);
vector<ll>compute_hash(string str){
	ll len=str.size();
	vector<ll>hash_table(len);
	hash_table[1]=str[0]-'a'+1;
	for(ll i=2; i<len; i++){
		hash_table[i]=((hash_table[i-1]*p)%mod+(str[i-1]-'a'+1))%mod;
	}
	return hash_table;
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	p_pow[0]=1;
	for(ll i=1; i<(N-5); i++){
		p_pow[i]=(p_pow[i-1]*p)%mod;
	}

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		string a,b;
		cin>>a>>b;
		b+=b;
		vector<ll>A=compute_hash(a);
		vector<ll>B=compute_hash(b);
		ll L=0,R=n,res=0,idx=0;
		while(L<=R){
			ll mid=(L+R)/2;
			ll hash_pat=A[mid];
			bool ok=false;
			for(ll i=0; i<n; i++){
				ll hash_text;
				if(i==0){
					hash_text=B[mid];
				}
				else{
					hash_text=(B[i+mid]-(B[i]*p_pow[mid])%mod+mod)%mod;
				}
				if(hash_pat==hash_text){
					idx=i; ok=true; break;
				}
			}
			if(ok==true){
				res=idx;
				L=mid+1;
			}
			else{
				R=mid-1;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}

