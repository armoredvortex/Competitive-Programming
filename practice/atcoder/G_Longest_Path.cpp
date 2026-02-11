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

int dp[100000 + 10];

ll dfs(ll i, vector<vector<ll>> &adj);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    vector<ll> inDeg(n, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    for (ll i = 0; i < 100010; i++)
    {
        dp[i] = -1;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (inDeg[i] == 0)
        {
            ans = max(ans, dfs(i, adj));
        }
    }

    cout << ans - 1 << '\n';
    return 0;
}

ll dfs(ll i, vector<vector<ll>> &adj)
{
    if (dp[i] == -1)
    {
        ll mx = 0;
        for (auto e : adj[i])
        {
            mx = max(mx, dfs(e, adj));
        }
        return dp[i] = 1 + mx;
    }
    else
    {
        return dp[i];
    }
}