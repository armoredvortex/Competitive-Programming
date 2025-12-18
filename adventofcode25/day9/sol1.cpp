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
                cerr << area << " = " << e1 << ' ' << e2 << '\n';
                marea = area;
            }
        }
    }

    cerr << marea << '\n';
}