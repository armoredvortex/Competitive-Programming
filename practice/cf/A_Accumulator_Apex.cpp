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

    ll x, n;
    cin >> x >> n;

    vector<vector<ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll c;
        cin >> c;
        for (ll j = 0; j < c; j++)
        {
            ll a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    cerr << v << '\n';

    vector<vector<pair<ll, ll>>> costs(n);
    for (ll i = 0; i < n; i++)
    {
        ll cost = 0, gain = 0;
        for (auto e : v[i])
        {
            if (e < 0)
            {
                if (gain)
                {
                    costs[i].push_back({cost, gain});
                    cost = e;
                    gain = 0;
                }
                else
                {
                    cost += e;
                }
            }
            else
            {
                gain += e;
            }
        }
        if (gain)
        {
            costs[i].push_back({cost, gain});
        }
    }
    for (auto e : costs)
    {
        cerr << "=> ";
        for (auto f : e)
        {
            cerr << f << ' ';
        }
        cerr << '\n';
    }
}