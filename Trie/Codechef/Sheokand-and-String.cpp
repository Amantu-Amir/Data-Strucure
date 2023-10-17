#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 1e5 + 50, mod = 1e9 + 7;

class Trie {
public:
  Trie *next[30];
  ll track[30], endmark, endmarkTrack;
  Trie () {
    endmark = 0;
    for (ll i = 0; i <= 26; i++) {
      next[i] = NULL;
    }
  }
}* root;

void insert(ll idx, string &s) {
  Trie *curr = root;
  for (auto i : s) {
    ll id = i - 'a';
    if (curr->next[id] == NULL) {
      curr->next[id] = new Trie();
      curr->track[id] = idx;
    }
    curr = curr->next[id];
  }
  if (curr->endmark == 0) {
    curr->endmark = 1; 
    curr->endmarkTrack = idx;
  }
}

string query(ll idx, string &s) {
  string res;
  Trie *curr = root;
  for (auto i : s) {
    ll id = i - 'a';
    if (curr->next[id] == NULL or curr->track[id] > idx) break;
    res += i;
    curr = curr->next[id]; 
  }
  while (1) {
    if (curr->endmark and curr->endmarkTrack <= idx) break;
    ll i = 0;
    while (i < 26) {
      if (curr->next[i] != NULL and curr->track[i] <= idx) {
        res += (i + 'a');
        curr = curr->next[i];
        break;
      }
      i++;
    }
    if (i >= 26) break;
  }
  return res;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    root = new Trie();
    ll n;
    cin >> n;
    string s;
    for (ll i = 1; i <= n; i++) {
      cin >> s;
      insert(i, s);
    }
    ll q;
    cin >> q;
    while (q--) {
      ll r;
      cin >> r >> s;
      string res = query(r, s);
      cout << res << "\n";
    }
  }
  return 0;
}



