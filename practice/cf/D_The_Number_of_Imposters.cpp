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

void solve()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        string s;
        cin >> u >> v >> s;
        u--;
        v--;
        if (s[0] == 'c')
        {
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
        }
        else
        {
            adj[v].push_back({u, 1});
            adj[u].push_back({v, 1});
        }
    }

    vll color(n, -1);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll ct1 = 0;
        ll ct2 = 0;
        if (color[i] != -1)
            continue;
        color[i] = 0;
        stack<ll> st;
        st.push(i);
        while (!st.empty())
        {
            auto e = st.top();
            st.pop();
            if (color[e] == 0)
            {
                ct1++;
            }
            else
            {
                ct2++;
            }
            for (auto f : adj[e])
            {
                if (color[f.first] != -1)
                {
                    if (f.second == 0 && (color[e] != color[f.first]))
                    {
                        cout << -1 << '\n';
                        return;
                    }
                    else if (f.second == 1 && (color[e] == color[f.first]))
                    {
                        cout << -1 << '\n';
                        return;
                    }
                }
                else
                {
                    if (f.second == 0)
                    {
                        color[f.first] = color[e];
                        st.push(f.first);
                    }
                    else
                    {
                        color[f.first] = color[e] ^ 1;
                        st.push(f.first);
                    }
                }
            }
        }
        ans += max(ct1, ct2);
    }
    cout << ans << '\n';
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