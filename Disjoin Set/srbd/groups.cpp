#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 1e7 + 50, mod = 1e9 + 7;

bitset<N> isPrime;
void sieve() {
	isPrime[1] = 1;
  for (ll i = 2; (i * i) < N; i++) {
    if (isPrime[i] == 0) {
      for (ll j = i * i; j < N; j += i) {
        isPrime[j] = 1;
      }
    }
  }
}

vector<ll> v(1e5 + 5), Min(4e5), Max(4e5);

void build(ll node, ll b, ll e) {
	if (b == e) {
		Min[node] = (!isPrime[v[b]] ? b : inf);
		Max[node] = (!isPrime[v[b]] ? b : 0);
		return;
	}
	ll mid = b + (e - b) / 2;
	build(node * 2, b, mid);
	build(node * 2 + 1, mid + 1, e);
	Min[node] = min(Min[node * 2], Min[node * 2 + 1]);
	Max[node] = max(Max[node * 2], Max[node * 2 + 1]);
	//cout << node << " " << Min[node] << " " << Max[node] << " debug\n";
}

ll getMin(ll node, ll b, ll e, ll l, ll r) {
	if (b > r or e < l or b > e) return inf;
	if (b >= l and e <= r) return Min[node];
	ll mid = b + (e - b) / 2;
	ll q1 = getMin(node * 2, b, mid, l, r);
	ll q2 = getMin(node * 2 + 1, mid + 1, e, l, r);
	//cout << node << " " << min(q1, q2) << " min\n"; 
	return min(q1, q2);
}

ll getMax(ll node, ll b, ll e, ll l, ll r) {
	if (b > r or e < l or b > e) return 0;
	if (b >= l and e <= r) return Max[node];
	ll mid = b + (e - b) / 2;
	ll q1 = getMax(node * 2, b, mid, l, r);
	ll q2 = getMax(node * 2 + 1, mid + 1, e, l, r);
	//cout << node << " " << min(q1, q2) << " max\n"; 
	return max(q1, q2);
}

void update(ll node, ll b, ll e, ll idx, ll val) {
	if (b == e) {
		Min[node] = (!isPrime[val] ? b : inf);
		Max[node] = (!isPrime[val] ? b : 0);
		return;
	}
	ll mid = b + (e - b) / 2;
	if (idx <= mid) update(node * 2, b, mid, idx, val);
	else update(node * 2 + 1, mid + 1, e, idx, val);
	Min[node] = min(Min[node * 2], Min[node * 2 + 1]);
	Max[node] = max(Max[node * 2], Max[node * 2 + 1]);
}

int main() {
	//https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges
	//freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  //https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges
  
  sieve();
  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
    	cin >> v[i];
    }
    build(1, 1, n);
    while (q--) {
    	ll type;
    	cin >> type;
    	if (type == 1) {
    		ll idx;
    		cin >> idx;
    		ll r = getMin(1, 1, n, idx + 1, n);
    		if (r == inf) r = n + 1;
    		ll l = getMax(1, 1, n, 1, idx - 1);
    		//cout << l << " " << r << " ck\n";
    		ll res = max(0LL, (r - (idx + 1))) + max(0LL, idx - (l + 1));
    		cout << res << "\n";
    	}
    	else {
    		ll idx, val;
    		cin >> idx >> val;
    		update(1, 1, n, idx, val);
    	}
    }
  }
  return 0;
}



