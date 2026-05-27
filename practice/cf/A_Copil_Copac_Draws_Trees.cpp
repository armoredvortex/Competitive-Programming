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

void dfs(int node, int parent, vector<vector<int>> &adj, map<pair<int, int>, int> &edges, vector<int> &dp, vector<int> &id)
{
    for (auto e : adj[node])
    {
        if (e == parent)
            continue;

        if (edges[{node, e}] >= id[node])
        {
            dp[e] = dp[node];
            id[e] = edges[{node, e}];
        }
        else
        {
            dp[e] = dp[e] + 1;
            id[e] = edges[{node, e}];
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[{u, v}] = i;
        edges[{v, u}] = i;
    }

    vector<int> dp(n), id(n);

    dp[0] = 1;
    id[0] = 1;

    dfs(0, -1, adj, edges, dp, id);

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--)
        solve();
}