#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define Mid(b, e) b + (e - b) / 2
#define inf 1e18
double PI = 2 * acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[] = {1, 2, 2, 1, -1, -2, -2, -1};

//8 direction
// ll dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// ll dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//4 direction
// ll dx[]={1, -1, 0, 0};
// ll dy[]={0, 0, 1, -1};

void yesNo(bool ck){cout << (ck ? "YES\n" : "NO\n");}
//------------------------------------------------------------------------------//

//ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
//string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
//typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


const ll P = 29;
const ll N = 1e5 + 50;
const ll mod = 1e9 + 7;

class Tree {
public:
  ll zero, one;
}tree[4 * N];

vector<ll> lazy(4 * N);

void build(ll node, ll b, ll e, string &s, vector<ll>& v) {
  if (b == e) {
    if (s[b - 1] == '1') tree[node].one = v[b - 1];
    else tree[node].zero = v[b - 1];
    return;
  }
  ll mid = b + (e - b) / 2;
  build(node * 2, b, mid, s, v);
  build(node * 2 + 1, mid + 1, e, s, v);
  tree[node].one = tree[node * 2].one ^ tree[node * 2 + 1].one;
  tree[node].zero = tree[node * 2].zero ^ tree[node * 2 + 1].zero;
}

void propagate(ll node, ll b, ll e) {
  if (b != e) {
    lazy[node * 2] ^= lazy[node];
    lazy[node * 2 + 1] ^= lazy[node];
  }
  if (lazy[node]) swap(tree[node].one, tree[node].zero);
  lazy[node] = 0;
}

void update(ll node, ll b, ll e, ll l, ll r) {
  if (lazy[node]) propagate(node, b, e);
  if (b > r or e < l or b > e) return;
  if (b >=l and e <= r) {
    lazy[node] ^= 1;
    if (lazy[node]) propagate(node, b, e);
    return;
  }
  ll mid = b + (e - b) / 2;
  update(node * 2, b, mid, l, r);
  update(node * 2 + 1, mid + 1, e, l, r);
  tree[node].one = tree[node * 2].one ^ tree[node * 2 + 1].one;
  tree[node].zero = tree[node * 2].zero ^ tree[node * 2 + 1].zero;
}

ll query(ll node, ll b, ll e, ll l, ll r, bool status) {
  if (lazy[node]) propagate(node, b, e);
  if (b > r or e < l or b > e) return 0;
  if (b >= l and e <= r) return (status ? tree[node].one : tree[node].zero);
  ll mid = b + (e - b) / 2;
  ll q1 = query(node * 2, b, mid, l, r, status);
  ll q2 = query(node * 2 + 1, mid + 1, e, l, r, status);
  return q1 ^ q2;
}

int main() {

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    ll n;
    cin >> n;
    for (ll i = 0; i <= (4 * n); i++) {
      tree[i].one = tree[i].zero = lazy[i] = 0;
    }
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
      cin >> v[i];
    }
    string s;
    cin >> s;
    ll xorOne = 0, xorZero = 0;
    for (ll i = 0; i < n; i++) {
      if (s[i] == '1') xorOne ^= v[i];
      else xorZero ^= v[i];
    }
    build(1, 1, n, s, v);
    ll q;
    cin >> q;
    while (q--) {
      ll tp;
      cin >> tp;
      if (tp == 1) {
        ll l, r;
        cin >> l >> r;
        update(1, 1, n, l, r);
        ll getXorOne = query(1, 1, n, l, r, 1);
        ll getXorZero = query(1, 1, n, l, r, 0);
        xorOne ^= getXorOne;
        xorOne ^= getXorZero;
        xorZero ^= getXorZero;
        xorZero ^= getXorOne;
      }
      else {
        ll g;
        cin >> g;
        cout << (g ? xorOne : xorZero) << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}





