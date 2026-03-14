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

    vll grp(n, 0);
    ll cg = 1;
    for (ll i = 0; i < n; i++)
    {
        if (grp[i])
        {
            continue;
        }
        grp[i] = cg;
        stack<ll> st;
        st.push(i);
        while (!st.empty())
        {
            auto e = st.top();
            st.pop();
            for (auto f : adj[e])
            {
                if (!grp[f])
                {
                    st.push(f);
                    grp[f] = cg;
                }
            }
        }
        cg++;
    }

    vll mem(n + 1, -1);
    for (ll i = 0; i < n; i++)
    {
        mem[grp[i]] = i + 1;
    }

    vector<pair<ll, ll>> ans;
    for (ll i = 1; i <= n; i++)
    {
        if (mem[i + 1] == -1)
        {
            break;
        }
        else
        {
            ans.push_back({mem[i], mem[i + 1]});
        }
    }

    cout << ans.size() << '\n';
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    // cerr << mem;
    // // cout << cg - 2 << '\n';
    // cerr << grp;
}