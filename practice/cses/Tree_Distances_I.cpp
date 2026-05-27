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

int dfs(int node, vector<vector<int>> &adj, int parent)
{
    int ans = 0;
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            ans = max(ans, 1 + dfs(e, adj, node));
        }
    }

    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> heights(n);
    heights[0] = dfs(0, adj, -1);

    dfs2()

    for (auto e : heights)
    {
        cout << e << ' ';
    }
}