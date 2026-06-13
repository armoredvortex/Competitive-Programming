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

    vector<vector<ll>> minst(n / 2 + 1, vector<ll>(n + 1, LONG_LONG_MAX));
    vector<vector<ll>> mxst(n / 2 + 1, vector<ll>(n + 1, LONG_LONG_MIN));

    for (ll i = 0; i < n; i++)
    {
        ll minv = v[i];
        ll maxv = v[i];

        vll seen(n + 1, 0);

        for (ll j = i; j < n; j++)
        {
            if (seen[v[j]])
                break;

            seen[v[j]] = 1;
            minv = min(minv, v[j]);
            maxv = max(maxv, v[j]);

            ll len = j - i + 1;

            if (maxv - minv == len - 1)
            {
                if (len <= n / 2)
                {
                    minst[len][minv] = min(minst[len][minv], i);
                    mxst[len][minv] = max(mxst[len][minv], i);
                }
            }
        }
    }

    ll ans = 0;
    for (ll k = n / 2; k >= 1; k--)
    {
        for (ll i = 1; i <= n - 2 * k + 1; i++)
        {
            ll tgt = i + k;
            if (minst[k][i] != LONG_LONG_MAX && minst[k][tgt] != LONG_LONG_MAX)
            {
                if (minst[k][i] + k <= mxst[k][tgt] ||
                    minst[k][tgt] + k <= mxst[k][i])
                {
                    ans = k;
                    break;
                }
            }
        }
        if (ans == k)
        {
            break;
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