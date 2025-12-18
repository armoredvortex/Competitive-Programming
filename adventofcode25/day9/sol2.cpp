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

    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        v[i] = {x, y};
    }

    ll x = 100000, y = 100000;
    vector<vector<ll>> map(x, vector<ll>(y, 0));

    for (ll i = 0; i < n - 1; i++)
    {
        auto e1 = v[i];
        auto e2 = v[i + 1];

        for (ll j = min(e1.first, e2.first); j <= max(e1.first, e2.first); j++)
        {
            for (ll k = min(e1.second, e2.second); k <= max(e1.second, e2.second); k++)
            {
                map[j][k] = 1;
                // cerr << j << ' ' << k << '\n';
            }
        }
    }
    for (ll j = min(v[0].first, v.back().first); j <= max(v[0].first, v.back().first); j++)
    {
        for (ll k = min(v[0].second, v.back().second); k <= max(v[0].second, v.back().second); k++)
        {
            map[j][k] = 1;
            // cerr << j << ' ' << k << '\n';
        }
    }

    for (ll i = 0; i < x; i++)
    {
        vector<ll> pos;
        for (ll j = 0; j < y; j++)
        {
            if (map[i][j] == 1)
            {
                pos.push_back(j);
            }
        }

        cerr << pos << '\n';
        if (pos.size() < 2)
        {
            continue;
        }
        for (ll j = 0; j < pos.size() - 1; j++)
        {
            for (ll k = pos[j]; k < pos[j + 1]; k++)
            {
                map[i][k] = 1;
            }
        }
    }

    ll marea = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            auto e1 = v[i];
            auto e2 = v[j];

            // cerr << e1 << ' ' << e2 << '\n';
            ll area = abs((e1.first - e2.first + 1) * (e1.second - e2.second + 1));
            if (area > marea)
            {
                ll flag = 0;
                for (ll i1 = min(e1.first, e2.first); i1 <= max(e1.first, e1.second); i1++)
                {
                    for (ll j1 = min(e1.second, e2.second); j1 < max(e1.second, e2.second); j1++)

                    {
                        if (map[i1][j1] == 0)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (!flag)
                {
                    marea = area;
                }
            }
        }
    }

    cerr << marea << '\n';

    cerr << map << '\n';
}