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

int dfs(int node, vector<vector<int>> &adj, vector<int> &dist)
{
    if (dist[node] >= 0)
    {
        return dist[node];
    }
    int mn = -1;
    for (auto e : adj[node])
    {
        if (dist[e] != -2)
        {
            auto f = dfs(e, adj, dist);
            if (f >= 0)
            {
                mn = max(mn, f);
            }
        }
    }
    if (mn == -1)
    {
        dist[node] = -2;
    }
    else
    {
        dist[node] = 1 + mn;
    }
    return dist[node];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }

    vector<int> dist(n, -1);
    dist[n - 1] = 0;
    int dt = dfs(0, adj, dist);
    if (dt < 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    auto it = max_element(dist.begin(), dist.end());
    int mx_node = it - dist.begin();
    cout << *it + 1 << '\n';
    while (dist[mx_node] != 0)
    {
        cout << mx_node + 1 << ' ';
        for (auto e : adj[mx_node])
        {
            if (dist[e] == dist[mx_node] - 1)
            {
                mx_node = e;
                break;
            }
        }
    }
    cout << mx_node + 1;
}