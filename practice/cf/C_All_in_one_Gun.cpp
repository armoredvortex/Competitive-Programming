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
    ll n, h, k;
    cin >> n >> h >> k;

    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;
    ll sum = accumulate(v.begin(), v.end(), 0ll);

    ans += (h / sum) * k + n * (h / sum);

    vll pre(n);
    pre[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        pre[i] = v[i] + pre[i - 1];
    }
    ll rem = h % sum;

    ll right = upper_bound(pre.begin(), pre.end(), rem) - pre.begin();
    ll mx = -1;
    for (ll i = right; i < n; i++)
    {
        mx = max(mx, v[i]);
    }

    ll min_idx = LONG_LONG_MAX;
    for (ll i = 0; i < right; i++)
    {
        // if (v[i] < mx)
        // {
        ll diff = mx - v[i];
        ll idx = lower_bound(pre.begin() + i + 1, pre.end(), h - diff) - pre.begin();
        min_idx = min(min_idx, idx);
        // }
    }

    if (min_idx == LONG_LONG_MAX)
    {
        min_idx = 0;
    }

    cout << ans + min_idx << '\n';

    // cerr << pre << '\n';
    // cerr << h << ' ' << rem << ' ' << ans << '\n';
    // cerr << ans << '\n';
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