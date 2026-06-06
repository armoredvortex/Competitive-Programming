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

    int n, m;
    cin >> n >> m;
    vector<map<int, int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        if (adj[u].find(v) == adj[u].end())
        {
            adj[u][v] = w;
        }
        else
        {
            adj[u][v] = min(adj[u][v], w);
        }
    }

    vector<long long> dist(n, LONG_LONG_MAX / 2);
    dist[0] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, 0});

    while (pq.size())
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

    for (auto e : dist)
    {
        cout << e << ' ';
    }
}