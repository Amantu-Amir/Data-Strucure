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

ll tot_hash=2;
ll base[]={29,31};
ll MOD[]={1000000007,1000000009};
ll p_pow[N][2];
ll hash_table[N][2];

void compute_base(){
	p_pow[0][0]=1;
	p_pow[0][1]=1;
	for(ll i=1; i<(N-5); i++){
		for(ll j=0; j<tot_hash; j++){
			p_pow[i][j]=(p_pow[i-1][j]*base[j])%MOD[j];
		}
	}
}

void compute_hash(string str){
	ll len=str.size();
	hash_table[1][0]=str[0]-'a'+1;
	hash_table[1][1]=str[0]-'a'+1;
	for(ll i=2; i<=len; i++){
		for(ll j=0; j<tot_hash; j++){
			hash_table[i][j]=((hash_table[i-1][j]*base[j])%MOD[j]+(str[i-1]-'a'+1))%MOD[j];
		}
	}
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	compute_base();
	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n,k; 
		cin>>n>>k;
		string str;
		cin>>str;
		compute_hash(str);
		ll curr_hash[tot_hash],res=0;
		set<pair<ll,ll>>st;
		for(ll i=0; i<=(n-k); i++){
			for(ll j=0; j<tot_hash; j++){
				if(i==0){
					curr_hash[j]=hash_table[k][j];
				}
				else{
					curr_hash[j]=(hash_table[i+k][j]-(hash_table[i][j]*p_pow[k][j])%MOD[j]+MOD[j])%MOD[j];
				}
			}
			st.insert({curr_hash[0],curr_hash[1]});
		}
		cout<<st.size()<<"\n";
	}
	return 0;
}



