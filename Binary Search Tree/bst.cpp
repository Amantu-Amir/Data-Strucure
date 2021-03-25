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

bool Search(BSTNode* root, ll val){
  if(root==NULL){
    return false;
  }
  else if(root->data==val){
    return true;
  }
  else if(val<root->data){
    return Search(root->left,val);
  }
  else{
    return Search(root->right,val);
  }
}


BSTNode* FindMin(BSTNode* root){
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}

// Function to search a delete a value from tree.
struct BSTNode* Delete(struct BSTNode *root, int data){
  if(root == NULL) return root; 
  else if(data < root->data){
    root->left = Delete(root->left,data);
  }
  else if(data > root->data){
    root->right = Delete(root->right,data);
  }
    //I found you, Get ready to be deleted  
  else{
    // Case 1:  No child
    if(root->left == NULL && root->right == NULL){ 
      delete root;
      root = NULL;
    }
    //Case 2: One child 
    else if(root->left == NULL) {
      struct BSTNode *temp = root;
      root = root->right;
      delete temp;
    }
    else if(root->right == NULL) {
      struct BSTNode *temp = root;
      root = root->left;
      delete temp;
    }
    // case 3: 2 children
    else { 
      struct BSTNode *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right,temp->data);
    }
  }
  return root;
}
 
void InOrder(BSTNode *root) {
  if(root==NULL){
    return;
  }
  InOrder(root->left);   
  cout<<root->data<<"\n"; 
  InOrder(root->right);     
}

void PreOrder(BSTNode *root) {
  if(root==NULL){
    return;
  }
  cout<<root->data<<"\n"; 
  PreOrder(root->left);   
  PreOrder(root->right);     
}

void PostOrder(BSTNode *root) {
  if(root==NULL){
    return;
  }
  PostOrder(root->left);   
  PostOrder(root->right);    
  cout<<root->data<<"\n";  
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
    ll Q; cin>>Q;
    root=Search(root,Q);
  }
  return 0;
}




