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

void dfs(ll node, ll parent, vector<vector<ll>> &adj, ll &ans, vector<ll> &height)
{
    vll v;
    if (adj[node].size() == 1)
    {
        height[node] = 1;
    }
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            dfs(e, node, adj, ans, height);
            height[node] = max(height[node], 1 + height[e]);
            v.push_back(height[e]);
        }
    }
    sort(v.begin(), v.end());
    ans++;
    if (v.size() >= 2)
    {
        ans += min(v.back(), v[v.size() - 2]);
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    for (int i = 1; i < n; i++)
    {
        ll a;
        cin >> a;
        a--;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    vll height(n, 0);
    ll ans = 0;
    dfs(0, -1, adj, ans, height);
    cout << ans << '\n';
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