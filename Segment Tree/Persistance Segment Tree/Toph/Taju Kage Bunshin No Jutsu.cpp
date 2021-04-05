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

class Node{
public:
    ll left,right,val;
}tree[N*20];


class Data{
public:
    ll L,R,k,v,type;
}Q[N];

ll id,curr;
vector<ll>A(N),root(N);
map<ll,ll>mp,origin;

ll update(ll node, ll b, ll e, ll idx){
    if(b>idx or e<idx){
        return node;
    }
    if(b==e){
        tree[++id]=tree[node];
        tree[id].val++;
        return id;
    }
    ll mid=b+(e-b)/2;
    tree[++id]=tree[node];
    node=id;
    tree[node].left = update(tree[node].left,b,mid,idx);
    tree[node].right = update(tree[node].right,mid+1,e,idx);
    tree[node].val = tree[tree[node].left].val + tree[tree[node].right].val;
    return node;
}

ll kthElement(ll a, ll b, ll L, ll R, ll k){
    if(L==R){
        return L;
    }
    ll mid=(L+R)>>1;
    ll cnt=tree[tree[a].left].val - tree[tree[b].left].val;
    if(cnt>=k){
        return kthElement(tree[a].left,tree[b].left,L,mid,k);
    }
    else{
        return kthElement(tree[a].right,tree[b].right,mid+1,R,k-cnt);
    }
}


ll lessCnt(ll a, ll b, ll L, ll R, ll idx){
    if(R<=idx){
        return tree[a].val - tree[b].val;
    }
    ll mid = (L+R)>>1;
    if(idx<=mid){
        return lessCnt(tree[a].left,tree[b].left,L,mid,idx);
    }
    else{
        return lessCnt(tree[a].left,tree[b].left,L,mid,idx) + lessCnt(tree[a].right,tree[b].right,mid+1,R,idx);
    }
}

void init(ll n, ll m){
    root[0]=tree[0].left=tree[0].right=tree[0].val=0;
    for(ll i=1; i<=n; i++){
        root[i]=update(root[i-1],1,m,mp[A[i]]);
    }
}


int main(){

    //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
    //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
        ll n; cin>>n;
        set<ll>st;
        for(ll i=1; i<=n; i++){
            cin>>A[i];
            st.insert(A[i]);
        }
        ll q; cin>>q;
        for(ll i=1; i<=q; i++){
            cin>>Q[i].type;
            if(Q[i].type==1){
                cin>>Q[i].v;
                st.insert(Q[i].v);
            }
            else if(Q[i].type==3){
                cin>>Q[i].L>>Q[i].R>>Q[i].k;
            }
        }
        ll m=0;
        for(auto it=st.rbegin(); it!=st.rend(); it++){
            mp[*it]=++m;
            origin[m]=*it;
        }
        init(n,m);
        ll curr_idx=n+1;
        for(ll i=1; i<=q; i++){
            if(Q[i].type==1){
                root[curr_idx]=update(root[curr_idx-1],1,m,mp[Q[i].v]);
                curr_idx++;
            }
            else if(Q[i].type==2){
                curr_idx--;
            }
            else{
                ll idx=kthElement(root[Q[i].R], root[Q[i].L-1],1,m,Q[i].k);
                cout<<origin[idx]<<"\n";
            }
        }
    }
    return 0;
}

