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

    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> v(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            for (ll k = j + 1; k < n; k++)
            {

                ll req = x - v[i].first - v[j].first - v[k].first;
                pair<ll, ll> p = {req, -1};
                auto it = lower_bound(v.begin() + j + 1, v.end(), p);

                if (it != v.end() && (*it).first == req)
                {
                    cout << v[i].second + 1 << ' ' << v[j].second + 1 << ' ' << v[k].second + 1 << ' ' << (*it).second + 1;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}