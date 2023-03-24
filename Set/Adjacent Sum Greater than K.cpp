//https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/adjacent-sum-greater-than-k-f41e3ec4/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if ((1 + n) < k) {
            cout << "-1\n";
            continue;
        }
        set<ll> st;
        vector<ll> res;
        res.push_back(1);
        for (ll i = 2; i <= n; i++) st.insert(i);
        ll last = 1;
        for (ll i = 1; i <= (n - 1); i++) {
            last = *st.lower_bound(k - last);
            st.erase(last);
            res.push_back(last);
        }
        for (auto i : res) cout << i << " ";
        cout << "\n";
    }
    return 0;
}


