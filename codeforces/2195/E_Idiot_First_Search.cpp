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

ll MOD = 1000000007;
ll fillvals(vector<ll> &vals, vector<ll> &visited, vector<vector<ll>> &adj, ll node)
{
    if (vals[node] != -1)
    {
        return vals[node];
    }

    visited[node] = 1;
    vals[node] = 4;
    for (ll i = 0; i < adj[node].size(); i++)
    {
        vals[node] += (fillvals(vals, visited, adj, adj[node][i])) % MOD;
    }

    vals[node] %= MOD;
    return vals[node];
}

void ans(vector<vector<ll>> &adj, vector<ll> &ansv, ll prev, ll node, vector<ll> &vals)
{
    ansv[node] = vals[node] + prev + 1;
    ansv[node] %= MOD;
    for (auto e : adj[node])
    {
        ans(adj, ansv, ansv[node], e, vals);
    }
    return;
}

void solve()
{
    ll n;
    cin >> n;

    vector<vector<ll>> adj(n + 1);
    adj[0].push_back(1);
    for (ll i = 1; i < n + 1; i++)
    {
        ll u, v;
        cin >> u >> v;

        if (u == 0)
        {
            continue;
        }

        adj[i].push_back(v);
        adj[i].push_back(u);
    }

    // cerr << adj << '\n';

    vector<ll> vals(n + 1, -1);
    vector<ll> visited(n + 1, 0);

    for (ll i = 0; i < n + 1; i++)
    {
        if (adj[i].size() == 0)
        {
            vals[i] = 0;
        }
    }

    fillvals(vals, visited, adj, 0);

    // for (auto e : vals)
    // {
    //     cerr << e << ' ';
    // }

    vector<ll> ansv(n + 1, 0);
    ans(adj, ansv, 0, 1, vals);
    for (ll i = 1; i < n + 1; i++)
    {
        auto e = ansv[i];
        cout << e << ' ';
    }
    cout << '\n';
    return;
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