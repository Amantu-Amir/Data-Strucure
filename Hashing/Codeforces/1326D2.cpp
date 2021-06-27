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
ll tot_hash=2;
ll base[]={61,71};
ll MOD[]={1000000007,1000000009};
ll p_pow[N][2];
ll A[N][2],B[N][2];

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
	A[1][0]=str[0]-'a'+1;
	A[1][1]=str[0]-'a'+1;
	for(ll i=2; i<=len; i++){
		for(ll j=0; j<tot_hash; j++){
			A[i][j]=((A[i-1][j]*base[j])%MOD[j]+(str[i-1]-'a'+1))%MOD[j];
		}
	}
	reverse(all(str));
	B[1][0]=str[0]-'a'+1;
	B[1][1]=str[0]-'a'+1;
	for(ll i=2; i<=len; i++){
		for(ll j=0; j<tot_hash; j++){
			B[i][j]=((B[i-1][j]*base[j])%MOD[j]+(str[i-1]-'a'+1))%MOD[j];
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
		string str;
		cin>>str;
		ll len=str.size();
		compute_hash(str);
		ll idx=0;
		for(ll i=1; i<=len; i++){
			if(A[i][0]==B[i][0] and A[i][1]==B[i][1]){
				idx++;
			}
			else{
				break;
			}
		}
		if(len==1 or idx==len){
			cout<<str<<"\n";
			continue;
		}
		ll left_idx=idx;
		ll curr_len=len-idx;
		while(idx<=curr_len){
			ll left[2],right[2];
			for(ll i=0; i<2; i++){
				left[i]=(A[curr_len][i]-(A[idx][i]*p_pow[curr_len-idx][i])%MOD[i]+MOD[i])%MOD[i];
				right[i]=(B[len-idx][i]-(B[len-curr_len][i]*p_pow[curr_len-idx][i])%MOD[i]+MOD[i])%MOD[i];
			}
			bool ok=true;
			for(ll i=0; i<2; i++){
				if(left[i]!=right[i]){
					ok=false;
				}
			}
			if(ok==true){
				left_idx=curr_len;
				break;
			}
			curr_len--;
		}
		ll right_idx=idx;
		curr_len=len-idx;
		while(idx<=curr_len){
			ll left[2],right[2];
			for(ll i=0; i<2; i++){
				left[i]=(B[curr_len][i]-(B[idx][i]*p_pow[curr_len-idx][i])%MOD[i]+MOD[i])%MOD[i];
				right[i]=(A[len-idx][i]-(A[len-curr_len][i]*p_pow[curr_len-idx][i])%MOD[i]+MOD[i])%MOD[i];
				//cout<<left[i]<<" "<<right[i]<<"\n";
			}
			bool ok=true;
			for(ll i=0; i<2; i++){
				if(left[i]!=right[i]){
					ok=false;
				}
			}
			if(ok==true){
				right_idx=curr_len;
				break;
			}
			curr_len--;
		}
		//cout<<left_idx<<" "<<right_idx<<"\n";
		string res;
		if(left_idx>=right_idx){
			string temp=str.substr(0,idx);
			res=temp;
			res+=str.substr(idx,(left_idx-idx));
			reverse(all(temp));
			res+=temp;
		}
		else{
			string temp=str.substr(0,idx);
			res=temp;
			reverse(all(str));
			res+=str.substr(idx,(right_idx-idx));
			reverse(all(temp));
			res+=temp;
		}
		cout<<res<<"\n";
	}
	return 0;
}



