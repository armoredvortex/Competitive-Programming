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

void calc_subtr(int node, int par, vector<vector<int>> &adj, vector<int> &subtr)
{

    if (adj[node].size() == 1)
    {
        subtr[node] = 1;
    }

    subtr[node] = 1;
    for (auto e : adj[node])
    {
        if (e != par)
        {
            calc_subtr(e, node, adj, subtr);
            subtr[node] += subtr[e];
        }
    }
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = {u, v};
    }

    if (n % 2)
    {
        cout << -1;
        return 0;
    }
    vector<int> subtr(n);
    calc_subtr(0, -1, adj, subtr);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int c1 = subtr[i];
        int c2 = n - c1;

        if (c2 != 0)
        {
            if (c1 % 2 == 0 && c2 % 2 == 0)
            {
                ans++;
            }
        }
    }
    cout << ans;
    // cerr << subtr;
}