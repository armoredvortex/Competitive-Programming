#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;

ll dfs(ll node, vector<vector<ll>> &adj, vector<ll> &visited)
{
    ll sum = 0;
    for (auto e : adj[node])
    {
        if (!visited[e])
        {
            visited[e] = 1;
            sum += dfs(e, adj, visited);
        }
    }
    return 1 + sum;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[v].push_back(u);
    }

    for (ll i = 0; i < n; i++)
    {
        vector<ll> visited(n, 0);
        visited[i] = 1;
        if (dfs(i, adj, visited) == n)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;

    return 0;
}