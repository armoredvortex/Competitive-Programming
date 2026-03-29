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

    ll n;
    cin >> n;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll ans = 0;
    for (ll k = 0; k < 64; k++)
    {
        vector<pair<ll, ll>> pre(n + 1, {0, 0});
        ll l1 = 0, l2 = 0;
        for (ll ii = 1; ii < n + 1; ii++)
        {
            ll i = ii - 1;
            if ((v[i] & (1ll << k)) == 0)
            {
                // cerr << l1 << '-' << pre[l1] << '\n';
                pre[ii].first = pre[l1].first;
                pre[ii].second = pre[l1].second + pre[l1].first * (ii - l1);
            }
            else
            {
                // cerr << 1 << ' ' << ii << '\n';
                pre[ii].first = pre[l2].first;
                pre[ii].first += (ii - l1);

                pre[ii].second = pre[l2].first * (ii - l2);
                pre[ii].second += (ii - l1) * (ii - l1 + 1) / 2;

                l2 = l1;
                l1 = ii;
            }
        }

        ll s = 0;
        for (auto e : pre)
        {
            s += e.second;
        }
        // cerr << s << '\n';
        // for (auto e : pre)
        // {
        //     cerr << e << ' ';
        // }

        ans += (1ll << k) * s;
    }
    cout << ans << '\n';
}