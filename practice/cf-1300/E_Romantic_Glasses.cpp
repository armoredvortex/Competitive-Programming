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

    vll o(n, -1), e(n, -1);

    e[0] = 0;
    for (ll i = 1; i < n; i += 2)
    {
        e[i] = v[i] + e[i - 1];
        if (i + 1 < n)
        {
            e[i + 1] = e[i];
        }
    }
    o[0] = v[0];
    if (1 < n)
    {
        o[1] = o[0];
    }
    for (ll i = 2; i < n; i += 2)
    {
        o[i] = v[i] + o[i - 1];
        if (i + 1 < n)
        {
            o[i + 1] = o[i];
        }
    }

    // cerr << e << '\n'
    //      << o << '\n';

    set<ll> st;
    st.insert(0);
    for (ll i = 0; i < n; i++)
    {
        auto k = e[i] - o[i];
        // cout << k << ' ';
        if (st.find(k) != st.end())
        {
            cout << "YES\n";
            return;
        }

        st.insert(k);
    }
    cout << "NO\n";
    return;
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