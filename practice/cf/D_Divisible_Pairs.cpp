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
    ll n, x, y;
    cin >> n >> x >> y;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<pair<ll, ll>> vp(n);
    for (int i = 0; i < n; i++)
    {
        vp[i] = {v[i] % y, v[i] % x};
    }

    sort(vp.begin(), vp.end());

    // for (auto e : vp)
    // {
    //     cerr << e << ' ';
    // }
    // cerr << '\n';

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        auto e = vp[i];
        pair<ll, ll> pt = {e.first + 1, -1};
        ll k = lower_bound(vp.begin(), vp.end(), pt) - vp.begin();
        // cerr << i << ' ' << k << '\n';
        pair<ll, ll> pt2 = {e.first, (x - e.second) % x};
        ans += upper_bound(vp.begin() + i + 1, vp.begin() + k, pt2) - lower_bound(vp.begin() + i + 1, vp.begin() + k, pt2);
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