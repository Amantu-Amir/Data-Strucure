#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    ll n, p, a;
    cin >> n >> p;
    ll cum = 0;
    map<ll, ll> Z;
    Z[0] = Z[p] = 1;
    ll mx = 0, cnt = 0;
    for (ll i = 1; i <= n; i++) {
      cin >> a;
      cum = (cum + a) % p;
      pair<ll, ll> pr = *Z.upper_bound(cum);
      ll y = pr.first;
      if (y == p) y = 0;
      ll sum = (cum + p - y) % p;
      if (sum == mx) cnt += Z[y];
      else if (sum > mx) { mx = sum; cnt = Z[y]; }
      Z[cum]++;
    }
    cout << mx << " " << cnt << "\n";
  }
  return 0;
}







