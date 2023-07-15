#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
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
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


const ll P = 661;
const ll N = 1e5+50;
const ll mod = 1e9+7;

ll basePow[N];

vector<ll> rollingHash(string &s) {
    ll siz = s.size();
    vector<ll> hash(siz + 5); 
    hash[0] = 0;
    for(ll i = 1; i <= siz; i++) {
        ll id = s[i - 1] - 'a' + 1;
        if(s[i - 1] >= 'A' and s[i - 1] <= 'Z') {
            id += 26;
        }
        hash[i] = ((hash[i - 1] * P) % mod + id) % mod;
    }
    return hash;
}

ll computeHash(string &s) {
    ll siz = s.size(), hash = 0;
    for(ll i = 0; i < siz; i++) {
        ll id = s[i] - 'a' + 1;
        if(s[i] >= 'A' and s[i] <= 'Z') {
            id += 26;
        }
        hash = ((hash * P) % mod + id) % mod;
    }
    return hash;
}

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    basePow[0] = 1;
    for(ll i = 1; i < N; i++) {
        basePow[i] = (basePow[i - 1] * P) % mod;
    }

    ll t = 1;
    for(ll T = 1; T <= t; T++) {
        string text, pat;
        getline(cin, text);
        getline(cin, pat);

        vector<ll> textHash = rollingHash(text);
        ll patHash = computeHash(pat);

        ll textLen = text.size(), patLen = pat.size();
        vector<ll> res;

        for(ll i = 1; (i + patLen - 1) <= textLen; i++) {
            ll currHash = (textHash[i + patLen - 1] - (textHash[i - 1] * basePow[patLen]) % mod + mod) % mod;
            if(currHash == patHash) {
                res.pb(i - 1);
            }
        }

        for(auto i : res) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}



