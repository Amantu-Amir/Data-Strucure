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

class node{
public:
    bool endmark;
    node *next[30];
    node(){
        endmark=false;
        for(ll i=0; i<26; i++){
            next[i]=NULL;
        }
    }
}*root;

void insert(string str){
    node *curr=root;
    ll len=str.size();
    for(ll i=0; i<len; i++){
        ll id=str[i]-'a';
        if(curr->next[id]==NULL){
            curr->next[id]=new node();
        }
        curr=curr->next[id];
    }
    curr->endmark=true;
}

bool search(string str){
    node *curr=root;
    ll len=str.size();
    for(ll i=0; i<len; i++){
        ll id=str[i]-'a';
        if(curr->next[id]==NULL){
            return false;
        }
        curr=curr->next[id];
    }
    return curr->endmark;
}

void del(node *curr){
    for(ll i=0; i<26; i++){
        if(curr->next[i]!=NULL){
            del(curr->next[i]);
        }
    }
    delete(curr);
}

int main(){

    //freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
    //freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
        root=new node();
        ll words; 
        cin>>words;
        string str;
        for(ll i=1; i<=words; i++){
            cin>>str;
            insert(str);
        }
        ll q; cin>>q;
        while(q--){
            cin>>str;
            if(search(str)==true){
                cout<<"Found\n";
            }
            else{
                cout<<"Not Found\n";
            }
        }
        del(root);
    }
    return 0;
}

