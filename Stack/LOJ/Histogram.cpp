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


vector<ll> calc(vector<ll>&v){
	stack<pair<ll,ll>>st;
	st.push({0,0});
	ll sz=v.size();
	vector<ll>expand(sz);
	for(ll i=0; i<sz; i++){
		ll val,idx,ck;
		while(st.size()>=1){
			pair<ll,ll>curr=st.top();
			val=curr.F, idx=curr.S;
			if(val>=v[i]){
				ck=1;
				if(val!=0){
					st.pop();
				}
			}
			else{
				ck=0;
				expand[i]=(i+1)-idx;
				break;
			}
		}
		if(ck==1){
			expand[i]=(i+1)-idx;
		}
		st.push({v[i],(i+1)});
	}
	return expand;
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1; cin>>t;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		vector<ll>v(n),res(n);
		for(ll i=0; i<n; i++){
			cin>>v[i];
		}
		vector<ll>left,right;
		left=calc(v);
		reverse(all(v));
		right=calc(v);
		reverse(all(right));
		reverse(all(v));
		ll ans=0;
		for(ll i=0; i<n; i++){
			res[i]=left[i]+right[i]-1;
			ans=max(ans,v[i]*res[i]);
		}
		cout<<"Case "<<T<<": "<<ans<<"\n";
	}
	return 0;
}

