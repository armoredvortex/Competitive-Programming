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

int dfs(int node, vector<vector<int>> &adj, int parent, int &ans)
{
    vector<int> heights;
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            heights.push_back(dfs(e, adj, node, ans));
        }
    }
    sort(heights.begin(), heights.end());
    // cerr << node << ' ' << heights << '\n';
    if (heights.size() == 0)
    {
        return 1;
    }
    else if (heights.size() == 1)
    {
        ans = max(ans, 1 + heights[0]);
        return 1 + heights[0];
    }
    ans = max(ans, 1 + heights[heights.size() - 1] + heights[heights.size() - 2]);
    return 1 + heights.back();
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
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1;
    dfs(0, adj, -1, ans);

    cout << ans - 1 << '\n';
}