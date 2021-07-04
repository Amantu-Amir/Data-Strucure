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


class Data{
public:
    ll Min,Max;
};

ll logs[N];
vector<ll>v;
Data sparse[22][N];

void build_sparse_table(ll n){
    logs[1]=0;
    for(ll i=2; i<=n; i++){
        logs[i]=logs[i/2]+1;
    }
    for(ll i=0; i<=logs[n]; i++){
        ll segment_len=1<<i;
        for(ll j=0; (j+segment_len)<=n; j++){
            if(segment_len==1){
                sparse[i][j].Min=v[j];
                sparse[i][j].Max=v[j];
            }
            else{
                sparse[i][j].Min=min(sparse[i-1][j].Min, sparse[i-1][j+(segment_len/2)].Min);
                sparse[i][j].Max=max(sparse[i-1][j].Max, sparse[i-1][j+(segment_len/2)].Max);
            }
        }
    }
}

ll get_min(ll L, ll R){
    ll K=logs[R-L+1];
    return min(sparse[K][L].Min, sparse[K][R-(1<<K)+1].Min);
}

ll get_max(ll L, ll R){
    ll K=logs[R-L+1];
    return max(sparse[K][L].Max, sparse[K][R-(1<<K)+1].Max);
}

int main(){

    //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
    //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1; cin>>t;
    for(ll T=1; T<=t; T++){
        ll n,d; cin>>n>>d;
        v.resize(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        build_sparse_table(n);
        ll res=0;
        for(ll i=0; i<=(n-d); i++){
        	res=max(res,get_max(i,i+d-1)-get_min(i,i+d-1));
        }
        cout<<"Case "<<T<<": "<<res<<"\n";
        v.clear();
    }
    return 0;
}




