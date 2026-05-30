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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> heights(n, vector<ll>(m)), cap(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> heights[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            cap[i][j] = c - '0';
        }
    }

    ll snowh = 0, non_snowh = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (cap[i][j])
            {
                snowh += heights[i][j];
            }
            else
            {
                non_snowh += heights[i][j];
            }
        }
    }

    ll diff = abs(snowh - non_snowh);

    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < m + 1; j++)
        {
            pre[i][j] = cap[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    vll primes;
    for (ll i = 0; i + k < n + 1; i++)
    {
        for (ll j = 0; j + k < m + 1; j++)
        {
            ll ct = pre[i + k][j + k] - pre[i][j + k] - pre[i + k][j] + pre[i][j];
            ll ct2 = k * k - ct;
            ll capdiff = abs(ct - ct2);
            primes.push_back(capdiff);
        }
    }

    ll g = 0;
    for (auto e : primes)
    {
        g = gcd(g, e);
    }

    if (diff == 0 || diff == g || (g != 0 && diff % g == 0))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    // cerr << diff << '\n';
    // cerr << primes << '\n';
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