#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 2147483647
double PI=2*acos(0.0);

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
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//

const ll p=29;
const ll N=1e5+50;
const ll mod=1e9+7;

vector<ll>tree[N*3],v(N);

void build(ll node, ll b, ll e){
    if(b==e){
        tree[node].pb(v[b-1]);
        return;
    }
    ll mid=Mid(b,e);
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    merge(all(tree[node*2]), all(tree[node*2+1]), back_inserter(tree[node]));
}

bool query(ll node, ll b, ll e, ll L, ll R, ll val){
    if(b>R or e<L or b>e){
        return false;
    }
    if(b>=L and e<=R){
        ll idx=lower_bound(all(tree[node]),val)-tree[node].begin();
        if(idx==tree[node].size()){
            return false;
        }
        if(tree[node][idx]==val){
            return true;
        }
        else{
            return false;
        }
    }
    ll mid=Mid(b,e);
    return query(node*2,b,mid,L,R,val)|query(node*2+1,mid+1,e,L,R,val);
}

int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
        ll n,q; 
        cin>>n>>q;
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        build(1,1,n);
        while(q--){
            ll l,r,x;
            cin>>l>>r>>x;
            yesNo(query(1,1,n,l,r,x));
        }
    }
    return 0;
}

