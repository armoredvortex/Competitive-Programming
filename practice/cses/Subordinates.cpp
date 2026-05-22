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

void dfs(int node, vector<vector<int>> &adj, vector<int> &result)
{
    result[node] = 1;
    if (adj[node].size() == 0)
    {
        return;
    }
    else
    {
        for (auto e : adj[node])
        {
            dfs(e, adj, result);
            result[node] += result[e];
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<int> v(n);
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> v[i];
        v[i]--;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        adj[v[i]].push_back(i + 1);
    }

    vector<int> result(n, 0);
    dfs(0, adj, result);

    for (auto e : result)
    {
        cout << e - 1 << ' ';
    }
}