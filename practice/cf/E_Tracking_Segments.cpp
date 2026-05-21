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
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> seg(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> seg[i].first >> seg[i].second;
    }

    ll q;
    cin >> q;
    vector<ll> queries(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> queries[i];
        queries[i]--;
    }

    ll left = 1, right = q;
    ll mid, ans = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        vll v(n, 0);
        for (ll i = 0; i < mid; i++)
        {
            v[queries[i]] = 1;
        }
        vll pre(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + v[i - 1];
        }
        ll flag = 0;
        for (auto e : seg)
        {
            ll sz = e.second - e.first + 1;
            ll ct = pre[e.second] - pre[e.first - 1];
            if (ct > sz / 2)
            {
                // cerr << "FOUND " << e.first << '-' << e.second << '\n';
                flag = 1;
                break;
            }
        }
        // cerr << v << '\n'
        //      << pre << '\n'
        //      << mid << "\n\n";

        if (flag)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
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