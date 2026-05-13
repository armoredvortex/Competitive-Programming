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

    const ll BITS = 32;
    vector<vector<ll>> nxt_one(BITS, vector<ll>(n));
    for (ll i = 0; i < BITS; i++)
    {
        if (v.back() & (1 << i))
        {
            nxt_one[i][n - 1] = n - 1;
        }
        else
        {
            nxt_one[i][n - 1] = LONG_LONG_MIN;
        }
        for (ll j = n - 2; j >= 0; j--)
        {
            if (v[j] & (1 << i))
            {
                if (nxt_one[i][j + 1] == LONG_LONG_MIN)
                {
                    nxt_one[i][j] = j;
                }
                else
                {
                    nxt_one[i][j] = nxt_one[i][j + 1];
                }
            }
            else
            {
                nxt_one[i][j] = LONG_LONG_MIN;
            }
        }
    }

    // cerr << nxt_one;
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, k;
        cin >> l >> k;
        l--;
        ll mx = n - 1;
        ll ans = LONG_LONG_MIN;
        for (ll i = BITS - 1; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                mx = min(mx, nxt_one[i][l]);
            }
            else
            {
                ans = max(ans, min(mx, nxt_one[i][l]));
            }
            // cerr << mx << '-' << ans << '\n';
        }
        ans = max(ans, mx);
        cout << max(-1ll, ans + 1) << ' ';
    }
    cout << '\n';
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