#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 2147483647

const ll N=2e5+50;
const ll mod=1e9+7;

class node{
public:
	node *next[30];
	ll count;
	node(){
		count=0;
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
		curr->count++;
	}
}

string search(string str){
	node *curr=root;
	ll len=str.size();
	ll idx=len;
	for(ll i=0; i<len; i++){
		ll id=str[i]-'a';
		curr=curr->next[id];
		if(curr->count==1){
			idx=i; break;
		}
	}
	return str.substr(0,idx+1);
}

int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		root=new node();
		string str;
		vector<string>A;
		while(getline(cin,str)){
			if(str.size()==0){
				break;
			}
			insert(str);
			A.pb(str);
		}
		ll len=A.size();
		for(ll i=0; i<len; i++){
			string res=search(A[i]);
			cout<<A[i]<<" "<<res<<"\n";
		}
	}
	return 0;
}

