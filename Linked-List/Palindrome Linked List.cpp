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

void palindromeLinkedList(){
	ll totalNode=1,mid;
	node *currNode=root;
	while(currNode->next!=NULL){
		totalNode++;
		currNode=currNode->next;
	}
	if(totalNode==1){
		cout<<"YES\n";
		return;
	}
	mid=totalNode/2;
	ll cnt=0;
	currNode=root;
	node *prev=NULL,*temp;
	while(1){
		cnt++;
		temp=currNode;
		currNode=currNode->next;
		temp->next=prev;
		prev=temp;
		if(cnt==mid){break;}
	}
	bool ok=true;
	if(totalNode%2==1){
		currNode=currNode->next;
	}
	while(mid--){
		if(temp->roll!=currNode->roll){
			ok=false; break;
		}
		temp=temp->next;
		currNode=currNode->next;
	}
	yesNo(ok);
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
		vector<ll>v={1,2,2,2,1};
		for(ll i=0; i<v.size(); i++){
			addNodeEnd(v[i]);
		}
		printNode();
		palindromeLinkedList();
	}
	return 0;
}



