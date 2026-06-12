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

void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vll post(n, INT_MAX);
    for (ll i = n - 2; i >= 0; i--)
    {
        post[i] = min(post[i + 1], v[i + 1]);
    }
    // cerr << post << '\n';
    ll base = 0;
    for (ll i = 0; i < n; i++)
    {
        base += max(0ll, v[i] - post[i]);
    }
    // cerr << base << '\n';
    ll ans = base;

    vll pse(n);
    stack<pair<ll, ll>> st;
    for (ll i = 0; i < n; i++)
    {
        while (st.size() && st.top().first >= v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            pse[i] = -1;
        }
        else
        {
            pse[i] = st.top().second;
        }
        ans = max(ans, base + (i - pse[i] - 1));
        st.push({v[i], i});
    }
    cout << ans << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();
}