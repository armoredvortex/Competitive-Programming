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

vector<ll> visited;
ll found = -1;

void dfs(ll i, vector<vector<ll>> &adj)
{
    visited[i] = 1;
    for (auto e : adj[i])
    {
        if (visited[e])
        {
            found = e;
            return;
        }
        else
        {
            dfs(e, adj);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.assign(n, 0);

    for (ll i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj);
        }
    }

    if (found == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        dfs2(found, adj);
    }

}