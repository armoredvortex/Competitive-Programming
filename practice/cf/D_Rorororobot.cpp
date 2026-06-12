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

ll rangeMax(ll i, ll j, vector<vector<ll>> &rq)
{
    ll sz = log2(j - i + 1);
    return max(rq[i][sz], rq[j - (1ll << sz) + 1][sz]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;
    vll v(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> rq(m, vector<ll>(20));
    for (ll i = 0; i < m; i++)
    {
        rq[i][0] = v[i];
    }
    for (ll j = 1; j < 20; j++)
    {
        for (ll i = 0; i + (1 << j) - 1 < m; i++)
        {
            rq[i][j] = max(rq[i][j - 1], rq[i + (1 << j) - (1 << (j - 1))][j - 1]);
        }
    }
    // cerr << rq << '\n';

    ll q;
    cin >> q;
    while (q--)
    {
        ll xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;

        if (abs(xs - xf) % k || abs(yf - ys) % k)
        {
            cout << "NO\n";
        }
        else
        {
            ll minY = min(ys, yf) - 1;
            ll maxY = max(ys, yf) - 1;

            ll jumps = (n - xs) / k;
            ll xmax = xs + jumps * k;

            if (xmax > rangeMax(minY, maxY, rq))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
