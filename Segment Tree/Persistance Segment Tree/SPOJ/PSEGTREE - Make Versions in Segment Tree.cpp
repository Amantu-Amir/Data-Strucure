#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e5+50;

int arr[N];
class Node{
public:
	Node *left;
	Node *right;
	int val;
	Node(){
		left = NULL; right = NULL; val = 0;
	}
}*root[N];

void build(Node *curr, int b, int e){
	if(b == e){
		curr -> val = arr[b];
		return;
	}
	int mid = b + (e-b)/2;
	curr -> left = new Node();
	curr -> right = new Node();
	build(curr -> left, b, mid);
	build(curr -> right, mid+1, e);
	curr -> val = (curr -> left -> val) + (curr -> right -> val);
}

void update(Node *currNode, Node *preNode, int b, int e, int idx, int v){
	if(b > idx or e < idx or b > e) return;
	if(b == e){
		currNode -> val = (preNode -> val + v);
		return;
	}
	int mid = b + (e-b)/2;
	if(idx <= mid){
		currNode -> right = preNode -> right;
		currNode -> left = new Node();
		update(currNode -> left, preNode -> left, b, mid, idx, v);
	}
	else{
		currNode -> left = preNode -> left;
		currNode -> right = new Node();
		update(currNode -> right, preNode -> right, mid+1, e, idx, v);
	}
	currNode -> val = (currNode -> left -> val) + (currNode -> right -> val);
}

int query(Node *curr, int b, int e, int l, int r){
	if(b > r or e < l or b > e) return 0;
	if(b >= l and e <= r) return curr -> val;
	int mid = b + (e-b)/2;
	int q1 = query(curr -> left, b, mid, l, r);
	int q2 = query(curr -> right, mid+1, e, l, r);
	return q1+q2;
}

int32_t main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("spoj.txt", "r", stdin);
	int tc = 1; 
	for(int T=1; T<=tc; T++){
		int n; cin>>n;
		for(int i=1; i<=n; i++){
			cin>>arr[i];
		}

		root[0] = new Node();
		build(root[0], 1, n);

		int q, curr = 0; cin>>q;
		for(int i=1; i<=q; i++){
			int op; cin>>op;
			if(op == 1){
				int ver, idx, v;
				cin>>ver>>idx>>v;
				root[++curr] = new Node();
				update(root[curr], root[ver], 1, n, idx, v);
			}
			else{
				int ver, l, r;
				cin>>ver>>l>>r;
				int res = query(root[ver], 1, n, l, r);
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}