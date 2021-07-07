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

class Data{
public:
    ll L,R,id;
};

Data Q[N];
vector<ll>v(N);
ll cnt[N];
ll res[N],curr_ans,segment_size;

bool cmp(Data &a, Data &b){
    ll block1 = a.L/segment_size;
    ll block2 = b.L/segment_size;
    if(block1==block2){
        return a.R<b.R;
    }
    return block1<block2;
}

void add(ll idx){
    cnt[v[idx]]++;
    if(cnt[v[idx]]==1){
        curr_ans++;
    }
}

void remove(ll idx){
    cnt[v[idx]]--;
    if(cnt[v[idx]]==0){
        curr_ans--;
    }
}

void solve(ll n, ll q){
    segment_size=sqrt(n);
    sort(Q+1,Q+q+1,cmp);
    ll currL=1,currR=0;
    for(ll i=1; i<=q; i++){
        while(currL>Q[i].L){
            add(--currL);
        }
        while(currR<Q[i].R){
            add(++currR);
        }
        while(currL<Q[i].L){
            remove(currL++);
        }
        while(currR>Q[i].R){
            remove(currR--);
        }
        res[Q[i].id]=curr_ans;
    }
}


//Count distinct number in a range

int main(){

    //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
    //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1; cin>>t;
    for(ll T=1; T<=t; T++){
        ll n,q; cin>>n>>q;
        for(ll i=1; i<=n; i++){
            cin>>v[i];
        }
        for(ll i=1; i<=q; i++){
            cin>>Q[i].L>>Q[i].R;
            Q[i].id=i;
        }
        solve(n,q);
        cout<<"Case "<<T<<":\n";
        for(ll i=1;i<=q; i++){
            cout<<res[i]<<"\n";
        }
        curr_ans=0;
        for(ll i=0; i<(N-5); i++){
        	cnt[i]=0;
        }
    }
    return 0;
}

