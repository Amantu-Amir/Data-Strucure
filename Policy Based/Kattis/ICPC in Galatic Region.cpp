#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//

typedef tree<pair<ll,ll>, null_type, less_equal< pair<ll,ll> >, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P=29;
const ll N=2e5+50;
const ll mod=1e9+7;

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
    	ll team, event;
    	cin>>team>>event;
    	ll solve=0, totPan=0;
    	ordered_set st;
    	vector< pair<ll,ll> > v(N, {0, 0});
    	st.insert({0, 0});
    	for(ll i=0; i<event; i++){
    		ll id, pan;
    		cin>>id>>pan;
    		if(id==1){
    			solve++, totPan+=pan;
			}
			if(v[id].F!=0 or id==1){
				st.erase(st.find_by_order(st.order_of_key({v[id].F, -v[id].S})));
			}
			v[id].F++, v[id].S+=pan;
			st.insert({v[id].F, -v[id].S});
			ll ans=st.order_of_key({solve, -totPan+1});
			pair<ll, ll> a=*st.find_by_order(st.order_of_key({solve, -totPan+1}));
			ll tot=st.size();
			if(ans!=tot) ans--;
			if(ans==tot) ans=tot-1;
			cout<<tot-ans<<"\n";
		}
    }
    return 0;
}








