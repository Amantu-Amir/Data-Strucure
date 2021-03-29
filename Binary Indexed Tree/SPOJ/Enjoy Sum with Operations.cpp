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
const ll N=1e5+50;
const ll mod=1e9+7;

ll n,mark;
ll tree[N][30];
vector<ll>input(N);
void update(ll idx, ll val){
	if(mark==1){
		ll curr_idx=idx;
		while(curr_idx<=n){
			ll temp=input[idx],rem;
			for(ll i=0; i<30; i++){
				rem=temp%2;
				if(rem==1){
					tree[curr_idx][i]--;
				}
				temp/=2;
			}
			curr_idx+=(curr_idx&-curr_idx);
		}
	}
	while(idx<=n){
		ll temp=val,rem;
		for(ll i=0; i<30; i++){
			rem=temp%2;
			if(rem==1){
				tree[idx][i]++;
			}
			temp/=2;
		}
		idx+=(idx&-idx);
	}
}


vector<ll> query(ll idx){
	vector<ll>cnt(30,0);
	while(idx>0){
		for(ll i=0; i<30; i++){
			cnt[i]+=tree[idx][i];
		}
		idx-=(idx&-idx);
	}
	return cnt;
}


ll solve(string type, ll L, ll R){
	vector<ll>high=query(R);
	vector<ll>low=query(L-1);
	ll dif=R-L+1;
	ll tot_pair=(dif*(dif-1))/2;
	ll OR=0,AND=0,XOR=0;
	for(ll i=0; i<30; i++){
		high[i]-=low[i];
		ll zeros=dif-high[i];
		zeros=(zeros*(zeros-1))/2;
		OR+=((tot_pair-zeros)*(1<<i));
		AND+=(((high[i]*(high[i]-1))/2)*(1<<i));
		XOR+=(((dif-high[i])*high[i])*(1<<i));
	}
	if(type=="OR"){
		return OR;
	}
	else if(type=="AND"){
		return AND;
	}
	else{
		return XOR;
	}
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll q;
		cin>>n>>q;
		for(ll i=1; i<=n; i++){
			cin>>input[i];
			update(i,input[i]);
		}
		while(q--){
			ll type; 
			cin>>type;
			if(type==1){
				mark=1;
				ll val,idx;
				cin>>val>>idx;
				update(idx,val);
				input[idx]=val;
			}
			else{
				string op; cin>>op;
				ll L,R; cin>>L>>R;
				ll res=solve(op,L,R);
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}



