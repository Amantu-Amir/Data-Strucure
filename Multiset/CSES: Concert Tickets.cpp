#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    ll price;
    multiset<ll> st;
    for (ll i = 0; i < n; i++) {
        cin >> price;
        st.insert(price);
    }
    for (ll i = 0; i < m; i++) {
        cin >> price;
        auto it = st.upper_bound(price);
        if (it == st.begin()) {
            cout << "-1\n";
        }
        else {
            it--;
            cout << *it << "\n";
            st.erase(it);
        }
    }
    return 0;
}
