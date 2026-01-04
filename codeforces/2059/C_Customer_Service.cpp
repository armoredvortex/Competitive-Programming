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

    vector<vector<ll>> v(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<ll>> post(n, vector<ll>(n + 1, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            post[i][n - j - 1] = v[i][n - j - 1] + post[i][n - j];
        }
    }

    // cerr << post;
    // ll ans = 0;
    // ll cto = n;
    vector<ll> ct(n + 1, 0);
    for (ll j = n; j > 0; j--)
    {
        for (ll i = 0; i < n; i++)
        {
            if (post[i][j] == n - j)
            {
                ct[j]++;
            }
        }
    }

    // cerr << ct << '\n';

    for (ll i = n - 1; i >= 0; i--)
    {
        if (ct[i] >= ct[i + 1])
        {
            ct[i] = ct[i + 1] - 1;
        }

        if (ct[i] == 0)
        {
            cout << n - i << '\n';
            return;
        }
    }

    // cout << ans << '\n';
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