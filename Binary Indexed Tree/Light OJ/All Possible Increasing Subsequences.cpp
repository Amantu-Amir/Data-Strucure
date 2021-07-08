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
const ll N=2e5+50;
const ll mod=1e9+7;

ll tree[N],cnt;
void update(ll idx, ll val){
    while(idx<=cnt){
        tree[idx]=(tree[idx]+val)%mod;
        idx+=(idx&-idx);
    }
}

ll query(ll idx){
    ll sum=0;
    while(idx>0){
        sum=(sum+tree[idx])%mod;
        idx-=(idx&-idx);
    }
    return sum;
}


int main(){

    //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
    //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1; cin>>t;
    for(ll T=1; T<=t; T++){
        ll n; cin>>n;
        vector<ll>A(n);
        for(ll i=0; i<n; i++){
            cin>>A[i];
        }
        vector<ll>temp(all(A));
        sort(all(temp));
        map<ll,ll>mp;
        cnt=0;
        for(ll i=0; i<n; i++){
            if(mp[temp[i]]==0){
                mp[temp[i]]=++cnt;
            }
        }
        ll res=0,curr;
        for(ll i=0; i<n; i++){
            curr=query(mp[A[i]]-1)+1;
            res=(res+curr)%mod;
            update(mp[A[i]],curr);
        }
        cout<<"Case "<<T<<": "<<res<<"\n";
        for(ll i=0; i<(N-5); i++){
            tree[i]=0;
        }
    }
    return 0;
}

