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

ll a, b;

void dfsb(ll node, ll parent, vector<vector<pair<ll, ll>>> &adj, ll x, set<ll> &bvals)
{
    for (auto e : adj[node])
    {
        if (e.first == parent)
            continue;

        bvals.insert(x ^ e.second);
        dfsb(e.first, node, adj, x ^ e.second, bvals);
    }
}

bool dfsa(ll node, ll parent, vector<vector<pair<ll, ll>>> &adj, ll x, set<ll> &bvals)
{
    if (bvals.find(x) != bvals.end())
        return true;

    for (auto e : adj[node])
    {
        if (e.first == parent)
            continue;

        ll x_new = x ^ e.second;
        if (e.first == b && x_new == 0)
        {
            return true;
        }
        else if (e.first != b)
        {
            if (dfsa(e.first, node, adj, x_new, bvals))
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    ll n;
    cin >> n >> a >> b;
    a--;
    b--;
    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    set<ll> bvals;
    dfsb(b, -1, adj, 0, bvals);

    // cerr << bvals << '\n';

    if (dfsa(a, -1, adj, 0, bvals))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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