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

vector<vector<ll>> g(100010);
vector<ll> visited(100010);

double dfs(ll node)
{
    // cerr << node << '\n';
    visited[node] = 1;
    double sum = 0;
    for (auto e : g[node])
    {
        if (!visited[e])
        {
            sum += dfs(e);
        }
    }
    if (node == 1)
    {
        return sum / (g[node].size());
    }
    if (g[node].size() == 1)
    {
        // cerr << node << " : " << 1 << '\n';
        return 1;
    }
    // cerr << node << " : " << (1.0 + sum / (g[node].size() - 1)) << '\n';

    return (1.0 + sum / (g[node].size() - 1));
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    if (n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // cerr << g << '\n';

    cout << fixed << setprecision(10);
    cout << dfs(1) << '\n';
}