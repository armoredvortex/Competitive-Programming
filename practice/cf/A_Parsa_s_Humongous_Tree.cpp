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

int calc(int node, int parent, vector<vector<int>> &adj, vector<int> &assigned, vector<pair<int, int>> &v)
{
    int s = 0;
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            if (abs(v[e].first - assigned[node]) > abs(v[e].second - assigned[node]))
            {
                assigned[e] = v[e].first;
                s += abs(v[e].first - assigned[node]);
            }
            else
            {
                assigned[e] = v[e].second;
                s += abs(v[e].second - assigned[node]);
            }
            s += calc(e, node, adj, assigned, v);
        }
    }

    return s;
}

void solve()
{
    ll n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> assigned(n, -1);
    assigned[0] = v[0].first;
    int ans = 0;
    int a1 = calc(0, -1, adj, assigned, v);

    vector<int> assigned2(n, -1);
    assigned[0] = v[0].second;
    int a2 = calc(0, -1, adj, assigned, v);

    cout << max(a1, a2) << "\n";
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