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

void dfs(ll node, ll parent, vector<vector<ll>> &adj, vector<vector<ll>> &dp)
{
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            dfs(e, node, adj, dp);
        }
    }

    if (adj[node].size() == 1)
    {
        dp[node][0] = 1;
        dp[node][1] = 1;
        return;
    }

    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<ll>> dp(n, vector<ll>(2));
    dfs(0, -1, adj, dp);
}