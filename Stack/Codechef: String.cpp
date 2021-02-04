
//https://www.codechef.com/problems/CHEFSTRN

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define prnt(a) cout<<a
#define sp cout<<" "
#define nl cout<<"\n"
#define in1(a) cin>>a
#define in2(a,b) cin>>a>>b
#define in3(a,b,c) cin>>a>>b>>c;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,a,b) for(ll i=a; i<b; i++) 
typedef tree < ll, null_type, less < ll >, 
rb_tree_tag, tree_order_statistics_node_update > ordered_set;
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}

//------------------------------------------------------------------------------//


const int N=1e6;
int main(){

	//freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	rep(T,1,t+1){
		string s; cin>>s;
		ll len=s.size();
		stack<char>st;
		for(ll i=0; i<len;i++){
			if(st.empty()==1){
				st.push(s[i]);
			}
			else{
				char ch=st.top();
				if(s[i]==ch){
					st.pop();
				}
				else{
					st.push(s[i]);
				}
			}
		}
		if(st.empty()==0){
			string res;
			while(st.empty()==0){
				res+=st.top(); st.pop();
			}
			reverse(all(res));
			cout<<res<<"\n";
		}
		else{cout<<"Empty String\n";}
	}
	return 0;
}

