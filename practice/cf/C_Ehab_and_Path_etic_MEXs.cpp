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

    vector<pair<ll, ll>> edges(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[i].first = u;
        edges[i].second = v;
    }

    vector<vector<ll>> adj(n);
    for (auto e : edges)
    {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    ll idx = -1;
    for (ll i = 0; i < n; i++)
    {
        if (adj[i].size() >= 3)
        {
            idx = i;
        }
    }

    ll ct1 = n - 2, ct2 = 0;
    for (auto e : edges)
    {
        if (e.first == idx || e.second == idx)
        {
            cout << ct2 << '\n';
            ct2++;
        }
        else
        {
            cout << ct1 << '\n';
            ct1--;
        }
    }

    return 0;
}