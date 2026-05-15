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

void dfs(int node, int parent, vector<vector<int>> &adj, int depth, vector<int> &subtr, vector<int> &dpt)
{
    dpt[node] = depth;
    subtr[node] = 1;
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            dfs(e, node, adj, depth + 1, subtr, dpt);
            subtr[node] += subtr[e];
        }
    }
}

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
    {
        a.second.second < b.second.second;
    }

    return a.second.first > b.second.first;
}

void solve(int node, int parent, vector<vector<int>> &adj, int &ans, set<int> &envoy, int tourist)
{
    if (envoy.find(node) == envoy.end())
    {
        tourist++;
    }
    else
    {
        ans += tourist;
    }

    for (auto e : adj[node])
    {
        if (e != parent)
        {
            solve(e, node, adj, ans, envoy, tourist);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subtr(n), depth(n);
    dfs(0, -1, adj, 0, subtr, depth);
    // cerr << subtr << '\n'
    //      << depth;
    vector<pair<int, pair<int, int>>> vp(n);
    for (int i = 0; i < n; i++)
    {
        vp[i] = {i, {depth[i], subtr[i]}};
    }

    sort(vp.begin(), vp.end(), comp);

    set<int> envoy;
    for (int i = 0; i < k; i++)
    {
        envoy.insert(vp[i].first);
    }

    int ans = 0;
    solve(0, -1, adj, ans, envoy, 0);

    cout << ans;
    return 0;
}
