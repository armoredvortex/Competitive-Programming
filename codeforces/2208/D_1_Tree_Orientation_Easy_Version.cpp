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

bool dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    for (int i : adj[v])
    {
        // If an adjacent vertex is not visited,
        // then recur for that adjacent
        if (!visited[i])
        {
            if (dfs(i, adj, visited, v))
                return true;
        }

        // If an adjacent vertex is visited and is not
        // parent of current vertex,
        // then there exists a cycle in the graph.
        else if (i != parent)
            return true;
    }

    return false;
}

// Returns true if the graph contains a cycle, else false.
bool isCycle(vector<vector<int>> &adj)
{
    int V = adj.size();
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
        {
            if (dfs(u, adj, visited, -1))
                return true;
        }
    }

    return false;
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<char>> m(n, vector<char>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    for (ll i = 0; i < n; i++)
    {
        if (m[i][i] != '1')
        {
            cout << "No\n";
            return;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (m[i][j] == m[j][i] && m[i][j] == '1')
            {
                cout << "No\n";
                return;
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (m[i][j] == '0')
            {
                ll flag = 0;

                for (ll k = 0; k < n; k++)
                {
                    if (m[i][k] == '1' && m[k][j] == '1')
                    {
                        flag = 1;
                    }
                }

                if (flag)
                {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    vector<pair<ll, ll>> ans;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (m[i][j] == '1')
            {
                ll flag = 1;
                for (ll k = 0; k < n; k++)
                {
                    if (i == k || j == k)
                    {
                        continue;
                    }
                    if (m[i][k] == '1' && m[k][j] == '1')
                    {
                        flag = 0;
                    }
                }
                if (flag)
                {
                    ans.push_back({i, j});
                }
            }
        }
    }
    // for (auto e : ans)
    // {
    //     cerr << e << ' ';
    // }

    if (ans.size() != n - 1)
    {
        cout << "No\n";
        return;
    }
    // cout << "Yes\n";
    // for (auto e : ans)
    // {
    //     cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    // }

    vector<vector<int>> adj(n);
    for (auto e : ans)
    {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    if (isCycle(adj))
    {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for (auto e : ans)
    {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
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