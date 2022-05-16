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

class ListNode{
public:
	ll val;
	ListNode *next;
};

ListNode *root=NULL;

void addNodeEnd(ll val){	
	if(root==NULL){
		root=new ListNode();
		root->val=val;
		root->next=NULL;
	}
	else{
		ListNode *currNode=root;
		while(currNode->next!=NULL){
			currNode=currNode->next;
		}
		ListNode *newNode=new ListNode();
		newNode->val=val;
		newNode->next=NULL;
		currNode->next=newNode;
	}
}

ll getTwinSum(){
	ll totalNode=0;
	ListNode *currNode=root;
	while(1){
		totalNode++;
		if(currNode->next==NULL){
			break;
		}
		currNode=currNode->next;
	}
	ll mid=totalNode/2;
	currNode=root;
	ListNode *prevNode=NULL;
	while(mid--){
		ListNode *temp=currNode;
		currNode=currNode->next;
		temp->next=prevNode;
		prevNode=temp;
	}
	ll twinSum=0,sum;
	while(1){
		sum=prevNode->val+currNode->val;
		twinSum=max(twinSum,sum);
		if(prevNode->next==NULL){
			break;
		}
		prevNode=prevNode->next;
		currNode=currNode->next;
	}
	return twinSum;
}

void printNode(){
	ListNode *currNode=root;
	while(currNode!=NULL){
		cout<<"val: "<<currNode->val<<"\n";
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
		vector<ll>v={1,5};
		for(ll i=0; i<v.size(); i++){
			addNodeEnd(v[i]);
		}
		printNode();
		ll ans=getTwinSum();
		cout<<ans<<"\n";
	}
	return 0;
}



