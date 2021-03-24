#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define inf 2147483647

//---------------------------------------------------------------------------//

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


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	bool vis[25][25];
	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n,m; cin>>n>>m;
		for(ll i=1; i<=n; i++){
			for(ll j=1; j<=m; j++){
				vis[i][j]=0;
			}
		}
		deque<ll>P,FW;
		for(ll i=1; i<=n; i++){
			P.push_back(i);
		}
		for(ll i=1; i<=m; i++){
			FW.push_back(i);
		}
		ll res=0,idx=0,ok=0;
		unordered_map<ll,ll>currStay;
		while(ok==0){
			idx=idx%m;
			if(currStay[FW[idx]]>0){
				P.push_back(currStay[FW[idx]]);
				currStay[FW[idx]]=0;
			}
			ll sz=P.size();
			for(ll i=0; i<sz; i++){
				if(vis[P[i]][FW[idx]]==0){
					currStay[FW[idx]]=P[i];
					vis[P[i]][FW[idx]]=1;
					//auto it=P.begin()+i;
					//cout<<*it<<"\n";
					P.erase(P.begin()+i);
					break;
				}
			}
			sz=P.size();
			for(ll i=0; i<sz; i++){
				ll ck=1;
				for(ll j=1; j<=m; j++){
					if(vis[P[i]][j]==0){
						ck=0; break;
					}
				}
				if(ck==1){
					P.erase(P.begin()+i);
				}
			}
			res+=5; idx++;
			ll ck=0;
			for(ll i=1; i<=n; i++){
				for(ll j=1; j<=m; j++){
					if(vis[i][j]==0){
						ck=1; break;
					}
				}
			}
			if(ck==0){
				ok=1;
			}
		}
		cout<<"Case "<<T<<": "<<res+(5*m)<<"\n";
	}
	return 0;
}

