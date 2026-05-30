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

vector<vector<ll>> adj;
vll depth;
vll mdepth;

ll dfs(int node, int parent, int dpt)
{
    depth[node] = dpt;
    ll mx = dpt;
    for (auto e : adj[node])
    {
        if (e != parent)
        {
            mx = max(mx, dfs(e, node, dpt + 1));
        }
    }
    mdepth[node] = mx;
    return mx;
}

void solve()
{
    ll n;
    cin >> n;
    adj.assign(n, {});
    depth.assign(n, 0);
    mdepth.assign(n, 0);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    mdepth[0] = dfs(0, -1, 0);

    vector<ll> diff(n + 10);
    for (int i = 0; i < n; i++)
    {
        diff[depth[i]]++;
        diff[mdepth[i] + 1]--;
    }

    vector<ll> ans(n + 10, 0);
    ll s = 0;
    for (int i = 0; i < n + 5; i++)
    {
        s += diff[i];
        ans[i] = s;
    }

    cout << n - *max_element(ans.begin(), ans.end()) << '\n';
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