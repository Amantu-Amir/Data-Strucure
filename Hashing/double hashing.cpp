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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//------------------------------------------------------------------------------//


//Max common substring of two strings

const ll N=2e6+50;

ll base[]={27, 29}, mod[]={1000000007, 1000000009};
ll basePow[N][3], aHash[N][3], bHash[N][3];

void rollingHash(string &s, bool flag){
    ll siz=s.size();
    for(ll i=1; i<=siz; i++){
        for(ll j=0; j<2; j++){
            ll id=s[i-1]-'A'+1;
            if(flag==0){
                aHash[0][j]=0;
                aHash[i][j]=((aHash[i-1][j]*base[j])%mod[j]+id)%mod[j];
            }
            else{
                bHash[0][j]=0;
                bHash[i][j]=((bHash[i-1][j]*base[j])%mod[j]+id)%mod[j];
            }
        }
    }
}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(ll i=1; i<N; i++){
        for(ll j=0; j<2; j++){
            basePow[0][j]=1;
            basePow[i][j]=(basePow[i-1][j]*base[j])%mod[j];
        }
    }

    ll t=1;
    for(ll T=1; T<=t; T++){
        ll n;
        cin>>n;
        string s, s2;
        cin>>s>>s2;
        rollingHash(s, 0);
        rollingHash(s2, 1);
        ll L=0, R=n+1, maxLen=0, fstIdx=0;
        while(L<=R){
            ll mid=(L+R)/2, ok=0, idx;
            map<pair<ll,ll>, bool> mark;
            for(ll i=1; (i+mid-1)<=n; i++){
                ll A[3];
                for(ll j=0; j<2; j++){
                    A[j]=(aHash[i+mid-1][j]-(aHash[i-1][j]*basePow[mid][j])%mod[j]+mod[j])%mod[j];
                }
                mark[{A[0], A[1]}]=true;
            }
            for(ll i=1; (i+mid-1)<=n; i++){
                ll A[3];
                for(ll j=0; j<2; j++){
                    A[j]=(bHash[i+mid-1][j]-(bHash[i-1][j]*basePow[mid][j])%mod[j]+mod[j])%mod[j];
                }
                if(mark[{A[0], A[1]}]){
                    ok=1, idx=i; break;
                }
            }
            if(ok){
                maxLen=mid, fstIdx=idx-1;
                L=mid+1;
            }
            else{
                R=mid-1;
            }
        }
        for(ll i=fstIdx; i<(fstIdx+maxLen); i++){
            cout<<s2[i];
        }
        cout<<"\n";
    }
    return 0;
}




