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
stack<ll>st;
ll res[N];
ll segment_size=350;
ll rep[N],sz[N],comp;
vector<pair<ll,ll>>G(N);


bool cmp(Data &a, Data &b){
  ll block1=a.L/segment_size;
  ll block2=b.L/segment_size;
  if(block1==block2){
    return a.R<b.R;
  }
  return block1<block2;
}

void init(ll n){
  comp=n;
  for(ll i=1; i<=n; i++){
    rep[i]=i; sz[i]=i;
  }
  while(st.size()>0){
    st.pop();
  }
}

ll find_rep(ll r, ll flag){
  if(rep[r]==r){
    return r;
  }
  if(flag==1){
    return find_rep(rep[r], flag);
  }
  return rep[r]=find_rep(rep[r], flag);
}

void join_node(ll u, ll v, ll flag){
  u=find_rep(u, flag);
  v=find_rep(v, flag);
  if(u!=v){
    comp--;
    if(sz[u]>sz[v]){
      swap(u,v);
    }
    rep[u]=v;
    sz[v]+=sz[u];
    if(flag==1){
      st.push(u);
    }
  }
}

void rollback(){
  while(st.size()>0){
    ll u=st.top();
    ll v=rep[u];
    sz[v]-=sz[u];
    rep[u]=u;
    st.pop();
    comp++;
  }
}

int main(){

  //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
  //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  ll t=1; cin>>t;
  for(ll T=1; T<=t; T++){
    ll node,edge,q;
    cin>>node>>edge>>q;
    ll u,v;
    for(ll i=1;i<=edge; i++){
      cin>>u>>v;
      G[i]={u,v};
    }
    for(ll i=1; i<=q; i++){
      cin>>Q[i].L>>Q[i].R;
      Q[i].id=i;
    }
    sort(Q+1,Q+q,cmp);
    ll pre_block=-1,currR;
    for(ll i=1; i<=q; i++){
      ll block=Q[i].L/segment_size;
      if(block!=pre_block){
        init(node);
        pre_block=block;
        currR=Q[i].L;
      }
      while(currR<Q[i].R){
        currR++;
        ll curr_block=currR/segment_size;
        if(curr_block<=block){
          continue;
        }
        join_node(G[currR].F, G[currR].S, 0);
      }
      ll next=min(Q[i].R, (segment_size*(block+1))-1);
      for(ll currL=Q[i].L; currL<=next; currL++){
        join_node(G[currL].F, G[currL].S, 1);
      }
      res[Q[i].id]=comp;
      rollback();
    }
    for(ll i=1; i<=q; i++){
      cout<<res[i]<<"\n";
    }
  }
  return 0;
}

