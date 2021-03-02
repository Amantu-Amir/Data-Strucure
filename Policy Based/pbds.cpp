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
#define inf 2147483647
string toString(ll n){stringstream ss; ss<<n; return ss.str();}
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
vector<ll> removeDup(vector<ll>v){
sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//------------------------------------------------------------------------------//

typedef tree<ll, null_type, less_equal<ll>,                 //takes duplicate value
rb_tree_tag, tree_order_statistics_node_update> pds;

//tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>T;


const int N=2e6+50;
const int mod=1e9+7;


int main(){

    //freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    /*
        order_of_key(n) : Find the position of n;
        find_by_order(idx) : Find the value of this position
    */


    ll t=1;
    for(ll T=1; T<=t; T++){
        ll n,q; cin>>n>>q;
        vector<ll>v(n);
        pds s;
        for(ll i=0; i<n; i++){
            cin>>v[i];
            s.insert(v[i]);
        }
        while(q--){
            char op;
            cin>>op;
            if(op=='?'){
                ll a,b;             //Find no of elements between a and b
                cin>>a>>b;
                ll res=s.order_of_key(b+1)-s.order_of_key(a);
                cout<<res<<"\n";
            }
            else{
                ll idx,val;         //update idx with val   
                cin>>idx>>val;
                s.erase(s.find_by_order(s.order_of_key(v[idx])));
                s.insert(val);
                v[idx]=val;
            }
        }
    }
    return 0;
}

