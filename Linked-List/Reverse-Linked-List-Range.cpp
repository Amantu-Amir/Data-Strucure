#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

class node{
public:
	ll roll;
	node *next;
};

node *root=NULL;

void addNodeEnd(ll roll){	
	if(root==NULL){
		root=new node();
		root->roll=roll;
		root->next=NULL;
	}
	else{
		node *currNode=root;
		while(currNode->next!=NULL){
			currNode=currNode->next;
		}
		node *newNode=new node();
		newNode->roll=roll;
		newNode->next=NULL;
		currNode->next=newNode;
	}
}

void reverseLinkedList(ll L, ll R){
	ll cnt=0;
	if(L==R){
		return;
	}
	node *currNode=root;
	node *start=NULL,*end=NULL;
	while(1){
		cnt++;
		if(cnt<L){
			start=currNode;
		}
		if(cnt>R){
			end=currNode;
			break;
		}
		if(currNode->next==NULL){break;}
		currNode=currNode->next;
	}
	node *prev=end,*temp;
	if(start==NULL){
		currNode=root;
	}
	else{
		currNode=start->next;
	}
	while(currNode->next!=end){
		temp=currNode;
		currNode=currNode->next;
		temp->next=prev;
		prev=temp;
	}
	currNode->next=prev;
	if(start!=NULL){
		start->next=currNode;
	}
	else{
		root=currNode;
	}
}

void printNode(){
	node *currNode=root;
	while(currNode!=NULL){
		cout<<"Roll: "<<currNode->roll<<"\n";
		currNode=currNode->next;
	}
	cout<<"//\n";
}

int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		vector<ll>v={3};
		for(ll i=0; i<v.size(); i++){
			addNodeEnd(v[i]);
		}
		printNode();
		ll x=10;
		while(x--){
			ll L,R; cin>>L>>R;
			reverseLinkedList(L,R);
			printNode();
		}
	}
	return 0;
}



