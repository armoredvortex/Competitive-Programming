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

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll visited(n, 0);
    queue<pair<ll, ll>> q;
    vll prev(n, -1);
    visited[0] = 1;
    q.push({0, -1});
    while (!q.empty())
    {
        auto e = q.front();
        q.pop();
        prev[e.first] = e.second;
        if (e.first == n - 1)
        {
            break;
        }
        for (auto f : adj[e.first])
        {
            if (!visited[f])
            {
                q.push({f, e.first});
                visited[f] = 1;
            }
        }
    }
    // cerr << visited;
    // cerr << prev;
    if (prev.back() != -1)
    {
        vll ans;
        ll pt = n - 1;
        while (pt != -1)
        {
            ans.push_back(pt);
            pt = prev[pt];
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto e : ans)
        {
            cout << e + 1 << ' ';
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    cout << '\n';
}