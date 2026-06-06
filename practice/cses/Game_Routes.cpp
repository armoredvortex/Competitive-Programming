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

const int mod = 1e9 + 7;
int dfs(int node, vector<vector<int>> &adj, vector<int>& ways, vector<int>& visited)
{
    if (visited[node])
    {
        return ways[node];
    }

    int w = 0;
    for (auto e : adj[node])
    {
        w = (w + dfs(e, adj, ways, visited)) % mod;
    }
    ways[node] = w;
    visited[node] = 1;
    return ways[node];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
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

    vector<int> ways(n, 0);
    vector<int> visited(n, 0);
    ways[n - 1] = 1;
    visited[n - 1] = 1;
    cout << dfs(0, adj, ways, visited);
}