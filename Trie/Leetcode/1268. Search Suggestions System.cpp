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
	node *next[30];
	vector<string>list;
	node(){
		for(ll i=0; i<26; i++){
			next[i]=NULL;
		}
	}
}*root;

class Solution{
public:
	vector<vector<string>>suggestedProducts(vector<string>&products, string searchWord){
        root=new node();
        ll len=products.size();
        sort(all(products));
        for(ll i=0; i<len; i++){
        	node *curr=root;
			ll len=products[i].size();
			for(ll j=0; j<len; j++){
				ll id=products[i][j]-'a';
				if(curr->next[id]==NULL){
					curr->next[id]=new node();
				}
				curr=curr->next[id];
				curr->list.pb(products[i]);
			}
        }

        len=searchWord.size();
        node *curr=root;
        vector<vector<string>>res(len);
        for(ll i=0; i<len; i++){
        	ll id=searchWord[i]-'a';
        	if(curr->next[id]==NULL){
        		break;
        	}
        	curr=curr->next[id];
        	ll siz=curr->list.size();
        	for(ll j=0; j<(min(3LL,siz)); j++){
        		res[i].pb(curr->list[j]);
        	}
        }
        return res;
    }
};


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		vector<string>str(n);
		for(ll i=0; i<n; i++){
			cin>>str[i];
		}
		string searchWord;
		cin>>searchWord;
		Solution sol;
		vector<vector<string>>res=sol.suggestedProducts(str,searchWord);
		ll len=searchWord.size();
		for(ll i=0; i<len; i++){
			ll siz=res[i].size();
			for(ll j=0; j<siz; j++){
				cout<<res[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}

