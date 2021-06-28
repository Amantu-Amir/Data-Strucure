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

const ll N=2e6+50;
const ll mod=1e9+7;

ll idx;
ll base[]={73,79};
ll MOD[]={1000000007,1000000009};
ll p_pow[N][2];
ll A[N][2],B[N][2];

void F(string str){
	ll len=str.size();
	for(ll i=1; i<=len; i++){
		for(ll j=0; j<2; j++){
			if(str[i-1]>='a' and str[i-1]<='z'){
				A[idx+i][j]=((A[idx+i-1][j]*base[j])%MOD[j]+(str[i-1]-'a'+1))%MOD[j];
			}
			else if(str[i-1]>='A' and str[i-1]<='Z'){
				A[idx+i][j]=((A[idx+i-1][j]*base[j])%MOD[j]+(str[i-1]-'A'+1)+26)%MOD[j];
			}
			else{
				A[idx+i][j]=((A[idx+i-1][j]*base[j])%MOD[j]+(str[i-1]-'0'+1)+52)%MOD[j];
			}
		}
	}
	idx+=len;
}

void F2(string str){
	ll len=str.size();
	for(ll i=1; i<=len; i++){
		for(ll j=0; j<2; j++){
			if(str[i-1]>='a' and str[i-1]<='z'){
				B[i][j]=((B[i-1][j]*base[j])%MOD[j]+(str[i-1]-'a'+1))%MOD[j];
			}
			else if(str[i-1]>='A' and str[i-1]<='Z'){
				B[i][j]=((B[i-1][j]*base[j])%MOD[j]+(str[i-1]-'A'+1)+26)%MOD[j];
			}
			else{
				B[i][j]=((B[i-1][j]*base[j])%MOD[j]+(str[i-1]-'0'+1)+52)%MOD[j];
			}
		}
	}
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	p_pow[0][0]=1;
	p_pow[0][1]=1;
	for(ll i=1; i<(N-5); i++){
		for(ll j=0; j<2; j++){
			p_pow[i][j]=(p_pow[i-1][j]*base[j])%MOD[j];
		}
	}

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		string str[n+5];
		for(ll i=0; i<n; i++){
			cin>>str[i];
		}
		string res=str[0];
		F(str[0]);
		for(ll i=1; i<n; i++){
			F2(str[i]);
			ll len=str[i].size(),siz=0,curr_idx=0,ok=false;
			for(ll j=1; j<=min(idx,len); j++){
				ll aa[2];
				for(ll k=0; k<2; k++){
					aa[k]=(A[idx][k]-(A[idx-j][k]*p_pow[j][k])%MOD[k]+MOD[k])%MOD[k];
				}
				ll ck=1;
				for(ll k=0; k<2; k++){
					if(aa[k]!=B[j][k]){
						ck=0;
					}
				}
				if(ck==1){
					ok=true;
					siz=len-j,curr_idx=j;
				}
			}
			//cout<<ok<<"\n";
			string temp=str[i].substr(curr_idx,siz);
			if(ok==false){
				temp=str[i];
			}
			res+=temp;
			F(temp);
		}
		cout<<res<<"\n";
	}
	return 0;
}

