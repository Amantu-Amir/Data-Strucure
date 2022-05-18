#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
//typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>pbds; 
//typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>pbds; 

//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

class Solution {
public:
	ll rep[1010],rank[1010];
	ll Find(ll r){
		if(rep[r]==r){return r;}
		return rep[r]=Find(rep[r]);
	}
	bool Union(ll a,ll b){
		a=Find(a),b=Find(b);
		if(a==b){
			return true;
		}
		if(rank[a]<rank[b]){
			swap(rank[a],rank[b]);
		}
		rep[b]=a;
		rank[a]+=rank[b];
		return false;
	}
	vector<ll> findRedundantDirectedConnection(vector<vector<ll>>& edges){
		ll node=edges.size();
		for(ll i=0; i<=node; i++){
			rep[i]=i, rank[i]=1;
		}
		ll first=-1,last=-1;
		vector<ll>First(node+5,-1);
		for(ll i=0; i<node; i++){
			if(First[edges[i][1]]==-1){
				First[edges[i][1]]=i;
			}
			else{
				last=i;
				first=First[edges[i][1]];
				break;
			}
		}
		for(ll i=0; i<node; i++){
			if(i!=last){
				bool cycle=Union(edges[i][0],edges[i][1]);
				if(cycle==true){
					if(last==-1){
						return edges[i];
					}
					return edges[first];
				}
			}
		}
		return edges[last];
	}
};



int main(){

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll node,u,v; 
		cin>>node;
		vector<vector<ll>>edges;
		for(ll i=0; i<node; i++){
			cin>>u>>v;
			edges.push_back({u,v});
		}
		Solution obj;
		vector<ll>ans=obj.findRedundantDirectedConnection(edges);
		cout<<ans[0]<<" "<<ans[1]<<"\n";
	}
	return 0;
}



