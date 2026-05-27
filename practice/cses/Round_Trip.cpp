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

bool dfs(int node, vector<vector<int>> &adj, int parent, vector<int> &visited, vector<int> &path)
{
    visited[node] = 1;
    path.push_back(node);
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            if (visited[e] == 1)
            {
                path.push_back(e);
                return true;
            }
            if (dfs(e, adj, node, visited, path))
            {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<int> path;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        path = {};
        if (dfs(i, adj, -1, visited, path))
        {
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    // cerr << path;

    vector<int> ans;
    ans.push_back(path.back());
    for (int i = path.size() - 2; i >= 0; i--)
    {
        ans.push_back(path[i]);
        if (path[i] == ans[0])
        {
            break;
        }
    }

    cout << ans.size() << '\n';
    for (auto e : ans)
    {
        cout << e + 1 << ' ';
    }
}