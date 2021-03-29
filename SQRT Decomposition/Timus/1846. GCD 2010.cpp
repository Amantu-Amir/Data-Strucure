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

ll current_segment=-1;
ll segment_size=sqrt(N);
vector<ll>segment(1010),A(N);
vector<ll>get_start(N);

void add(ll idx, ll val){
	if(idx%segment_size==0){
		current_segment++;
		get_start[current_segment]=idx;
	}
	if(segment[current_segment]==0){
		segment[current_segment]=val;
	}
	segment[current_segment]=__gcd(segment[current_segment],val);
}


void remove(ll curr_idx, ll total_len){
	ll segment_no=curr_idx/segment_size;
	ll L = get_start[segment_no];
	ll curr_gcd = A[curr_idx];
	while(L<min(segment_size, total_len)){
		curr_gcd = __gcd(curr_gcd,A[L++]);
	}
	segment[segment_no]=curr_gcd;
}


ll query(ll L, ll R){
	ll res=segment[L/segment_size];
	while((L+segment_size)<=R){
		res=__gcd(res,segment[L/segment_size]);
		L+=segment_size;
	}
	if(L<=R){
		res=__gcd(res,A[L++]);
	}
	return res;
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll Q; cin>>Q;
		ll n=-1,num,res=0;
		unordered_map<ll,ll>occur,index;
		while(Q--){
			char type; 
			cin>>type;
			if(type=='+'){
				cin>>num; 
				if(occur[num]==0){
					n++;
					A[n]=num; 
					index[num]=n;
					add(n,num);
					res=query(0,n);
					cout<<res<<"\n";
				}
				else{
					cout<<res<<"\n";
				}
				occur[num]++;
			}
			else{
				cin>>num; 
				if(occur[num]>1){
					occur[num]--;
					cout<<res<<"\n";
				}
				else{
					occur[num]--;
					if(n==index[num]){
						if(n==0){
							n--;
							cout<<"1\n";
							current_segment=-1;
							for(ll i=0; i<=1005; i++){
								segment[i]=0;
							}
							continue;
						}
						else{
							remove(n-1,n);
						}
					}
					else{
						index[A[n]]=index[num];
						A[index[num]]=A[n];
						remove(index[num],n);
					}
					n--;
					res=query(0,n);
					cout<<res<<"\n";
				}
			}
		}
	}
	return 0;
}



