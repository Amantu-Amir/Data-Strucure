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
const ll N=3e5+50;
const ll mod=1e9+7;


vector<ll>A(N);
ll segment_size=600;
vector<ll>segment[600];

void pre_process(ll n){
	ll current_segment=-1;
	for(ll i=0; i<n; i++){
		if(i%segment_size==0){
			if(current_segment!=-1){
				sort(all(segment[current_segment]));
			}
			current_segment++;
		}
		segment[current_segment].pb(A[i]);
	}
}



ll query(ll L, ll R, ll val){
	ll cnt=0;
	while(L<R and L%segment_size!=0){
		if(A[L++]<val){
			cnt++;
		}
	}
	while((L+segment_size)<=R){
		ll block=L/segment_size;
		ll idx=lower_bound(all(segment[block]), val)-segment[block].begin();
		cnt+=idx; L+=segment_size;
	}
	while(L<=R){
		if(A[L++]<val){
			cnt++;
		}
	}
	return cnt;
}

void update(ll idx, ll val){
	ll block=idx/segment_size;
	ll siz=segment[block].size();
	for(ll i=0; i<siz; i++){
		if(segment[block][i]==A[idx]){
			segment[block][i]=val;
			break;
		}
	}
	sort(all(segment[block]));
	A[idx]=val;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n,q,u;
		cin>>n>>q>>u;
		for(ll i=0; i<n; i++){
			cin>>A[i];
		}
		pre_process(n);
		ll L,R,val,idx;
		for(ll i=0; i<q; i++){
			cin>>L>>R>>val>>idx;
			ll res=query(L-1,R-1,val);
			update(idx-1,(u*res)/(R-L+1));
		}
		for(ll i=0; i<n; i++){
			cout<<A[i]<<"\n";
		}
	}
	return 0;
}

