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
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//

const ll p=29;
const ll N=2e5+50;
const ll mod=1e9+7;


vector<ll>occur(N),tree(N*3);

void build(ll node, ll b, ll e){
    if(b==e){
        tree[node]=occur[b-1];
        return;
    }
    ll mid=(b+e)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

ll query(ll node, ll b, ll e, ll L, ll R){
    if(b>R or e<L or b>e){
        return -1;
    }
    if(b>=L and e<=R){
        return tree[node];
    }
    ll mid=(b+e)/2;
    return max(query(node*2,b,mid,L,R),query(node*2+1,mid+1,e,L,R));
}

int main(){

    //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
    //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1; cin>>t;
    for(ll T=1; T<=t; T++){
        ll n,c,q; 
        cin>>n>>c>>q;
        ll aa; cin>>aa;
        ll prev=aa,cnt=1;
        occur[0]=1;
        vector<ll>v(n);
        vector<pair<ll,ll>>A(n+5);
        v[0]=aa;
        for(ll i=1; i<n; i++){
            cin>>aa;
            v[i]=aa;
            if(aa==prev){
                cnt++;
            }
            else{
                cnt=1;
            }
            occur[i]=cnt;
            A[aa]={cnt,i};
            prev=aa;
        }
        build(1,1,n);
        ll l,r;
        cout<<"Case "<<T<<":\n";
        while(q--){
            ll res=-1;
            cin>>l>>r;
            if(v[r-1]==v[l-1]){
                res=r-l+1;
            }
            else{
                ll val=A[v[l-1]].F,idx=A[v[l-1]].S+1;
                res=val-occur[l-1]+1;
                res=max(res,query(1,1,n,idx+1,r));
            }
            cout<<res<<"\n";
        }
    }
    return 0;
}

