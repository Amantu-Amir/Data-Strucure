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
void compute_pow(){
	p_pow[0]=1;
	for(ll i=1; i<(N-5); i++){
		p_pow[i]=(p_pow[i-1]*p)%mod;
	}
}

vector<ll>compute_hash(string str){
	ll len=str.size();
	vector<ll>hash_table(len+1);
	hash_table[0]=0;
	for(ll i=0; i<len; i++){
		hash_table[i+1]=((hash_table[i]*p)%mod+(str[i]-'a'+1))%mod;
	}
	return hash_table;
}


ll find_lps(vector<ll>v, vector<ll>A, vector<ll>B, ll len){
	ll res=1;
	ll L=0,R=v.size()-1;
	while(L<=R){
		ll mid=Mid(L,R),ok=0;
		ll curr_len=v[mid];
		for(ll i=0; i<=(len-curr_len); i++){
			ll left=(A[curr_len+i]-(A[i]*p_pow[curr_len])%mod+mod)%mod;
			ll right=(B[len-i]-(B[len-i-curr_len]*p_pow[curr_len])%mod+mod)%mod;
			if(left==right){
				ok=1; break;
			}
		}
		if(ok==1){
			res=curr_len;
			L=mid+1;
		}
		else{
			R=mid-1;
		}
	}
	return res;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	compute_pow();

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		string str;
		cin>>str;
		ll len=str.size();
		vector<ll>A=compute_hash(str);
		reverse(all(str));
		vector<ll>B=compute_hash(str);
		vector<ll>odd,even;
		for(ll i=1; i<=len; i+=2){
			odd.pb(i);
		}
		for(ll i=2; i<=len; i+=2){
			even.pb(i);
		}
		ll res=find_lps(odd,A,B,len);
		res=max(res,find_lps(even,A,B,len));
		cout<<res<<"\n";
	}
	return 0;
}



