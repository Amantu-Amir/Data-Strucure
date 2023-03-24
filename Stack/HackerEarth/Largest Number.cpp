//https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/largest-number-7-eee0b7c3/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    stack<char> st;
    ll n = s.size();
    for (ll i = 0; i < n; i++) {
        if (st.empty()) st.push(s[i]);
        else {
            while (st.empty() == 0 and st.top() < s[i] and k) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
    }
    while (k) {
        st.pop();
        k--;
    }
    vector<char> res;
    while (st.empty() == 0) {
        res.push_back(st.top());
        st.pop();
    }
    ll siz = res.size();
    for (ll i = siz - 1; i >= 0; i--) cout << res[i];
    cout << "\n";
    return 0;
}
