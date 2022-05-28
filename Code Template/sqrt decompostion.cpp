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

ll segment_size;
vector<ll>A,segment(N);
void pre_process(ll n){
	ll current_segment=-1;
	segment_size=sqrt(n);
	for(ll i=0; i<n; i++){
		if(i%segment_size==0){
			current_segment++;
		}
		segment[current_segment]+=A[i];
	}
}

ll query(ll L, ll R){
	ll res=0;
	while(L<R and L%segment_size!=0){
		res+=A[L]; L++;
	}
	while((L+segment_size)<=R){
		res+=segment[L/segment_size];
		L+=segment_size;
	}
	while(L<=R){
		res+=A[L];
		L++;
	}
	return res;
}

void update(ll idx, ll val){
	ll segment_no=idx/segment_size;
	segment[segment_no]-=A[idx];
	segment[segment_no]+=val;
	A[idx]=val;
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		A.resize(n);
		for(ll i=0; i<n; i++){
			cin>>A[i];
		}
		pre_process(n);
		ll Q; cin>>Q;
		while(Q--){
			ll type;
			cin>>type;
			if(type==1){
				ll idx,val;
				cin>>idx>>val;
				update(idx,val);
			}
			else{
				ll L,R;
				cin>>L>>R;
				ll res=query(L,R);
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}



