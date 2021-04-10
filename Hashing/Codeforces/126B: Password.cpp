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

void compute_hash(string str){
	ll len=str.size();
	hash_table[0]=str[0]-'a'+1;
	for(ll i=1; i<len; i++){
		hash_table[i]=((hash_table[i-1]*p)%mod+(str[i]-'a'+1))%mod;
	}
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
		string str;
		cin>>str;
		ll len=str.size();
		compute_hash(str);
		ll left,right,idx,ok=0;
		for(ll i=0; i<(len-1); i++){
			left=hash_table[i];
			ll temp=len-(i+1);
			right=(hash_table[len-1]-(hash_table[temp-1]*p_pow[i+1])%mod+mod)%mod;
			if(left==right){
				for(ll j=1; j<(len-i-1); j++){
					ll curr_hash=(hash_table[j+i]-(hash_table[j-1]*p_pow[i+1])%mod+mod)%mod;
					if(curr_hash==left){
						idx=i; ok=1; 
						break;
					}
				}
			}
		}
		if(ok==1){
			for(ll i=0; i<=idx; i++){
				cout<<str[i];
			}
			cout<<"\n";
		}
		else{
			cout<<"Just a legend\n";
		}
	}
	return 0;
}


//aaaaaaaaaa
