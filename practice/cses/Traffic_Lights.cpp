#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

#ifndef ONLINE_JUDGE
#include "debugging.h"
#endif

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll x, n;
    cin >> x >> n;

    set<ll> st;

    st.insert(0);
    st.insert(x);

    multiset<ll> ans;
    ans.insert(x);

    for (ll i = 0; i < n; i++)
    {
        ll p;
        cin >> p;

        auto it = st.upper_bound(p);
        ll v = *it;
        ll u = *(--it);
        st.insert(p);
        // cerr << u << ' ' << v << '\n';
        ans.erase(ans.find(v - u));
        ans.insert(p - u);
        ans.insert(v - p);

        cout << *(--ans.end()) << ' ';
    }
}