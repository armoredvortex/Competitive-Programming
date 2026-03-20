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

vll a;
vll sum, sumf;
vll visited;
vll height;
vll ans;
void dfs(vector<vector<ll>> &adj, ll node)
{
    visited[node] = 1;
    ll mx_ht = 0;
    sum[node] = a[node];
    for (auto e : adj[node])
    {
        if (!visited[e])
        {
            dfs(adj, e);
            sum[node] += sum[e];
            sumf[node] += sumf[e] + sum[e];
            mx_ht = max(mx_ht, height[e]);
        }
    }
    height[node] = mx_ht + 1;
}

ll calc(vector<vector<ll>> &adj, ll node)
{
    visited[node] = 1;

    ll ct = 0;
    for (auto e : adj[node])
    {
        if (!visited[e])
        {
            ct++;
        }
    }

    ans[node] = sumf[node];

    // cerr << node << ' ' << ct << '\n';

    if (ct == 0)
    {
        return 0;
    }
    else if (ct == 1)
    {
        ll k;
        for (auto e : adj[node])
        {
            if (!visited[e])
            {
                k = calc(adj, e);
            }
        }
        ans[node] += k;
        return k;
    }
    else
    {
        vll h;
        for (auto e : adj[node])
        {
            if (!visited[e])
            {
                h.push_back(height[e]);
            }
        }

        sort(h.begin(), h.end());
        ll k = 0;
        for (auto e : adj[node])
        {
            if (!visited[e])
            {
                ll child_val = calc(adj, e);

                if (height[e] == h.back())
                {
                    k = max({k, sum[e] * (h[h.size() - 2]), child_val});
                }
                else
                {
                    k = max({k, sum[e] * h.back(), child_val});
                }
            }
        }
        ans[node] += k;
        return k;
    }
    return 0;
}

void solve()
{
    ll n;
    cin >> n;

    height.assign(n, 0);
    sumf.assign(n, 0);
    a.assign(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sum.assign(n, 0);
    visited.assign(n, 0);
    dfs(adj, 0);

    // cerr << sum << '\n'
    //      << height << '\n'
    //      << sumf << "\n";

    ans.assign(n, 0);

    for (auto &e : visited)
    {
        e = 0;
    }

    calc(adj, 0);

    for (auto e : ans)
    {
        cout << e << ' ';
    }
    cout << '\n';
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