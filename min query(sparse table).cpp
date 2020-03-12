#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1e5;
const int K = 25;

int sp[N][K];
void build_sparse_table(vector<int> v){
	int n = v.size();
	for(int i=0; i<n; i++){
		sp[i][0] = v[i];
	}
	for(int j=1; j<=K; j++){
		for(int i=0; i+(1<<j) <= n; i++){
			sp[i][j] = min(sp[i][j-1], sp[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int L, int R){
	int idx = log2(R-L+1);
	return min(sp[L][idx], sp[R-(1<<idx)+1][idx]);
}

int32_t main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("algorithm.txt","r",stdin);
    int tc=1;
    for(int T=1; T<=tc; T++){
    	int n; cin>>n;
    	vector<int> v(n);
    	for(int i=0; i<n; i++){
    		cin>>v[i];
    	}
    	build_sparse_table(v);
    	int q; cin>>q;
    	for(int i=0; i<q; i++){
    		int l, r; cin>>l>>r;
    		int res = query(l-1, r-1);
    		cout<<res<<"\n";
    	}
    }
    return 0;
}