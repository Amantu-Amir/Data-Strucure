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

struct BSTNode{
  ll data;
  BSTNode* left;
  BSTNode* right;
};

BSTNode* GetNewNode(ll val){
  BSTNode* newNode=new BSTNode();
  newNode->data=val;
  newNode->left=newNode->right=NULL;
  return newNode;
}

BSTNode* Insert(BSTNode* root, ll val){
  if(root==NULL){
    root=GetNewNode(val);
  }
  else if(val<=root->data){
    root->left=Insert(root->left,val);
  }
  else{
    root->right=Insert(root->right,val);
  }
  return root;
}

ll Search(BSTNode* root){
  if(root==NULL){
    return 0;
  }
 ll leftLevel=Search(root->left);
 ll rightLevel=Search(root->right);
 return max(leftLevel,rightLevel)+1;
}


int main(){

  //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
  //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  ll t=1; cin>>t;
  for(ll T=1; T<=t; T++){
    BSTNode* root = NULL;
    ll n,a; cin>>n;
    for(ll i=1; i<=n; i++){
      cin>>a;
      root=Insert(root, a);
    }
    cout<<Search(root)<<"\n";
    delete(root);
  }
  return 0;
}




