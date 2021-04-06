#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
	node *next[2];
	node(){
		next[0]=next[1]=NULL;
	}
}*root;


bool insert(string str){
	node *curr=root;
	ll len=str.size(),ok=0;
	for(ll i=0; i<len; i++){
		ll id=str[i]-'0';
		if(curr->next[id]==NULL){
			ok=1; 
			curr->next[id]=new node();
		}
		curr=curr->next[id];
	}
	return ok;
}

void del(node *curr){
	for(ll i=0; i<2; i++){
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
		ll st=1;
		string str;
		vector<string>A;
		while(getline(cin,str)){
			root=new node();
			if(str.size()==0){
				break;
			}
			if(str=="9"){
				sort(all(A));
				reverse(all(A));
				ll len=A.size(),ok=1;
				for(ll i=0; i<len; i++){
					if(insert(A[i])==0){
						ok=0; break;
					}
				}
				if(ok==1){
					cout<<"Set "<<(st++)<<" is immediately decodable\n";
				}
				else{
					cout<<"Set "<<(st++)<<" is not immediately decodable\n";
				}
				del(root);
				A.clear();
			}
			else{
				A.pb(str);
			}
		}
	}
	return 0;
}

