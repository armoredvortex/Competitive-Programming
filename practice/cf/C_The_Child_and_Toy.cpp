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

    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
        mp[i] = v[i].first;
    }

    sort(v.rbegin(), v.rend());
    set<pair<ll, ll>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.insert({u, v});
    }

    ll ans = 0;
    for (auto e : v)
    {
        for (auto it = edges.begin(); it != edges.end();)
        {
            auto k = *it;
            if (e.second == k.first)
            {
                ans += mp[k.second];
                it = edges.erase(it);
            }
            else if (e.second == k.second)
            {
                ans += mp[k.first];
                it = edges.erase(it);
            }
            else
            {
                it++;
            }
        }
    }
    cout << ans << '\n';
}