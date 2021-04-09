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
vector<ll>hash_table(N);

void rolling_hash(string str){
	ll len=str.size();
	hash_table[0]=str[0]-'a'+1;
	for(ll i=1; i<len; i++){
		hash_table[i]=((hash_table[i-1]*p)%mod+(str[i]-'a'+1))%mod;
	}
}

ll compute_hash(string str){
	ll len=str.size();
	reverse(all(str));
	ll hash_val=0;
	for(ll i=0; i<len; i++){
		hash_val=(hash_val+((str[i]-'a'+1)*p_pow[i])%mod)%mod;
	}
	return hash_val;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	p_pow[0]=1;
	for(ll i=1; i<(N-5); i++){
		p_pow[i]=(p_pow[i-1]*p)%mod;
	}

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n;
		while(cin>>n){
			string pat,text;
			cin>>pat>>text;
			rolling_hash(text);
			ll text_len = text.size(),curr_hash;
			ll pat_len = pat.size(),ok=0;
			ll hash_val = compute_hash(pat);
			for(ll i=0; i<=(text_len-pat_len); i++){
				if(i==0){
					curr_hash=hash_table[i+pat_len-1];
				}
				else{
					curr_hash=(hash_table[i+pat_len-1]-(hash_table[i-1]*p_pow[pat_len])%mod+mod)%mod;
				}
				//cout<<i<<" "<<curr_hash<<" "<<hash_val<<"\n";
				if(curr_hash==hash_val){
					ok=1;
					cout<<i<<"\n";
				}
			}
			if(ok==0){
				cout<<"\n";
			}
		}
	}
	return 0;
}

