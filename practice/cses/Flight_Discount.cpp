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
    vector<vector<pair<ll, ll>>> adj(n), rev_adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        rev_adj[v].push_back({u, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vll dist(n, LONG_LONG_MAX);
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        if (e.first > dist[e.second])
            continue;

        for (auto f : adj[e.second])
        {
            if (dist[e.second] + f.second < dist[f.first])
            {
                dist[f.first] = dist[e.second] + f.second;
                pq.push({dist[f.first], f.first});
            }
        }
    }

    ll ans = LONG_LONG_MAX;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq1;
    vll dist1(n, LONG_LONG_MAX);
    dist1[n - 1] = 0;
    pq1.push({0, n - 1});
    while (!pq1.empty())
    {
        auto e = pq1.top();
        pq1.pop();
        if (e.first > dist1[e.second])
            continue;

        for (auto f : rev_adj[e.second])
        {
            ans = min(ans, dist1[e.second] + f.second / 2 + dist[f.first]);
            if (dist1[e.second] + f.second < dist1[f.first])
            {
                dist1[f.first] = dist1[e.second] + f.second;
                pq1.push({dist1[f.first], f.first});
            }
        }
    }
    // cerr << dist << '\n';
    // cerr << dist1 << '\n';
    cout << ans << '\n';
}