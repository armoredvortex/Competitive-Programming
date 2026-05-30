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

ll getans(ll l, ll r, vector<vector<ll>> &rq)
{
    ll sz = r - l;
    ll j = log2(sz);
    return gcd(rq[l][j], rq[r - (1 << j)][j]);
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vll v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n == 1)
    {
        for (ll i = 0; i < q; i++)
        {
            ll l, r;
            cin >> l >> r;
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }

    vll d(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        d[i] = abs(v[i + 1] - v[i]);
    }

    vector<vector<ll>> rq(n - 1, vector<ll>(log2(n - 1) + 1, 0));

    for (ll i = 0; i < n - 1; i++)
    {
        rq[i][0] = d[i];
    }

    for (ll j = 1; j <= log2(n - 1); j++)
    {
        for (ll i = 0; i + (1 << j) < n; i++)
        {
            rq[i][j] = gcd(rq[i][j - 1], rq[i + (1 << j) - (1 << (j - 1))][j - 1]);
        }
    }
    // cerr << d << '\n';
    // cerr << rq;

    for (ll i = 0; i < q; i++)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r)
        {
            cout << 0 << ' ';
            continue;
        }

        cout << getans(l, r, rq) << ' ';
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